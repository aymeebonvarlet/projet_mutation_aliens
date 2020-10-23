#include "alien.h"
#include "schtroumpf.h"
#include <time.h>
#include "alien_gene.h"

Alien::Alien()
{

}

Schtroumpf Alien::sf(Alien *parent1, Alien *parent2)
{
    srand(time(NULL));
    //On récupère le génome des parents
    QList<alien_gene*> genome_p1=parent1->getGenome();
    QList<alien_gene*> genome_p2=parent2->getGenome();
    //on commence par le gène Schtroumpf
    Schtroumpf *gene_s1=genome_p1[0]->getS();
    Schtroumpf *gene_s2=genome_p2[0]->getS();
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
    Schtroumpf *new_s = new Schtroumpf(l_new_alien[0], l_new_alien[1],c,fitness_s);
    return *new_s;

}





QList<alien_gene *> Alien::getGenome() const
{
    return genome;
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
    double tentaclessize::def_fitness(int taille)
    {
        return taille;
    }

}
