#ifndef ALIEN_H
#define ALIEN_H
#include <QString>
#include <QList>
#include <QDebug>
#include "gene_schtroumpf.h"
#include "gene_tentacles.h"

class Alien
{
private:
    Gene_Schtroumpf *s;
    Gene_Tentacles *ts;
    double fitness;
public:
    Alien();
    Alien(Gene_Schtroumpf *st, Gene_Tentacles *t, double f=-1);
    void def_fitness_global();
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
