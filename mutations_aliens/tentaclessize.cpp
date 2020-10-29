#include "tentaclessize.h"
#include <QTextStream>
#include "parameters.h"
#include <QDebug>

double Tentaclessize::getFitness() const
{
    return fitness;
}


QString Tentaclessize::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"taille:" <<taille<<" -> fitness = "<<fitness<<endl;
    return res;
}

Tentaclessize::Tentaclessize(int t, double f) : taille(t) , fitness(f)
{

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


