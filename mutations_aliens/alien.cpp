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
    //on récupère la valeur de la taille des tentacules des parents
    int taille_p1 = parent1->getTs().getTaille();
    int taille_p2 = parent2->getTs().getTaille();
    //on fait la variable random (On peut la représenter par l'environement du nouvel individu)
    int min_borne = 0;
    int max_borne = 8;
    int x = rand()%(max_borne-min_borne+1)+1;
    //on fait la variable random pour savoir quel impact l'environement aura
    int max_borne2 = 2;
    double y = (double) rand()/max_borne2;
    //On fait le calcul de la nouvelles taille des tentacules de notre nouvel individu
    double taille_pNew;
    if(y < 0.95){
        taille_pNew = (taille_p1+taille_p2)/2 - x;
    }
    else if (y > 1.05) {
        taille_pNew = (taille_p1+taille_p2)/2 + x;
    }
    else {
        taille_pNew = (taille_p1+taille_p2)/2;
    }
    return taille_pNew;


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



double Alien::getFitness() const
{
    return fitness;
}

//fonction permmetant de retourner le gène Schtroumpf du nouvel individu créer à partir de 2 parents


Tentaclessize *Alien::getTs() const
{
    return ts;
}

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
    couleur_ind c = Schtroumpf::couleur_individual(l_new_alien[0], l_new_alien[1]);
    //on définit le fitness en fonction de la couleur
    double fitness_s= Schtroumpf::def_fitness_schtroumpf(c);
    //on créait le gène Schtroupf finalisé
    Schtroumpf* new_s = new Schtroumpf(l_new_alien[0], l_new_alien[1],c,fitness_s);
    return new_s;

}

double Alien::def_fitness_global(Alien *a)
{
    double fitness_s = a->getS()->getFitness();
    double fitness_t = a->getTs().getFitness();
    double fitness_global = fitness_s + fitness_t;
    return fitness_global;
}










