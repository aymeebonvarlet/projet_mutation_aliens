#include "evolutionnary_process.h"
#include "parameters.h"
#include <QTextStream>
#include <QDebug>



void Evolutionnary_process::survival(QList<Alien *> &newGeneration)
{
    //la nouvelle génération devient l'ancienne
    l_Alien = newGeneration;
}

Evolutionnary_process::Evolutionnary_process()
{
    for(int i=0 ; i<Parameters::individualsNb-1; i++){
        Alien *alien= new Alien();
        l_Alien.append(alien);
    }
}

void Evolutionnary_process::run()
{
    QList<Alien *> new_aliens;
    //on commence par la première génération qui est différente des autres
    //on run que pour la première génération
    for (int p1 = 0; p1<Parameters::individualsNb-1 ; p1++){
        int min_borne = 0;
        int max_borne = 6;
        //ajouter que le parent doit être différent du premier
        int p2 = rand()%(max_borne-min_borne+1)+1;
        while(p1==p2){
            p2 = rand()%(max_borne-min_borne+1)+1;
        }
        //gène Schtroumpf
        Gene_Schtroumpf *new_s = new Gene_Schtroumpf(l_Alien[p1]->getS(),l_Alien[p2]->getS());
        //gène Tentacules
        Gene_Tentacles *new_t = new Gene_Tentacles(l_Alien[p1]->getTs(),l_Alien[p2]->getTs());
        //on les insères
        Alien *new_a = new Alien(new_s,new_t);
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
    Gene_Schtroumpf *s1 = new Gene_Schtroumpf(R,R,Rouge,1);
    Gene_Tentacles *t1 = new Gene_Tentacles(65,5);
    l_Alien.append(new Alien(s1,t1));
    qDebug()<<"f_s : "<<l_Alien[0]->getS()->getFitness();
    qDebug()<<l_Alien[0]->getS()->getFitness();
    qDebug()<<"coucou"<<l_Alien[0]->toString();
    //Alien 2
    Gene_Schtroumpf *s2 = new Gene_Schtroumpf(R,R,Rouge,1);
    Gene_Tentacles *t2 = new Gene_Tentacles(41,5);
    l_Alien.append(new Alien(s2,t2));
    //Alien 3
    Gene_Schtroumpf *s3 = new Gene_Schtroumpf(R,R,Rouge,1);
    Gene_Tentacles *t3 = new Gene_Tentacles(10,5);
    l_Alien.append(new Alien(s3,t3));
    //Alien 4
    Gene_Schtroumpf *s4 = new Gene_Schtroumpf(R,R,Rouge,1);
    Gene_Tentacles *t4 = new Gene_Tentacles(40,5);
    l_Alien.append(new Alien(s4,t4));
    //Alien 5
    Gene_Schtroumpf *s5 = new Gene_Schtroumpf(v,v,Vert,5);
    Gene_Tentacles *t5 = new Gene_Tentacles(15,5);
    l_Alien.append(new Alien(s5,t5));
    //Alien 6
    Gene_Schtroumpf *s6 = new Gene_Schtroumpf(v,v,Vert,5);
    Gene_Tentacles *t6 = new Gene_Tentacles(20,5);
    l_Alien.append(new Alien(s6,t6));
    //Alien 7
    Gene_Schtroumpf *s7 = new Gene_Schtroumpf(b,b,Bleu,20);
    Gene_Tentacles *t7 = new Gene_Tentacles(45,5);
    l_Alien.append(new Alien(s7,t7));

    /* //on évalue les fitness de chaque nouvel individu
    for (int i = 0 ; i<Parameters::individualsNb ; i++){
        qDebug()<<"coucou"<<l_Alien[i]->toString();
        double b = Alien::def_fitness_global(l_Alien[i]);
        qDebug()<<b;
        l_Alien[i]->setFitness(b);
    }*/

    qDebug()<<"on a bien créer nos individus";
}

QString Evolutionnary_process::toString()
{
 //Retourner la liste de la population
    QString res;
    QTextStream buf(&res);
    buf<<"[ ";
    for (int all= 0; all < 7 ; all++){
        buf<<" Alien "<<all<<" "<<l_Alien[all]->toString()<<" ; ";
    }
    buf<<" ]"<<endl;
    return res;
}


