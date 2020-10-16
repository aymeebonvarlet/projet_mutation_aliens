#include "schtroumpf.h"

void Schtroumpf::setChrom1(const QString &value)
{
    chrom1 = value;
}

void Schtroumpf::setChrom2(const QString &value)
{
    chrom2 = value;
}

Schtroumpf::Schtroumpf(QString c1, QString c2, double f) : chrom1(c1) , chrom2(c2), fitness(f)
{
    
}

bool Schtroumpf::schtroumf(Schtroumpf g)
{
    if (g.chrom1=="s" && g.chrom2=="s"){
        return true;
    }
    else {
        return false; 
    }
    
}

void Schtroumpf::mutate()
{
    
}
