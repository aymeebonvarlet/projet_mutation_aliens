#include "evolutionnary_process.h"
#include "aliens_populations.h"
#include "parameters.h"



void Evolutionnary_process::survival(QList<Alien *> &newGeneration)
{
    population = newGeneration;
}

Evolutionnary_process::Evolutionnary_process()
{
    Aliens_populations::init();
    for(int i=0 ; i<Parameters::individualsNb; i++){
        Alien
    }
}

void Evolutionnary_process::run()
{

}
