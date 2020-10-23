#include "alien.h"



Alien::Alien()
{

}

Alien::Alien(Alien *parent1, Alien *parent2)
{
    QList<alien_gene*> genome_p1=parent1->getGenome();
    QList<alien_gene*> genome_p2=parent2->getGenome();
    //on commence par le gène Schtroumpf
    Schtroumpf *gene_s=genome_p1.;

}



QList<alien_gene *> Alien::getGenome() const
{
    return genome;
}
