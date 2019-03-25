using namespace std;
#include <iostream>
#include <cmath>
#include "Matrice.h"

using namespace std;
Matrice ::Matrice()
{  //Constructor fara parametri
    n=0;
    m=0;

}
Matrice :: ~Matrice()
{//Destructor
    for(int i=0; i<n; i++)
        delete V1[i];
    delete V1;
    n=0;
    m=0;
}
Matrice Matrice :: operator=(const Matrice &a)
{//Supraincarcare operator =
    m=a.m;
    n=a.n;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            V1[i][j]=a.V1[i][j];
    return *this;
}
Matrice :: Matrice(int a,int b)
{//Constructor cu parametri
    n=a;
    m=b;
    V1=new int*[n];
    for(int i=0; i<m; i++)
        V1[i]=new int[m];
}

Matrice :: Matrice(Matrice &z)
{// Constructor de copiere
    V1=new int*[z.n];
    for(int i=0; i<z.m; i++)
        V1[i]=new int[z.m];
    n=z.n;
    m=z.m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            V1[i][j]=z.V1[i][j];


}
Matrice operator+(Matrice m1,Matrice m2)
{//Supraincarcarea operatorului +
 try{
        if(m1.n!= m2.n or m1.m!=m2.m)
          throw "adunarea nu se poate executa";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
    Matrice a(m1.n,m1.m);
    if(m1.n==m2.n && m1.m==m2.m)
    {
        for(int i=0; i<m1.n; i++)
        {
            for(int j=0; j<m1.m; j++)
                a.V1[i][j]=m1.V1[i][j]+m2.V1[i][j];
        }
        return a;
    }
}
Matrice Matrice::  operator-(Matrice m2)
{//Supraincarcare operatorului -
    try{
        if(n!=m2.n || m!=m2.m)
          throw "nu se poate face scaderea";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
    Matrice a(n,m);
    if(n==m2.n && m==m2.m)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                a.V1[i][j]=V1[i][j]-m2.V1[i][j];
        }
        return a;
    }
}
Matrice Matrice::  operator*(int z)
{// Supraincarcare * cu scalar
    Matrice a(n,m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            a.V1[i][j]=z*V1[i][j];
    }
    return a;
}
int * Matrice:: operator[](int poz)
{// Supraincarcare operator []
   try{
        if(poz>=n)
          throw "pozitia nu exista";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
    int *v;
    v=new int[m];
    for(int i=0; i<m; i++)
    {
        v[i]=V1[poz][i];
    }
    return v;
}
Matrice Matrice::  operator*(Matrice m4)
{// Supraincarcare operator * cu matrice
     try{
        if(m4.n!=m or m4.m!=n)
          throw "inmultirea nu se poate executa";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
    Matrice a(n,m4.m);
    if(n==m4.m && m==m4.n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                a.V1[i][j]=0;
                for(int x=0; x<m4.m; x++)
                    a.V1[i][j]=a.V1[i][j]+V1[i][x]*m4.V1[x][j];
            }
        }
    }
    return a;
}
istream &operator >>(istream &in,Matrice &b)
{// Supraincarcare citire
    for(int i=0; i<b.n; i++)
        for(int j=0; j<b.m; j++)
            in>>b.V1[i][j];
    return in;
}
ostream &operator <<(ostream &out,Matrice &b)
{// Supraincarcarea afisare
    for(int i=0; i<b.n; i++)
    {
        for(int j=0; j<b.m; j++)
            out<<b.V1[i][j]<<" ";
        out<<endl;
    }
}
int Matrice :: determinant()
{// Calcul determinant
     try{
        if(n!=m)
          throw "determinatul nu se poate calcula";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
    int num1,num2,det = 1,index,total = 1;
    int *temp;
    temp=new int[n+1];
    int **V2;
    V2=new int * [n+1];
    for(int i=0; i<=n; i++)
        V2[i]=new int [n+1];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            V2[i][j]=V1[i][j];
    for(int i=0; i<n; i++)
    {
        index = i;
        while(V2[index][i]==0 && index<n)
        {
            index++;

        }
        if(index==n)
        {
            continue;

        }
        if(index!=i)
        {
            for(int j=0; j<n; j++)
            {
                swap(V2[index][j],V2[i][j]);
                det = det*pow(-1,index-i);

            }
        }
        for(int j=0; j<n; j++)
        {
            temp[j]=V2[i][j];

        }
        for(int j=i+1; j<n; j++)
        {
            num1=temp[i];
            num2=V2[j][i];


            for(int k=0; k<n; k++)
            {
                V2[j][k]=(num1*V2[j][k])-(num2 * temp[k]);

            }
            total=total*num1;
        }

    }
    for(int i=0; i<n; i++)
    {
        det=det*V2[i][i];
    }
    return (det/total);
}
bool Matrice :: inversabil()
{// Inversabilitate pt matrice de intregi
    int x=determinant();
    if(x==1 or x==-1)
        return 1;
    return 0;
}
void Matrice ::elimincoloana(int z)
{// Eliminare coloana
    try{
        if(z>n)
          throw "pozitia nu exista";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
    for(int i=0; i<n; i++)
        for(int j=z; j<m; j++)
            V1[i][j-1]=V1[i][j];
    m--;

}
void Matrice :: eliminlinie(int z)
{// Eliminare linie
 try{
        if(z>n)
          throw "pozitia nu exista";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
    for(int i=z; i<n; i++)
        for(int j=0; j<m; j++)
            V1[i-1][j]=V1[i][j];
    n--;
}
void Matrice :: eliminliniecol(int z,int z1)
{// Eliminare linie si coloana
    try{
        if(z>n or z1>n)
          throw "pozitia nu exista";

   }
   catch(const char * e)
   {
     cout<<e;
     exit(EXIT_FAILURE);
   }
   for(int i=0; i<n; i++)
        for(int j=z1; j<m; j++)
            V1[i][j-1]=V1[i][j];
    m--;
    for(int i=z; i<n; i++)
        for(int j=0; j<m; j++)
            V1[i-1][j]=V1[i][j];
    n--;
}
