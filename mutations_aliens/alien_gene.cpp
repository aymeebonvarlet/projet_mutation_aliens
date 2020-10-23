#include "alien_gene.h"
#include <QTextStream>


Schtroumpf *alien_gene::getS() const
{
    return s;
}

alien_gene::alien_gene(Schtroumpf *schtroumph, tentaclessize tents) : s(schtroumph) , ts(tents)
{

}

QString alien_gene::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << " L'alien est défini par le gêne Schtroumph "<< s <<" et le gêne tentaclessize "<< *ts <<endl;
    return res;
}
