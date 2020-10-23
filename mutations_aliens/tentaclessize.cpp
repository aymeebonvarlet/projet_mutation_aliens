#include "tentaclessize.h"
#include <QTextStream>
double Tentaclessize::getFitness() const
{
    return fitness;
}


QString Tentaclessize::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"taille:" <<taille<<" -> fitness = "<<fitness<<endl;
    return res;
}

Tentaclessize::Tentaclessize(int t, double f) : taille(t) , fitness(f)
{

}

double Tentaclessize::def_fitness_tentacle(int taille)
{
    return taille;

}

int Tentaclessize::getTaille() const
{
    return taille;
}

void Tentaclessize::setTaille(int value)
{
    taille = value;
}


