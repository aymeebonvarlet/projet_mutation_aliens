#include "tentaclessize.h"
#include <QTextStream>
#include "parameters.h"
#include <QDebug>
srand(time(NULL));
double Tentaclessize::getFitness() const
{
    return fitness_t;
}


QString Tentaclessize::toString()
{
    QString res;
    QTextStream buf(&res);
    qDebug()<<taille;
    buf<<"taille:" <<taille<<" -> fitness = "<<fitness_t<<endl;
    return res;
}

Tentaclessize::Tentaclessize(int t, double f) : taille(t) , fitness_t(f)
{

}

Tentaclessize::Tentaclessize(Alien parent1, Alien parent2)
{
    //on récupère la valeur de la taille des tentacules des parents
    int taille_p1 = parent1->
    int taille_p2 = parent2->getTs()->getTaille();
    int taille_pNew = (taille_p1+taille_p2)/2;

    //on appelle la fonction permettant de définir le nouveau fitness du gène tentacules de l'Alien
    double fitness_pNew= Tentaclessize::def_fitness_tentacle(taille_pNew);
    //on créait le nouveau gène
    Tentaclessize *new_p = new Tentaclessize(taille_pNew, fitness_pNew);
    liste_t.append(new_p);
}

void Tentaclessize::mutate(Tentaclessize t)
{
    double tent = t.getTaille();
    double x = rand()/RAND_MAX;
    if (x<Parameters::mutationRate_tentasize){
        //on créait les bornes de la variables random désirée
        int min_borne = 0;
        int max_borne = 8;
        int x = rand()%(max_borne-min_borne+1)+1;
        //on fait la variable random pour savoir quel impact l'environement aura
        int max_borne2 = 1;
        double y = rand()/max_borne2;
        //On fait le calcul de la nouvelles taille des tentacules de notre nouvel individu
        if(y < 1){
            tent = tent - x;
        }
        else if (y >= 1) {
            tent = tent + x;
        }
        t.setTaille(tent);
    }
}

double Tentaclessize::def_fitness_tentacle(int taille)
{
    double FitnessTentSize = taille / 5;

    return FitnessTentSize ;

}

double Tentaclessize::getTaille() const
{
    return taille;
}

void Tentaclessize::setTaille(double value)
{
    taille = value;
}


