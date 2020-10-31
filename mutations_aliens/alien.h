#ifndef ALIEN_H
#define ALIEN_H
#include <QString>
#include <QList>
#include "schtroumpf.h"
#include "tentaclessize.h"
#include <QDebug>
class Alien
{
private:
    Schtroumpf *s;
    Tentaclessize *ts;
    double fitness=-1;
public:
    Alien(Schtroumpf *st, Tentaclessize *t, double f=-1);
    double def_fitness_global(Alien* a);
    QString toString();
    double evaluate();
    //getter
    Schtroumpf *getS() const;
    double getFitness() const;
    Tentaclessize *getTs() const;
    void setFitness(double value);
};

#endif // ALIEN_H
