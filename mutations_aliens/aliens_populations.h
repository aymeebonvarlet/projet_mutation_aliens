#ifndef ALIENS_POPULATIONS_H
#define ALIENS_POPULATIONS_H
#include "alien.h"

class Aliens_populations
{
private:
    double bestFitness;
public:

    double getBestFitness() const;
    void setBestFitness(double value);
};

#endif // ALIENS_POPULATIONS_H
