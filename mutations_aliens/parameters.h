#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QString>

class Parameters
{
public:
    static  int individualsNb;
    static int generationsMaxNb;
    static int initialGenesNb;
    static int minFitnessGlobal;

    static double mutationRate_schtroumpf;
    static double crossoverRate;

    static double mutationRate_tentasize;
    static double mutationAddRate_tentasize;
    static double mutationDeleteRate_tentasize;


    static int debug;
    static void print(QString txt, int d);
};

#endif // PARAMETERS_H
