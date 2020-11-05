#include "alien.h"
#include "gene_schtroumpf.h"
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




//fonction permmetant de retourner le gène Schtroumpf du nouvel individu créer à partir de 2 parents






double Alien::def_fitness_global(Alien *a)
{

    double fitness_s = a->getS()->getFitness();
    double fitness_t = a->getTs()->getFitness();
    double fitness_global = fitness_s + fitness_t;
    return fitness_global;
}









