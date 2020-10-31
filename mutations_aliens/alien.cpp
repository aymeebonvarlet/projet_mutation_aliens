#include "alien.h"
#include "schtroumpf.h"
#include <time.h>
#include <QTextStream>
#include <QDebug>

void Alien::setFitness(double value)
{
    fitness = value;
}



Alien::Alien( Schtroumpf *st, Tentaclessize *t,double f) : s(st), ts(t) ,fitness(f)
{

}



QString Alien::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"[ "<<s->toString()<<" ; ";
    qDebug()<<"ok";
    buf<< ts->toString()<<" ]"<<endl;
    qDebug()<<"ok2";
    return res;
}






Schtroumpf *Alien::getS() const
{
    return s;
}



double Alien::getFitness() const
{
    return fitness;
}



//fonction permmetant de retourner le gène Schtroumpf du nouvel individu créer à partir de 2 parents


Tentaclessize *Alien::getTs() const
{
    return ts;
}



double Alien::def_fitness_global(Alien *a)
{

    double fitness_s = a->getS()->getFitness();
    double fitness_t = a->getTs()->getFitness();
    double fitness_global = fitness_s + fitness_t;
    return fitness_global;
}

double Alien::evaluate()
{

}








