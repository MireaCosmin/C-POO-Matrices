#include <iostream>
#include "Matrice.h"
#include <cassert>



int testare()
{
    assert(Matrice(2,2,3) + Matrice(2,2,4) = Matrice(2,2,7) );
    assert(Matrice (2,2,4) - Matrice (2,2,2) = Matrice (2,2,2));
    assert(Matrice(2,2,1) * Matrice(2,2,3) = Matrice (2,2,6));
    assert ( 5 * Matrice(3,3,4) = Matrice (3,3,20));

}
int main()
{
    /*Matrice m1;
    std::cout<<"Constructor fara parametri: "<<m1;
    Matrice m2(2,2);
    std::cout<<"Constructor cu parametri:\n"<<m2;
    Matrice m3(2,2);
    std::cout<<"Constructor cu parametri:\n"<<m3;
    std::cout<<"Suma lui m2 si m3 este: \n" << m2 + m3;
    std::cout<<"Diferenta lui m2 si m3 este: \n" << m2 - m3;
    std::cout<<"Produsul lui m2 si m3 este: \n" << m2 * m3;
    std::cout<<"Produsul lui m2 si un scalar: \n" << 4* m2;
    std::cout<<"Linia lui m2: ";
    m2[2];
    std::cout<<"\nMatricea m2 de ordin inferior:\n"<<m2.ordin(0,2);
    std::cout<<"Determinantul matricei m2: "<<m2.det();
    if(m2.invers()==true)
        std::cout<<" => este inversabila";
    else
        std::cout<<" => nu este inversabila";
    std::cout<<'\n'<<"Nr de coloane ale lui m2: "<<m2.getcoloana()<<"\nNr de linii ale lui m2: "<<m2.getlinie();
    */

    testare();
    std::cout<<"test reusit";
    return 0;
}
