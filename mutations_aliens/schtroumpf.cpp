#include "schtroumpf.h"
#include "random.h"
#include "QTextStream"



gene_couleur Schtroumpf::getChrom1() const
{
    return chrom1;
}

void Schtroumpf::setChrom1(const gene_couleur &value)
{
    chrom1 = value;
}

gene_couleur Schtroumpf::getChrom2() const
{
    return chrom2;
}

void Schtroumpf::setChrom2(const gene_couleur &value)
{
    chrom2 = value;
}

double Schtroumpf::getFitness() const
{
    return fitness;
}



QString Schtroumpf::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"( "<<chrom1<<" , "<<chrom2<<" ) = "<<couleur<<" -> fitness : "<<fitness<<endl;
    return res;
}

Schtroumpf::Schtroumpf(gene_couleur c1, gene_couleur c2, couleur_ind c, double f) : chrom1(c1) , chrom2(c2), c(couleur), fitness(f)
{
    
}



void Schtroumpf::mutate()
{

}
