#include "aliens_populations.h"
#include "alien.h"
#include <QList>
#include "schtroumpf.h"





QList<Alien *> Aliens_populations::getL_Alien()
{
    return l_Alien;
}

void Aliens_populations::init()
{
    //Alien 1
    Schtroumpf *s1 = new Schtroumpf(R,R,Rouge,1);
    Tentaclessize *t1 = new Tentaclessize(40,5);
    l_Alien.append(new Alien(s1,t1));
    //Alien 2
    Schtroumpf *s2 = new Schtroumpf(R,R,Rouge,1);
    Tentaclessize *t2 = new Tentaclessize(40,5);
    l_Alien.append(new Alien(s2,t2));
    //Alien 3
    Schtroumpf *s3 = new Schtroumpf(R,R,Rouge,1);
    Tentaclessize *t3 = new Tentaclessize(40,5);
    l_Alien.append(new Alien(s3,t3));
    //Alien 4
    Schtroumpf *s4 = new Schtroumpf(R,R,Rouge,1);
    Tentaclessize *t4 = new Tentaclessize(40,5);
    l_Alien.append(new Alien(s4,t4));
    //Alien 5
    Schtroumpf *s5 = new Schtroumpf(v,v,Vert,5);
    Tentaclessize *t5 = new Tentaclessize(40,5);
    l_Alien.append(new Alien(s5,t5));
    //Alien 6
    Schtroumpf *s6 = new Schtroumpf(v,v,Vert,5);
    Tentaclessize *t6 = new Tentaclessize(40,5);
    l_Alien.append(new Alien(s6,t6));
    //Alien 7
    Schtroumpf *s7 = new Schtroumpf(b,b,Bleu,20);
    Tentaclessize *t7 = new Tentaclessize(40,5);
    l_Alien.append(new Alien(s7,t7));

    //on évalue les fitness de chaque nouvel individu
    for (int i = 0 ; i<7 ; i++){
        double a = Alien::def_fitness_global(l_Alien[i]);
        l_Alien[i]->setFitness(a);
    }
}











