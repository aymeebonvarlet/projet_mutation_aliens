#include "evolutionnary_process.h"
#include "parameters.h"



void Evolutionnary_process::survival(QList<Alien *> &newGeneration)
{
    //la nouvelle génération devient l'ancienne
    l_Alien = newGeneration;
}

Evolutionnary_process::Evolutionnary_process()
{
    for(int i=0 ; i<Parameters::individualsNb; i++){
        Alien *alien= new Alien();
        l_Alien.append(alien);
    }
}

void Evolutionnary_process::run()
{
    Evolutionnary_process();
    //on commence par la première génération qui est différente des autres
    //on run que pour la première génération
    for (int p1 = 0; p1<7 ; p1++){
        int min_borne = 0;
        int max_borne = 6;
        int p2 = rand()%(max_borne-min_borne+1)+1;

    }

}

void Evolutionnary_process::init()
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

QString Evolutionnary_process::toString()
{

}


