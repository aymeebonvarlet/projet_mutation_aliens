#ifndef ALIEN_H
#define ALIEN_H
#include <QString>
#include <QList>
#include "schtroumpf.h"
#include "tentaclessize.h"
class Alien
{
private:
    Schtroumpf *s;
    Tentaclessize *ts;
    double fitness=-1;
public:
    Alien();
    Schtroumpf* sf(Alien *parent1, Alien *parent2);
    Tentaclessize* t(Alien *parent1, Alien *parent2);
    static double def_fitness_global(Alien* a);
    QString toString();
    //getter
    Schtroumpf *getS() const;
    double getFitness() const;
    double getfitness() const;
    void setFitness(double value);
    Tentaclessize *getTs() const;
};

#endif // ALIEN_H
