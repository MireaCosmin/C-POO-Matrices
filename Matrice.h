#ifndef _Matrice_H_
#define _Matrice_H_

class Matrice
{
    int l,c,m[100][100];
public:
    Matrice();
   Matrice(int, int, int);
   Matrice operator+(Matrice)const;
   Matrice operator-(Matrice)const;
   Matrice operator*(Matrice)const;
   bool operator=(Matrice)const;
   friend Matrice operator*(int, Matrice);
   Matrice operator[](int);
   int getlinie();
   int getcoloana();
   Matrice ordin(int,int);
   friend std::istream& operator>>(std::istream& in, Matrice&);
   friend std::ostream& operator<<(std::ostream& in, Matrice);
   int det();
   bool invers();
   //Matrice(Matrice&);


};


#endif // _Matrice_H_
