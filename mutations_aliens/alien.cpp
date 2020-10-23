#include "alien.h"
#include "schtroumpf.h"
#include <time.h>
#include "alien_gene.h"
#include <QTextStream>


Alien::Alien(double f, Schtroumpf *st, Tentaclessize t) : fitness(f), s(st), ts(t)
{

}

Tentaclessize Alien::t(Alien *parent1, Alien *parent2)
{
    srand(time(NULL));
    //on récupère le génome des parents ainsi que la taille des tentacules
    Tentaclessize gene_p1 = parent1->getTs();
    Tentaclessize gene_p2 = parent2->getTs();
    int min_borne = 0;
    int max_borne = 15;
    int x = rand()%(max_borne-min_borne+1)+1;

}

QString Alien::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << " L'alien est défini par le gêne Schtroumph :"<< s->toString() <<" et le gêne tentaclessize "<< ts.toString() <<endl;
    return res;
}




Schtroumpf *Alien::getS() const
{
    return s;
}

Tentaclessize Alien::getTs() const
{
    return ts;
}

double Alien::getFitness() const
{
    return fitness;
}

//fonction permmetant de retourner le gène Schtroumpf du nouvel individu créer à partir de 2 parents


Schtroumpf* Alien::sf(Alien *parent1, Alien *parent2)
{
    srand(time(NULL));
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
    couleur_ind c = couleur_individual(l_new_alien[0], l_new_alien[1]);
    //on définit le fitness en fonction de la couleur
    double fitness_s= def_fitness_schtroumpf(c);
    //on créait le gène Schtroupf finalisé
    Schtroumpf* new_s = new Schtroumpf(l_new_alien[0], l_new_alien[1],c,fitness_s);
    return new_s;

}




couleur_ind Alien::couleur_individual(gene_couleur c1, gene_couleur c2)
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

double Alien::def_fitness_schtroumpf(couleur_ind c)
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

double Alien::def_fitness_tentacle(int taille)
{

        return taille;


}

double Alien::def_fitness_global(Alien a)
{
    double fitness_s = a.getS()->getFitness();
    double fitness_t = a.getTs().getFitness();
    double fitness_global = fitness_s + fitness_t;
    return fitness_global;
}

