#include "tentaclessize.h"
#include <QTextStream>
double tentaclessize::getFitness() const
{
    return fitness;
}


QString tentaclessize::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"taille:" <<taille<<" -> fitness = "<<fitness<<endl;
    return res;
}

tentaclessize::tentaclessize(int t, double f) : taille(t) , fitness(f)
{

}

int tentaclessize::getTaille() const
{
    return taille;
}

void tentaclessize::setTaille(int value)
{
    taille = value;
}


