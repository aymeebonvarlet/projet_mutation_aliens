#ifndef TENTACLESSIZE_H
#define TENTACLESSIZE_H
#include <QString>
#include "alien.h"

class Tentaclessize
{
private:
    double taille;
    double fitness_t;
public:
    QList<Tentaclessize*> liste_t;
    Tentaclessize(int t, double f);
    Tentaclessize(Alien *parent1, Alien *parent2);
    void mutate(Tentaclessize t);
    double def_fitness_tentacle(int taille);
    //getter et setter
    double getTaille() const;
    void setTaille(double value);
    double getFitness() const;
    QString toString();

};

#endif // TENTACLESSIZE_H
