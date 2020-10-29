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
    couleur_ind couleur;
    double fitness;
public:
    Schtroumpf();
    Schtroumpf(gene_couleur c1, gene_couleur c2, couleur_ind c, double g);
    static void mutate(Schtroumpf s);
    static couleur_ind couleur_individual(gene_couleur c1, gene_couleur c2);
    static double def_fitness_schtroumpf(couleur_ind c);
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
