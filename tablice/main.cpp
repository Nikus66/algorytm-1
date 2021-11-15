#include <iostream>
#include<fstream>
#include "funkcje.h"

using namespace std;

int main()
{
    int n, t;//zmienna n oznacza ilosc elementów talbicy a t oznacza ilosc testów
    cout<<"podaj ilosc elementow w tablicy skladajacej sie z zer i jedynek"<<endl;
    cin>>n;
    cout<<"Podaj ilosc testow: ";
    cin>>t;

    ofstream zapis("wyniki.txt");
    while(t--)
    {
        int *tab = new int[n];
        string tab2=generuj_dane(tab, n);
        zapis<<tab2<<endl;;
       // pisz_dane(tab, n);
        tab2="";
        tab2= generuj_jedynki_przed_zerami(tab, n);
        zapis<<tab2<<endl;;
        n=n+5;
        delete tab;
    }
    cout<<"Wyniki zapisano do pliku Wyniki.txt"<<endl;
    zapis.close();
    return 0;
}

