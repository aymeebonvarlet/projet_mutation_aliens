#ifndef ALIEN_GENE_H
#define ALIEN_GENE_H
#include "schtroumpf.h"
#include "tentaclessize.h"
#include <QString>

class alien_gene
{
private: 
    Schtroumpf *s;
    tentaclessize *ts;
public:
    alien_gene(Schtroumpf *schtroumph, tentaclessize tents);
    alien_gene(alien_gene &g);
    void mutate();
    QString toString();
};

#endif // ALIEN_GENE_H
