#ifndef ALIENS_POPULATIONS_H
#define ALIENS_POPULATIONS_H
#include "alien.h"

class Aliens_populations
{
private:
    static QList<Alien *> l_Alien;
    double bestFitness;
public:
    double evaluate();
    QString toString();
    static void init();
    static QList<Alien *> getL_Alien();
};

#endif // ALIENS_POPULATIONS_H
