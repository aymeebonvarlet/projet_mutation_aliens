#include "chromosomes.h"
#include <QTextStream>


Chromosomes::Chromosomes(QString c1, QString c2): chrom1(c1), chrom2(c2)
{

}

QString Chromosomes::getChrom1() const
{
    return chrom1;
}

void Chromosomes::setChrom1(const QString &value)
{
    chrom1 = value;
}

QString Chromosomes::getChrom2() const
{
    return chrom2;
}

void Chromosomes::setChrom2(const QString &value)
{
    chrom2 = value;
}




