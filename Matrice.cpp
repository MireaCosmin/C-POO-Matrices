#include <iostream>
#include "Matrice.h"
//cosntructor fara parametri
Matrice::Matrice()
{
    l=1;
    c=1;
    m[1][1]=0;
}

//constructor cu parametri-> o matrice cu elementice cu a linii si b coloane
Matrice::Matrice(int a, int b, int x)
{
    l=a;
    c=b;
    for(int i=1;i<=l;i++)
    {

        for(int j=1;j<=c;j++)
        {

            m[i][j]=x;
        }
    }

}
//constructor cu parametri-> o matrice cu a linii si b coloane si elemente citite de la tastatura. nu am reusit sa folosesc assert pe o matrice cu elemente diferite
/*
Matrice::Matrice(int a, int b)
{
    int x;
    l=a;
    c=b;
    for(int i=1;i<=l;i++)
    {
        cout << "Elementele de pe linia " << i<< ":" << endl;
        for(int j=1;j<=c;j++)
        {
            cout << "\t\tColoana " << j << ": ";
            cin >> x;
            m[i][j]=x;
        }
    }
    cout<<"Matricea formata:"<<endl;

}
*/

bool Matrice::operator=(Matrice x)const
{

    if(l!=x.l||c!=x.c)
        {return false;
    return true;}
    else
    {
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(m[i][j]==x.m[i][j])
                    return true;
                return false;
            }
        }
    }
}

Matrice Matrice ::operator+(Matrice x)const
{
    Matrice y;
    y.l=l;
    y.c=c;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=c;j++)
        {
            y.m[i][j]=x.m[i][j]+m[i][j];

        }

    }
    return y;
}

Matrice Matrice ::operator-(Matrice x)const
{
    Matrice y;
    y.l=l;
    y.c=c;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=c;j++)
        {
            y.m[i][j]=m[i][j]-x.m[i][j];

        }

    }
    return y;
}

//merge si pentru A[m][n]*B[n][p]
Matrice Matrice ::operator*(Matrice x)const
{
    Matrice y;
    y.l=l;
    y.c=x.c;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=x.c;j++)
        {
            y.m[i][j]=0;
            for(int k=1;k<=x.c;k++)
            {
                y.m[i][j]+=m[i][k]*x.m[k][j];
            }

        }

    }
    return y;
}

Matrice operator*(int x, Matrice z)
{
    Matrice y;
    y.l=z.l;
    y.c=z.c;
    for(int i=1;i<=z.l;i++)
    {
        for(int j=1;j<=z.c;j++)
        {
            y.m[i][j]=z.m[i][j] * x;

        }

    }
    return y;
}

Matrice Matrice::operator[](int x)
{
    for(int i=1;i<=c;i++)
        std::cout<< m[x][i] <<' ';
}

//obtine matricea de ordin inferior prin eliminarea unei linii, a unei coloane sau a amandurora
Matrice Matrice::ordin(int lin, int col)
{
    Matrice x;
    x.l=0;
    x.c=0;

    for(int i=1;i<=l;i++)
    {
        if(i!=lin)
        {x.l=x.l+1;
        x.c=0;
            for(int j=1;j<=c;j++)
            {
            if(j!=col)
                {
                    x.c=x.c + 1;
                    x.m[x.l][x.c]=m[i][j];

                }
            }
        }
    }

    return x;
}
/*am aplicat formula generala : suma elementelor de pe prima linie inmultite fiecare cu determinantul
(cu semn alternat) unei matrice de ordin inferior formate prin taierea liniei si coloanei elementului respectiv.  */
int Matrice::det()
{
    int d=0;
    if(l==1)
        d= m[1][1];
    else if(l>1)
    {
        int semn=1;
        for(int i=1;i<=c;i++)
        {Matrice x;
         x=ordin(1,i);
         d=d+semn*m[1][i]*x.det();
         semn=semn*(-1);
        }
    }
         return d;
}
//am verificat daca determinantul este diferita sau egala cu 0 pentru a afla daca matricea este sau nu inversabila
bool Matrice::invers()
{
    if(det()==0)
        return false;
    return true;
}

int Matrice::getlinie()
{
    return l;
}

int Matrice::getcoloana()
{
    return c;
}

std::istream& operator>> (std::istream& in, Matrice& f) {
    in >> f.l >> f.c;
    return in;
}

std::ostream& operator<< (std::ostream& out, Matrice f) {
    for(int i=1;i<=f.l;i++)
    {
        for(int j=1;j<=f.c;j++)
        {
            out << f.m[i][j] << ' ';
        }
        out << std::endl;
    }
    return out;
}
//constructor de copiere
/*Matrice::Matrice(Matrice &d)
{
    l=d.l;
    c=d.c;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=c;j++)
        {
            m[i][j]=d.m[i][j];
        }
    }

}*/
