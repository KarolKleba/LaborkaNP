#include <stdio.h>
#include <conio.h>
#include <math.h>


int main()
{
    double base = 0, num = 0, res = 0, itv = 0; //res = result; itv = interval
    short int h = 0; //h = help - zmienna pomocnicza - ustawiona na 0 po to, aby ominac switcha - patrz nizej


    printf("Witaj w kalkulatorze logarytmicznym! Podaj podstawe logarytmu:\n");
    do
    {
        scanf("%lf", &base);
        if((base < 0) || (base == 1)) printf("\nPodano zla podstawe. Podstawa musi być wieksza od zera i rozna od 1. Sprobuj jeszcze raz:\n");
        else break;
    }
    while(1);


    printf("\nPodaj liczbe z wyliczanego algorytmu:\n");
    do
    {
        scanf("%lf", &num);
        if(num <= 0) printf("\nPodano zla liczba. Liczba musi byc wieksza od 0. Sprobuj jeszcze raz:\n");
        else break;
    }
    while(1);

    //jezeli wynik logarytmu jest mniejszy od 0, h zostaje ustawione na -1, jezeli wiekszy od 0 - 1;
    //pozostale dwa warunki wynikaja z wlasnosci logarytmu i od razu daja odpowiedz, wiec nie trzeba jej szukac,
    //dlatego switch szukajacy wyniku zostaje pominiety
    if(num == base) res = 1;
    else if(num == 1) res = 0;
    else if(num > 1) h = 1;
    else h = -1;


    switch(h)
    {
    case 1:
        {
            itv = 1;
            for(itv; itv > 0.0000009; itv /= 10)
            {
                while(pow(base, res) < num) res += itv;
                if(pow(base, res) == num) break;
                res -= itv;
            }
            break;
        }
    case -1:
        {
            itv = -1;
            for(itv; itv < -0.0000009; itv /= 10)
            {
                while(pow(base, res) > num) res += itv;
                if(pow(base, res) == num) break;
                res -= itv;
            }
            break;
        }
    }
    printf("\nLogarytm o podstawie %lf z %lf wynosi %lf", base, num, res);

    return 0;
}















/*
if((num/base) > 1) h = 1; //oznacza, ze rozwiazanie logarytmu jest wieksze od 1
    else if((num/base) == 1)
    {

        h = 2; //ustawienie h na 2 powoduje nie wykonywanie przyszlej instrukcji switch() poniewaz wynik juz zostal znaleziony
        res = 1;
    }
    else if(num > 1) h = 0; //oznacza, ze rozwiazanie logarytmu znajduje sie pomiedzy 0 a 1
    else if(num == 1)
    {
        h = 2; //ustawienie h na 2 powoduje nie wykonywanie przyszlej instrukcji switch() poniewaz wynik juz zostal znaleziony
        res = 0;
    }
    else h = -1; //oznacza, ze rozwiazanie logarytmu jest mniejsze od 0
*/
