#ifndef ALIENS_POPULATIONS_H
#define ALIENS_POPULATIONS_H
#include "alien.h"

class Aliens_populations
{
private:
    QList<Alien> l_Alien;
    double bestFitness;
    Alien *selection();
    void survival(QList <Alien *> &newGeneration);
public:
    Aliens_populations(QList<Alien> l_a);
    QList<Alien> getL_Alien() const;
    void setL_Alien(const QList<Alien> &value);
    double evaluate();
    QString toString();
    void run();
};

#endif // ALIENS_POPULATIONS_H
