#ifndef TENTACLESSIZE_H
#define TENTACLESSIZE_H


class tentaclessize
{
private:
    int taille;
public:
    tentaclessize(int t);
    void mutate();
    int getTaille() const;
    void setTaille(int value);
};

#endif // TENTACLESSIZE_H
