#ifndef ALIENS_POPULATIONS_H
#define ALIENS_POPULATIONS_H
#include "alien.h"

class Aliens_populations
{
private:
    static QList<Alien *> l_Alien;
    double bestFitness;
public:
    QString toString();
    static void init();
    static QList<Alien *> getL_Alien();
    double getBestFitness() const;
    void setBestFitness(double value);
};

#endif // ALIENS_POPULATIONS_H
