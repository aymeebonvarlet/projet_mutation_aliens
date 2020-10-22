#include "alien.h"

Alien::Alien(Schtroumpf_gene c, tentaclessize_gene t): color(c), tentaclessize(t)
{

}

QList<alien_gene *> Alien::getGenome() const
{
    return genome;
}
