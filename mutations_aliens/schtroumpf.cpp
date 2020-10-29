#include "schtroumpf.h"
#include "random.h"
#include "QTextStream"
#include "parameters.h"



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
    double x = rand()/RAND_MAX;
    if (x<Parameters::mutationRate_schtroumpf){
        int min_borne = 1;
        int max_borne = 4;
        int x = rand()%(max_borne-min_borne+1)+1;
        if (x%2==0){

        }
    }
}

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

double Schtroumpf::def_fitness_schtroumpf(couleur_ind c)
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
