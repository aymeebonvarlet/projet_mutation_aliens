#ifndef SCHTROUMPF_H
#define SCHTROUMPF_H
#include <QString>

class Schtroumpf
{
private:
    QString chrom1;
    QString chrom2;
    double fitness;
public:
    Schtroumpf(QString c1, QString c2, double f);
    bool schtroumf(Schtroumpf g);
    void mutate();
    QString getChrom1() const;
    QString getChrom2() const;
    void setChrom1(const QString &value);
    void setChrom2(const QString &value);
};

#endif // SCHTROUMPF_H
