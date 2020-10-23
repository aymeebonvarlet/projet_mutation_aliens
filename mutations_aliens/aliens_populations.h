#ifndef ALIENS_POPULATIONS_H
#define ALIENS_POPULATIONS_H
#include "alien.h"

class Aliens_populations
{
private:
    static QList<Alien *> l_Alien;
    double bestFitness;
    Alien *selection();
    void survival(QList <Alien *> &newGeneration);
public:
    double evaluate();
    QString toString();
    void run();
    static void init();
    static double def_fitness_global(Alien* a);
    static QList<Alien *> getL_Alien();
};

#endif // ALIENS_POPULATIONS_H
