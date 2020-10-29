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

couleur_ind Schtroumpf::getCouleur() const
{
    return couleur;
}

void Schtroumpf::setCouleur(const couleur_ind &value)
{
    couleur = value;
}

void Schtroumpf::setFitness(double value)
{
    fitness = value;
}

Schtroumpf::Schtroumpf(gene_couleur c1, gene_couleur c2, couleur_ind c, double f) : chrom1(c1) , chrom2(c2), c(couleur), fitness(f)
{
    
}




void Schtroumpf::mutate(Schtroumpf s)
{
    double x = rand()/RAND_MAX;
    if (x<Parameters::mutationRate_schtroumpf){
        //choix du chromosome qui mute
        int min_borne = 1;
        int max_borne = 2;
        int num_chrom = rand()%(max_borne-min_borne+1)+1;
        //choix de la mutation, si 2,4 = R , 1=b , 3=v
        min_borne = 1;
        max_borne = 4;
        int x = rand()%(max_borne-min_borne+1)+1;
        gene_couleur new_g;
        if (x%2==0){
            new_g = R;
        }
        else if (x==3){
            new_g= v;
        }
        else {
            new_g = b;
        }
        //on modifie le gène
        if (num_chrom==1){
            s.setChrom1(new_g);
        }
        else{
            s.setChrom2(new_g);
        }
        //et du coup, la couleur et le fitness
        couleur_ind c = couleur_individual(s.chrom1, s.chrom2);
        s.setCouleur(c);
        double f = def_fitness_schtroumpf(c);
        s.setFitness(f);
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
