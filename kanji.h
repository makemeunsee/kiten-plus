#ifndef KANJI_H
#define KANJI_H

#include <QString>
#include <QList>

class Kanji
{
public:
    Kanji(const QString &);
    const QString getLiteral();
    int getUnicode();
    const QString getJis208();
    const QString getJis212();
    const QString getJis213();
    char getClassicalRadical();
    char getNelsonRadical();
    char getGrade();
    char getStrokeCount();
    const QList<int> * getUnicodeVariants();
    const QList<QString> * getJis208Variants();
    const QList<QString> * getJis212Variants();
    const QList<QString> * getJis213Variants();
    // if 0 -> not one of the 2500 most frequent
    short getFrequency();
    const QList<QString> *getNamesAsRadical();
    char getJLPT();
    const QList<QString> *getOnReadings();
    const QList<QString> *getKunReadings();
    const QList<QString> *getNanoriReadings();
    const QList<QString> *getFrenchMeanings();
    const QList<QString> *getEnglishMeanings();

    void setUnicode(int);
    void setJis208(const QString &);
    void setJis212(const QString &);
    void setJis213(const QString &);
    void setClassicalRadical(char);
    void setNelsonRadical(char);
    void setGrade(char);
    void setStrokeCount(char);
    void addUnicodeVariant(int);
    void addJis208Variant(const QString &);
    void addJis212Variant(const QString &);
    void addJis213Variant(const QString &);
    void setFrequency(short);
    void addNameAsRadical(const QString &);
    void setJLPT(char);
    void addOnReading(const QString &);
    void addKunReading(const QString &);
    void addNanoriReading(const QString &);
    void addFrenchMeaning(const QString &);
    void addEnglishMeaning(const QString &);

private:
    QString literal;
    int unicode;
    QString jis208;
    QString jis212;
    QString jis213;
    char classicalRadical;
    char nelsonRadical;
    char grade;
    char strokeCount;
    QList<int> unicodeVariants;
    QList<QString> jis208Variants;
    QList<QString> jis212Variants;
    QList<QString> jis213Variants;
    short frequency;
    // names in hiragana if this kanji is a radical and has a name
    QList<QString> radicalNames;
    char jlpt;
    QList<QString> onReadings;
    QList<QString> kunReadings;
    // readings for names only
    QList<QString> nanoriReadings;
    QList<QString> englishMeanings;
    QList<QString> frenchMeanings;
    // other languages to come???
};

#endif // KANJI_H
