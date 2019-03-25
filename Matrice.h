#ifndef MATRICE_H
#define MATRICE_H
using namespace std;

class Matrice
{
    int n,m;
    int **V1;
    public:
        Matrice();
        ~Matrice();
        Matrice operator=(const Matrice &);
        Matrice(int ,int);
        Matrice(Matrice &);
        friend Matrice operator +(Matrice ,Matrice);
        Matrice operator -(Matrice);
        Matrice operator *(int);
        int *operator[](int);
        Matrice operator *(Matrice);
        friend istream &operator >>(istream &,Matrice &);
        friend ostream &operator <<(ostream &,Matrice &);
        int determinant();
        bool inversabil();
        void elimincoloana(int);
        void eliminlinie(int);
        void eliminliniecol(int,int);
};

#endif // MATRICE_H
