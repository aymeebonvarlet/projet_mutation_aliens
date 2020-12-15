#include "gene_tentacles.h"
#include <QTextStream>
#include "parameters.h"
#include <QDebug>

double Gene_Tentacles::getFitness() const
{
    return fitness_t;
}


QString Gene_Tentacles::toString()
{
    QString res;
    QTextStream buf(&res);
    qDebug()<<"dans tostring tentacles";
    buf<<"taille:" <<taille<<" -> fitness = "<<fitness_t;
    return res;
}



Gene_Tentacles::Gene_Tentacles(int t, double f) : taille(t) , fitness_t(f)
{

}

Gene_Tentacles::Gene_Tentacles(Gene_Tentacles *p1, Gene_Tentacles *p2)
{
    //on récupère la valeur de la taille des tentacules des parents
    int taille_p1 = p1->getTaille();
    int taille_p2 = p2->getTaille();
    taille = (taille_p1+taille_p2)/2;

    //on appelle la fonction permettant de définir le nouveau fitness du gène tentacules de l'Alien
    fitness_t = def_fitness_tentacle(taille);
}

void Gene_Tentacles::mutate()
{
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
            taille -= x;
        }
        else if (y >= 1) {
            taille += x;
        }
    }
}

double Gene_Tentacles::def_fitness_tentacle(int taille)
{
    double FitnessTentSize = taille / 5;

    return FitnessTentSize ;

}

double Gene_Tentacles::getTaille() const
{
    return taille;
}

void Gene_Tentacles::setTaille(double value)
{
    taille = value;
}


