#ifndef TENTACLESSIZE_H
#define TENTACLESSIZE_H
#include <QString>

class Tentaclessize
{
private:
    int taille;
    double fitness;
public:
    Tentaclessize(int t, double f);
    void mutate();
    static double def_fitness_tentacle(int taille);
    //getter et setter
    int getTaille() const;
    void setTaille(int value);
    double getFitness() const;
    QString toString();

};

#endif // TENTACLESSIZE_H
