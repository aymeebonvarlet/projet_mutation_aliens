#ifndef SCHTROUMPF_H
#define SCHTROUMPF_H
#include <QString>
#include "alien.h"

enum gene_couleur {R, v ,b };
static QString couleur_gene[3]={
    "R","v","b"
};
enum couleur_ind{Rouge, Jaune, Bleu, Vert};
static QString couleur_txt[4]={
    "Rouge","Jaune","Bleu","Vert"
};
class Schtroumpf
{
private:
    gene_couleur chrom1;
    gene_couleur chrom2;
    couleur_ind couleur;
    double fitness_s;
public:
    QList<Schtroumpf*> liste_s;
    Schtroumpf(gene_couleur c1, gene_couleur c2, couleur_ind c, double g);
    Schtroumpf(Alien *parent1, Alien *parent2);
    void mutate(Schtroumpf s);
    couleur_ind couleur_individual(gene_couleur c1, gene_couleur c2);
    double def_fitness_schtroumpf(couleur_ind c);
    //getter et setter
    gene_couleur getChrom1() const;
    void setChrom1(const gene_couleur &value);
    gene_couleur getChrom2() const;
    void setChrom2(const gene_couleur &value);
    double getFitness() const;
    QString toString();
    couleur_ind getCouleur() const;
    void setCouleur(const couleur_ind &value);
    void setFitness(double value);
};

#endif // SCHTROUMPF_H
