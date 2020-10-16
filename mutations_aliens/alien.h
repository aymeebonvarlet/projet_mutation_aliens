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
    Alien(Alien *parent);
    double getfitness() const;
    double evaluate();
    QString toString();
};

#endif // ALIEN_H
