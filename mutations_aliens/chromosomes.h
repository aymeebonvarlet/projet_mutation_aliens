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
    QString get_chrom1();
};

#endif // CHROMOSOMES_H
