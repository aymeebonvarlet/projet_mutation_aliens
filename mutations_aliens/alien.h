#ifndef ALIEN_H
#define ALIEN_H
#include <QString>
#include <QList>
#include "gene_schtroumpf.h"
#include "gene_tentacles.h"
#include <QDebug>

class Alien
{
private:
    Gene_Schtroumpf *s;
    Gene_Tentacles *ts;
    double fitness=-1;
public:
    Alien();
    Alien(Gene_Schtroumpf *st, Gene_Tentacles *t, double f=-1);
    static double def_fitness_global(Alien* a);
    QString toString();
    double evaluate();
    //getter
    Gene_Schtroumpf *getS() const;
    void setS(Gene_Schtroumpf *value);
    Gene_Tentacles *getTs() const;
    void setTs(Gene_Tentacles *value);
    double getFitness() const;
    void setFitness(double value);
};

#endif // ALIEN_H
