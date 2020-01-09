#include <stdio.h>
#include <conio.h>
#include <math.h>


long int factorial(long int);

int main()
{
    char ch = ' '; //ch = choice

    printf("Witaj w kalkulatorze kombinatorycznym! Wybierz dzialanie:\
\n('c' - kombinacja, 'p' - permutacja, 'w' - wariacja z powtorzeniami, 'v' - wariacja bez powtorzen, 'x' - wyjscie)\n");

    do
    {
        scanf("%s", &ch);
        if((ch != 'c') && (ch != 'p') && (ch != 'w') && (ch != 'v') && (ch != 'x'))
        {
            printf("\nPodano zly znak. Sprobuj jeszcze raz:\
\n('c' - kombinacja, 'p' - permutacja, 'w' - wariacja z powtorzeniami, 'v' - wariacja bez powtorzen, 'x' - wyjscie)\n");
        }
        else break;
    }
    while(1); //brak warunku, poniewaz wewnatrz petli znajduje sie warunek, ktory konczy dzialanie

    if(ch == 'x') return 0;
    else
    {
        long int k = 0, n = 0, res = 0; //'k' i 'n' - oznaczenia zgodne z teoria kombinatoryki

        printf("\nPodaj ilosc elementow w zbiorze:\n");
        scanf("%ld", &n);

        switch(ch)
        {
        case 'c':
            {
                printf("\nPodaj ilosc losowanych elementow:\n");
                scanf("%ld", &k);
                res = (factorial(n))/(factorial(k)*factorial(n - k));
                printf("\nIstnieje %ld mozliwosci wylosowania %ld elementow sposrod %ld (nie istotna kolejnosc)", res, k, n);
                break;
            }
        case 'p':
            {
                res = factorial(n);
                printf("\nIstnieje %ld mozliwych ustawien zbioru %ld elementow", res, n);
                break;
            }
        case 'w':
            {
                printf("Podaj ilosc kolejno wybieranych elementow:\n");
                scanf("%ld", &k);
                res = pow(n, k);
                printf("\nIstnieje %ld mozliwosci wylosowania kolejno %ld elementow sposrod %ld (z powtorzeniami)", res, k, n);
                break;
            }
        case 'v':
            {
                printf("Podaj ilosc kolejno wybieranych elementow:\n");
                scanf("%ld", &k);
                res = (factorial(n))/(factorial(n - k));
                printf("\nIstnieje %ld mozliwosci wylosowania kolejno %ld elementow sposrod %ld (bez powtorzen)", res, k, n);
                break;
            }
        }
    }
}

long int factorial (long int n)
{
    if(n > 1) return factorial(n - 1) * n;
    else return 1;
}
