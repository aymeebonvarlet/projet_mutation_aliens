#ifndef SCHTROUMPF_H
#define SCHTROUMPF_H
#include <QString>

enum gene_couleur {R, v ,b };
enum couleur_ind{Rouge, Jaune, Bleu, Vert};
class Schtroumpf
{
private:
    gene_couleur chrom1;
    gene_couleur chrom2;
    double fitness;
    couleur_ind couleur;
public:
    Schtroumpf(gene_couleur c1, gene_couleur c2, double f, couleur_ind c);
    void mutate();
    couleur_ind couleur_individual(gene_couleur c1, gene_couleur c2);
    //getter et setter
    gene_couleur getChrom1() const;
    void setChrom1(const gene_couleur &value);
    gene_couleur getChrom2() const;
    void setChrom2(const gene_couleur &value);
    double getFitness() const;
    double definition_fitness(couleur_ind c);
    QString toString();
};

#endif // SCHTROUMPF_H
