#include "evolutionnary_process.h"
#include "parameters.h"
#include <QTextStream>
#include "alien.h"



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
    QList<Alien *> new_aliens;
    //on commence par la première génération qui est différente des autres
    //on run que pour la première génération
    for (int p1 = 0; p1<7 ; p1++){
        int min_borne = 0;
        int max_borne = 6;
        int p2 = rand()%(max_borne-min_borne+1)+1;
        Schtroumpf *new_s = Alien::new_gene_s(l_Alien[p1],l_Alien[p2]);
        Schtroumpf::mutate(*new_s);
        Tentaclessize *new_t = Alien::new_gene_t(l_Alien[p1],l_Alien[p2]);
        Tentaclessize::mutate(*new_t);
        Alien *new_a = new Alien(new_s,new_t);
        new_a->setFitness(Alien::def_fitness_global(new_a));
        new_aliens.append(new_a);
    }
    //on range les aliens dans la nouvelle liste en fonction de leurs fitness
    for (int i=0 ; i<7 ; i++){
        for (int j=1 ; j<7 ; j++){
            if (new_aliens[i]->getFitness()<new_aliens[j]->getFitness()){
                Alien *index= new_aliens[i];
                new_aliens[i]=new_aliens[j];
                new_aliens[j]=index;
            }
        }
    }
    survival(new_aliens);

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
 //Retourner la liste de la population
    QString res;
    QTextStream buf(&res);
    for (int all= 0; all < 7 ; all++){
        buf<<"Alien n°"<<all<<" "<<l_Alien[all]->toString()<<endl;
    }
    return res;
}


