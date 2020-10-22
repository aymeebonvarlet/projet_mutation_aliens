#ifndef ALIEN_H
#define ALIEN_H
#include <QString>
#include "alien_gene.h"
#include <QList>
class Alien
{
private:
    double fitness=-1;
    QList<alien_gene *> genome;
public:
    Alien();
    Alien(Alien *parent1, Alien *parent2);
    double getfitness() const;
    double evaluate();
    QString toString();
    QList<alien_gene *> getGenome() const;
    static bool lessFitnessThan(Alien *a1, Alien *a2);
};

#endif // ALIEN_H
