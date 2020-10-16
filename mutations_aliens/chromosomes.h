#ifndef CHROMOSOMES_H
#define CHROMOSOMES_H
#include <QString>

class Chromosomes
{
private:
    QString chrom1;
    QString chrom2;
public:
    Chromosomes(QString c1, QString c2);
    QString getChrom1() const;
    void setChrom1(const QString &value);
    QString getChrom2() const;
    void setChrom2(const QString &value);
};

#endif // CHROMOSOMES_H
