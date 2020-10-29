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
    Alien(Schtroumpf *st, Tentaclessize *t, double f=-1);
    static Schtroumpf* new_gene_s(Alien *parent1, Alien *parent2);
    static Tentaclessize* new_gene_t(Alien *parent1, Alien *parent2);
    static double def_fitness_global(Alien* a);
    QString toString();
    //getter
    Schtroumpf *getS() const;
    double getFitness() const;
    Tentaclessize *getTs() const;
    void setFitness(double value);
};

#endif // ALIEN_H
