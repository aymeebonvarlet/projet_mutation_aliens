#ifndef EVOLUTIONNARY_PROCESS_H
#define EVOLUTIONNARY_PROCESS_H

#include "alien.h"
#include <QList>

class Evolutionnary_process
{
private:
    QList<Alien *> l_Alien;
    Alien *selection();
    void survival(QList <Alien *> &newGeneration);
public:
    Evolutionnary_process();
    void run();
    void init();
    QString toString();
};

#endif // EVOLUTIONNARY_PROCESS_H
