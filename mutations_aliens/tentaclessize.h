#ifndef TENTACLESSIZE_H
#define TENTACLESSIZE_H
#include <QString>

class Tentaclessize
{
private:
    double taille;
    double fitness;
public:
    Tentaclessize(int t, double f);
    static void mutate(Tentaclessize t);
    static double def_fitness_tentacle(int taille);
    //getter et setter
    double getTaille() const;
    void setTaille(double value);
    double getFitness() const;
    QString toString();

};

#endif // TENTACLESSIZE_H
