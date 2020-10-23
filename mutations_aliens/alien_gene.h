#ifndef ALIEN_GENE_H
#define ALIEN_GENE_H
#include "schtroumpf.h"
#include "tentaclessize.h"
#include <QString>

class alien_gene
{
private: 
    Schtroumpf *s;
    Tentaclessize ts;
public:
    alien_gene(Schtroumpf *schtroumph, Tentaclessize tents);
    alien_gene(alien_gene &g);
    void mutate();
    QString toString();
    Schtroumpf *getS() const;
    Tentaclessize getTs() const;
    QString toString();
};

#endif // ALIEN_GENE_H
