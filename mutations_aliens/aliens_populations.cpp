#include "aliens_populations.h"

Aliens_populations::Aliens_populations(QList<Alien> l_a): l_Alien(l_a)
{

}

QList<Alien> Aliens_populations::getL_Alien() const
{
    return l_Alien;
}

void Aliens_populations::setL_Alien(const QList<Alien> &value)
{
    l_Alien = value;
}


