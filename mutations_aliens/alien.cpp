#include "alien.h"
#include <time.h>
#include <QTextStream>
#include <QDebug>



Gene_Schtroumpf *Alien::getS() const
{
    return s;
}

void Alien::setS(Gene_Schtroumpf *value)
{
    s = value;
}

Gene_Tentacles *Alien::getTs() const
{
    return ts;
}

void Alien::setTs(Gene_Tentacles *value)
{
    ts = value;
}

double Alien::getFitness() const
{
    return fitness;
}

void Alien::setFitness(double value)
{
    fitness = value;
}

Alien::Alien()
{

}

Alien::Alien(Gene_Schtroumpf *st, Gene_Tentacles *t, double f) : s(st), ts(t) ,fitness(f)
{
    def_fitness_global();
}



QString Alien::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"[ "<<s->toString()<<" ; ";
    qDebug()<<"dans to string alien";
    buf<< ts->toString()<<" ]"<<endl;
    qDebug()<<"ok2";
    return res;
}




void Alien::def_fitness_global()
{
    double fitness_st = s->getFitness();
    qDebug()<<s->getFitness();
    double fitness_te = ts->getFitness();
    fitness = fitness_st + fitness_te;
}









