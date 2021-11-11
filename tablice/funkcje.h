#ifndef FUNKCJE_H_INCLUDED//dyrektywy preprocesora sprawdzaja zgodnosc z starszymi wersjami jezyka
#define FUNKCJE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>//generowanie automatyczne zmiennych danych
using namespace std;
int minimum(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

string generuj_dane(int tab[], int n)//funkcja generowania danyhc w dwoch postaciahc tablicy intow i stringa
{
    srand(time(NULL));
    int a;
    string dane="[";
    for(int i=0; i<n-1; i++)
    {
        a= rand()%2;
        if(a==1)
            {
                tab[i]=1;
                dane=dane+"1 ";
            }
        else
        {
            tab[i]=0;
            dane=dane+"0 ";
        }

    }
    a= rand()%2;
    if(a==1)
            {
                tab[n-1]=1;
                dane=dane+"1]";
            }
    else
        {
            tab[n-1]=0;
            dane=dane+"0]";
        }
        return dane;
}
 void pisz_dane(int tab[], int n)
 {
     for(int i=0; i<n; i++)
      cout<<tab[i]<<" ";
    cout<<endl;
 }
 string generuj_jedynki_przed_zerami(int tab[], int n)
 {
     int s0=0, s1=0 ;//s1 liczba jedynek i s0 liczba przechowywanych zer
    string dane="";
         for(int j=0; j<n ;j++)
        {
           if(tab[j]==1 && tab[j-1]==0 && j>=1)
            {
                s0=0;
                s1=1;
            }
            else if(tab[j]==1)
                {
                    s1++;
                }

                else if(s1>=2)
                    s0++;
            if(s0>=2 &&s1>=2 && tab[j+1]==1)//jesli ilosc jedynek i zer jest wieksza od 2 to znajdujemy minimum z tych dwoch wartosci i tyle razy co minimum zapisujemy
            {
                dane=dane+"[";
                int m=minimum(s1, s0);
                for(int p=0; p<m; p++)
                    dane=dane+"1 ";
                for(int p=0; p<m; p++)
                    dane=dane+"0 ";
                dane=dane+"]\n";
            }
        }
        if(s0>=2&& s1>=2)//skonczylismy przegladac tablice i nie wszystkie zera i jedynki zostaly zapisane
            {
                dane=dane+"[";
                int m=minimum(s1, s0);
                for(int p=0; p<m; p++)
                    dane=dane+"1 ";
                for(int p=0; p<m; p++)
                 dane=dane+"0 ";
                dane=dane+"]\n";
            }
            return dane;

 }


#endif // FUNKCJE_H_INCLUDED
