#ifndef TENTACLESSIZE_H
#define TENTACLESSIZE_H
#include <QString>

class tentaclessize
{
private:
    int taille;
    double fitness;
public:
    tentaclessize(int t, double f);
    void mutate();
    //getter et setter
    int getTaille() const;
    void setTaille(int value);
    double getFitness() const;
    QString toString();

};

#endif // TENTACLESSIZE_H
