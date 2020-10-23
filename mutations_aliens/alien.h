#ifndef ALIEN_H
#define ALIEN_H
#include <QString>
#include "alien_gene.h"
#include <QList>
class Alien
{
private:
    double fitness=-1;
    QList<alien_gene *> genome;
public:
    Alien();
    Schtroumpf *sf(Alien *parent1, Alien *parent2);
    tentaclessize t(Alien *parent1, Alien *parent2);
    double getfitness() const;
    double evaluate();
    QString toString();
    QList<alien_gene *> getGenome() const;
    static bool lessFitnessThan(Alien *a1, Alien *a2);
    couleur_ind couleur_individual(gene_couleur c1, gene_couleur c2);
    double def_fitness_schtroumpf(couleur_ind c);
    double def_fitness_tentacle(int taille);
    double def_fitness_global(Alien a);
};

#endif // ALIEN_H
