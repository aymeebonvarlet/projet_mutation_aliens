#include "tentaclessize.h"
#include <QTextStream>
#include "parameters.h"
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

void Tentaclessize::mutate(Tentaclessize t)
{
    double x = rand()/RAND_MAX;
    if (x<Parameters::mutationRate_tentasize){

    }
}

double Tentaclessize::def_fitness_tentacle(int taille)
{
    double FitnessTentSize = taille / 5;

    return FitnessTentSize ;

}

int Tentaclessize::getTaille() const
{
    return taille;
}

void Tentaclessize::setTaille(int value)
{
    taille = value;
}


