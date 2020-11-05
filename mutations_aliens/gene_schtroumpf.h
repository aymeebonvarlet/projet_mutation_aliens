#ifndef GENE_SCHTROUMPF_H
#define GENE_SCHTROUMPF_H
#include <QString>

enum gene_couleur {R, v ,b };
static QString couleur_gene[3]={
    "R","v","b"
};
enum couleur_ind{Rouge, Jaune, Bleu, Vert};
static QString couleur_txt[4]={
    "Rouge","Jaune","Bleu","Vert"
};

class Gene_Schtroumpf
{
private:
    gene_couleur chrom1;
    gene_couleur chrom2;
    couleur_ind couleur;
    double fitness_s;
public:
    Gene_Schtroumpf(gene_couleur c1, gene_couleur c2, couleur_ind c, double g);
    Gene_Schtroumpf(Gene_Schtroumpf *parent1, Gene_Schtroumpf *parent2);
    void mutate();
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

#endif // GENE_SCHTROUMPF_H
