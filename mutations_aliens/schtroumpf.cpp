#include "schtroumpf.h"
#include "QTextStream"
#include "parameters.h"
#include <QDebug>
#include "time.h"


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
    return fitness_s;
}



QString Schtroumpf::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"( "<<couleur_gene[chrom1]<<" , "<<couleur_gene[chrom2]<<" ) = "<<couleur_txt[couleur]<<" -> fitness : "<<fitness_s<<endl;
    qDebug()<<res;
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
    fitness_s = value;
}



Schtroumpf::Schtroumpf(gene_couleur c1, gene_couleur c2, couleur_ind c, double g): chrom1(c1), chrom2(c2), couleur(c), fitness_s(g)
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
    double a;
    if (c==Rouge){
        a=1;
    }
    if (c==Vert){
        a=5;
    }
    if (c==Jaune){
        a=12;
    }
    if (c==Bleu){
        a=20;
    }
    return a;
}

Schtroumpf::Schtroumpf(Alien *parent1, Alien *parent2)
{
    //On récupère le gène parent des parents
    Schtroumpf *gene_s1=parent1->getS();
    Schtroumpf *gene_s2=parent2->getS();
    // on va créer deux variables x et y au hasard afin de selectionner 1 chromosome pour chaque parent
    int x = rand()%2+1;
    int y = rand()%2+1;
    //on créait la nouvelle liste de chromosome de ce nouvelle individu
    QList<gene_couleur> l_new_alien;
    //on créait les listes de chromosomes du parent 1 et 2
    QList<gene_couleur> l_p1;
    QList<gene_couleur> l_p2;
    //on injecte maintenant dans les listes l_p1 et l_p2 les valeurs des chromos
    l_p1<<gene_s1->getChrom1()<<gene_s1->getChrom2();
    l_p2<<gene_s2->getChrom1()<<gene_s2->getChrom2();
    //on injecte maintenant dans la nouvelle liste en fonction de x et y
    l_new_alien<<l_p1[x]<<l_p2[y];
    //on définit la couleur de l'alien en fonction de ces nouveaux chromos
    couleur_ind c = Schtroumpf::couleur_individual(l_new_alien[0], l_new_alien[1]);
    //on définit le fitness en fonction de la couleur
    double fitness_s= Schtroumpf::def_fitness_schtroumpf(c);
    //on créait le gène Schtroupf finalisé
    Schtroumpf *new_s = new Schtroumpf(l_new_alien[0], l_new_alien[1],c,fitness_s);
    liste_s.append(new_s);
}
