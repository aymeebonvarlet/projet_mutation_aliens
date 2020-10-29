#include "parameters.h"
#include "../../shared/qstd.h"
using namespace qstd;

int Parameters::individualsNb = 7;
int Parameters::generationsMaxNb = 50;
int Parameters::initialGenesNb = 2;
int Parameters::minFitnessGlobal = 0;

double Parameters::mutationRate_schtroumpf=0.1;
double Parameters::mutationRate_tentasize=0.2;
double Parameters::mutationAddRate_tentasize=0.2;
double Parameters::mutationDeleteRate_tentasize=0.1;
double Parameters::crossoverRate = 0.6;
// TODO : modifier la graine

int Parameters::debug = 1;

void Parameters::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt<<endl;
}

