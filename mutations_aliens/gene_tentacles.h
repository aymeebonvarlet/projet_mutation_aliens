#ifndef GENE_TENTACLES_H
#define GENE_TENTACLES_H
#include <QString>

class Gene_Tentacles
{
private:
    double taille;
    double fitness_t;
public:
    Gene_Tentacles(int t, double f);
    Gene_Tentacles(Gene_Tentacles *p1, Gene_Tentacles *p2);
    void mutate();
    double def_fitness_tentacle(int taille);
    //getter et setter
    double getTaille() const;
    void setTaille(double value);
    double getFitness() const;
    QString toString();
};

#endif // GENE_TENTACLES_H
