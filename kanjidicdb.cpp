#include "kanjidicdb.h"
#include <QMessageBox>
#include <iostream>
#include "kanji.h"

KanjidicDB::KanjidicDB()
{
    //empty list returned when no match found
    kanjisByStroke[0] = new QSet<Kanji *>();
}

bool KanjidicDB::read(QIODevice *device)
{
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (!domDocument.setContent(device, true, &errorStr, &errorLine,
                                &errorColumn))
    {
        QMessageBox::information(window(), tr("Kanjidic"),
                                 tr("Parse error at line %1, column %2:\n%3")
                                 .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr));
        return false;
    }

    QDomElement root = domDocument.documentElement();
    if (root.tagName() != "kanjidic2")
    {
        QMessageBox::information(window(), tr("Kanjidic"),
                                 tr("The file is not a Kanjidic2 file."));
        return false;
    }

    // kanjidic has 1 header node and pairs of comment and character nodes
    long count = ( root.childNodes().count() - 1 ) / 2;
    //std::cout << count << std::endl;

    QDomElement child = root.firstChildElement("character");
    while (!child.isNull())
    {
        ++count;
        parseCharacterElement(child);
        child = child.nextSiblingElement("character");
    }

    return true;
}

void KanjidicDB::parseCharacterElement(const QDomElement &element){
    QString title = element.firstChildElement("literal").text();
    Q_ASSERT(title.length() > 0);
    Kanji *k = new Kanji(title);

    bool ok;

    QDomElement codepoint= element.firstChildElement("codepoint");
    QDomElement child = codepoint.firstChildElement("cp_value");
    while (!child.isNull())
    {
        if(QString::compare(child.attribute("cp_type", ""), "ucs") == 0)
        {
            int unicode = child.text().toInt(&ok, 16);
            k->setUnicode(unicode);
            Q_ASSERT(unicode > 0);
            kanjis[unicode] = k;
        } else if(QString::compare(child.attribute("cp_type", ""), "jis208") == 0)
        {
            QString text = child.text();
            k->setJis208(text);
            kanjisJIS208[text] = k;
        }
        else if(QString::compare(child.attribute("cp_type", ""), "jis212") == 0)
        {
            QString text = child.text();
            k->setJis212(text);
            kanjisJIS212[text] = k;
        }
        else if(QString::compare(child.attribute("cp_type", ""), "jis213") == 0)
        {
            QString text = child.text();
            k->setJis213(text);
            kanjisJIS213[text] = k;
        }
        child = child.nextSiblingElement("cp_value");
    }

    QDomElement radical = element.firstChildElement("radical");
    child = radical.firstChildElement("rad_value");
    while (!child.isNull())
    {
        if(QString::compare(child.attribute("rad_type", ""), "classical") == 0)
        {
            int cRad = child.text().toInt(&ok, 10);
            k->setClassicalRadical(cRad);
            QSet<Kanji *> *set = kanjisByRadical[cRad];
            if(set == 0)
            {
                set = new QSet<Kanji *>();
                kanjisByRadical[cRad] = set;
            }
            set->insert(k);
        }
        else if(QString::compare(child.attribute("rad_type", ""), "nelson_c") == 0)
            k->setNelsonRadical(child.text().toInt(&ok, 10));
        child = child.nextSiblingElement("rad_value");
    }

    //parsing misc element of character
    QDomElement misc = element.firstChildElement("misc");

    child = misc.firstChildElement("grade");
    if(!child.isNull())
    {
        int grade = child.text().toInt(&ok, 10);
        k->setGrade(grade);
        QSet<Kanji *> *set = kanjisByGrade[grade];
        if(set == 0)
        {
            set = new QSet<Kanji *>();
            kanjisByGrade[grade] = set;
        }
        set->insert(k);
    }

    child = misc.firstChildElement("variant");
    while (!child.isNull())
    {
        if(QString::compare(child.attribute("var_type", ""), "ucs") == 0)
            k->addUnicodeVariant(child.text().toInt(&ok, 16));
        else if(QString::compare(child.attribute("var_type", ""), "jis208") == 0)
            k->addJis208Variant(child.text());
        else if(QString::compare(child.attribute("var_type", ""), "jis212") == 0)
            k->addJis212Variant(child.text());
        else if(QString::compare(child.attribute("var_type", ""), "jis213") == 0)
            k->addJis213Variant(child.text());
        child = child.nextSiblingElement("variant");
    }

    child = misc.firstChildElement("freq");
    if(!child.isNull())
        k->setFrequency(child.text().toInt(&ok, 10));

    child = misc.firstChildElement("rad_name");
    while (!child.isNull())
    {
        k->addNameAsRadical(child.text());
        child = child.nextSiblingElement("rad_name");
    }

    child = misc.firstChildElement("jlpt");
    if(!child.isNull())
    {
        int jlpt = child.text().toInt(&ok, 10);
        k->setJLPT(jlpt);
        QSet<Kanji *> *set = kanjisByJLPT[jlpt];
        if(set == 0)
        {
            set = new QSet<Kanji *>();
            kanjisByJLPT[jlpt] = set;
        }
        set->insert(k);
    }

    int strokeCount = misc.firstChildElement("stroke_count").text().toInt(&ok, 10);

    k->setStrokeCount(strokeCount);
    QSet<Kanji *> *set = kanjisByStroke[strokeCount];
    if(set == 0)
    {
        set = new QSet<Kanji *>();
        kanjisByStroke[strokeCount] = set;
    }
    set->insert(k);

    // end of misc parsing

    // parsing reading_meaning element of character
    QDomElement reamea = element.firstChildElement("reading_meaning");
    if(reamea.isNull())
        return;
    QDomElement rmgroup = reamea.firstChildElement("rmgroup");
    while(!rmgroup.isNull())
    {
        child = rmgroup.firstChildElement("reading");
        while (!child.isNull())
        {
            if(QString::compare(child.attribute("r_type", ""), "ja_on") == 0)
                k->addOnReading(child.text());
            else if(QString::compare(child.attribute("r_type", ""), "ja_kun") == 0)
                 k->addKunReading(child.text());
            child = child.nextSiblingElement("reading");
        }
        child = rmgroup.firstChildElement("meaning");
        while (!child.isNull())
        {
            if(!child.hasAttribute("m_lang") || QString::compare(child.attribute("m_lang", ""), "en") == 0)
                k->addEnglishMeaning(child.text());
            else if(QString::compare(child.attribute("m_lang", ""), "fr") == 0)
                k->addFrenchMeaning(child.text());
            child = child.nextSiblingElement("meaning");
        }
        rmgroup = rmgroup.nextSiblingElement("rmgroup");
    }
    // nanori readings
    child = reamea.firstChildElement("nanori");
    while (!child.isNull())
    {
        k->addNanoriReading(child.text());
        child = child.nextSiblingElement("nanori");
    }
}

