#ifndef ALIEN_H
#define ALIEN_H
#include <QString>
#include <QList>
#include "schtroumpf.h"
#include "tentaclessize.h"
class Alien
{
private:
    double fitness=-1;
    Schtroumpf *s;
    Tentaclessize ts;
public:
    Alien(double f=-1, Schtroumpf *st, Tentaclessize t);
    Schtroumpf* sf(Alien *parent1, Alien *parent2);
    Tentaclessize t(Alien *parent1, Alien *parent2);
    couleur_ind couleur_individual(gene_couleur c1, gene_couleur c2);
    double def_fitness_schtroumpf(couleur_ind c);
    double def_fitness_tentacle(int taille);
    double def_fitness_global(Alien a);
    QString toString();
    //getter
    Schtroumpf *getS() const;
    Tentaclessize getTs() const;
    double getFitness() const;
    double getfitness() const;
};

#endif // ALIEN_H
