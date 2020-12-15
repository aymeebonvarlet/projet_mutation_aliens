#include "gene_schtroumpf.h"
#include "QTextStream"
#include "parameters.h"
#include <QDebug>
#include "time.h"


gene_couleur Gene_Schtroumpf::getChrom1() const
{
    return chrom1;
}

void Gene_Schtroumpf::setChrom1(const gene_couleur &value)
{
    chrom1 = value;
}

gene_couleur Gene_Schtroumpf::getChrom2() const
{
    return chrom2;
}

void Gene_Schtroumpf::setChrom2(const gene_couleur &value)
{
    chrom2 = value;
}

double Gene_Schtroumpf::getFitness() const
{
    if (fitness_s==-1){
        qDebug()<<"ici le fitness est passé à -1";
    }
    qDebug()<<"ds le get"<<fitness_s;
    return fitness_s;
}



QString Gene_Schtroumpf::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"( "<<couleur_gene[chrom1]<<" , "<<couleur_gene[chrom2]<<" ) = "<<couleur_txt[couleur]<<" -> fitness : "<<fitness_s;
    qDebug()<<res;
    return res;
}

couleur_ind Gene_Schtroumpf::getCouleur() const
{
    return couleur;
}

void Gene_Schtroumpf::setCouleur(const couleur_ind &value)
{
    couleur = value;
}

void Gene_Schtroumpf::setFitness(double value)
{
    fitness_s = value;
}



Gene_Schtroumpf::Gene_Schtroumpf(gene_couleur c1, gene_couleur c2, couleur_ind c, double g): chrom1(c1), chrom2(c2), couleur(c), fitness_s(g)
{

}


void Gene_Schtroumpf::mutate()
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
            chrom1=new_g;
        }
        else{
            chrom2=new_g;
        }
        //et du coup, la couleur et le fitness
        couleur_ind c = couleur_individual(chrom1, chrom2);
        couleur=c;
        double f = def_fitness_schtroumpf(c);
        fitness_s=f;
    }
}


couleur_ind Gene_Schtroumpf::couleur_individual(gene_couleur c1, gene_couleur c2)
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

double Gene_Schtroumpf::def_fitness_schtroumpf(couleur_ind c)
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

Gene_Schtroumpf::Gene_Schtroumpf(Gene_Schtroumpf *parent1, Gene_Schtroumpf *parent2)
{
    // on va créer deux variables x et y au hasard afin de selectionner 1 chromosome pour chaque parent
    int x = rand()%2+1;
    int y = rand()%2+1;
    //on créait la nouvelle liste de chromosome de ce nouvelle individu
    QList<gene_couleur> l_new_alien;
    //on créait les listes de chromosomes du parent 1 et 2
    QList<gene_couleur> l_p1;
    QList<gene_couleur> l_p2;
    //on injecte maintenant dans les listes l_p1 et l_p2 les valeurs des chromos
    l_p1<<parent1->chrom1<<parent1->chrom2;
    l_p2<<parent2->chrom1<<parent2->chrom2;
    //on injecte maintenant dans la nouvelle liste en fonction de x et y
    chrom1=l_p1[x];
    chrom2=l_p2[y];
    //on définit la couleur de l'alien en fonction de ces nouveaux chromos
    couleur = couleur_individual(chrom1, chrom2);
    //on définit le fitness en fonction de la couleur
    fitness_s= def_fitness_schtroumpf(couleur);
    //on fait muter le gène
    mutate();
}