void KanjidicDB::searchByUnicode(int unicode, QSet<Kanji *> &set)
{
    if(unicode > 0 && kanjis.contains(unicode))
        set.insert(kanjis[unicode]);
}

void KanjidicDB::searchByJIS208(const QString &s, QSet<Kanji *> &set)
{
    if(s.size() > 0 && kanjisJIS208.contains(s))
        set.insert(kanjisJIS208[s]);
}

void KanjidicDB::searchByJIS212(const QString &s, QSet<Kanji *> &set)
{
    if(s.size() > 0 && kanjisJIS212.contains(s))
        set.insert(kanjisJIS212[s]);
}

void KanjidicDB::searchByJIS213(const QString &s, QSet<Kanji *> &set)
{
    if(s.size() > 0 && kanjisJIS213.contains(s))
        set.insert(kanjisJIS213[s]);
}

void KanjidicDB::search(char strokeCount, char jlpt, char grade, char radical, QSet<Kanji *> &set)
{
    bool united = false;
    if(strokeCount > 0)
    {
        if(kanjisByStroke[strokeCount] != 0)
        {
            set.unite(*kanjisByStroke[strokeCount]);
            united = true;
        }
    }
    if(jlpt > 0)
    {
        if(kanjisByJLPT[jlpt] != 0)
        {
            if(!united)
            {
                set.unite(*kanjisByJLPT[jlpt]);
                united = true;
            } else
            {
                set.intersect(*kanjisByJLPT[jlpt]);
            }
        }
    }
    if(grade > 0)
    {
        if(kanjisByGrade[grade] != 0)
        {
            if(!united)
            {
                set.unite(*kanjisByGrade[grade]);
                united = true;
            } else
            {
                set.intersect(*kanjisByGrade[grade]);
            }
        }
    }
    if(radical > 0)
    {
        if(kanjisByRadical[radical] != 0)
        {
            if(!united)
            {
                set.unite(*kanjisByRadical[radical]);
                united = true;
            } else
            {
                set.intersect(*kanjisByRadical[radical]);
            }
        }
    }
}
