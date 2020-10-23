#include "schtroumpf.h"
#include "random.h"
#include "QTextStream"


couleur_ind Schtroumpf::couleur_individual(gene_couleur c1, gene_couleur c2)
{
    if (c1==R or c2 == R){
        return Rouge;
    }
    else {
        if (c1==v){
            if (c2==v){
                return Vert;
            }
            else{
                return Jaune;
            }
        }
        else{
            if (c2==b){
                return Bleu;
            }
            else{
                return Jaune;
            }
        }
    }
}

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


double Schtroumpf::definition_fitness(couleur_ind c)
{
    if (c==Rouge){
        return 1;
    }
    if (c==Vert){
        return 5;
    }
    if (c==Jaune){
        return 12;
    }
    if (c==Bleu){
        return 20;
    }
}

QString Schtroumpf::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"( "<<chrom1<<" , "<<chrom2<<" ) = "<<couleur<<" -> fitness : "<<fitness<<endl;
    return res;
}

Schtroumpf::Schtroumpf(gene_couleur c1, gene_couleur c2, double f, couleur_ind c) : chrom1(c1) , chrom2(c2), fitness(f), c(couleur)
{
    
}



void Schtroumpf::mutate()
{

}
