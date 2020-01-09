#include <stdio.h>
#include <conio.h>
#include <math.h>


long long int factorial(long long int);

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
        long long int k = 0, n = 0, res = 0; //'k' i 'n' - oznaczenia zgodne z teoria kombinatoryki

        printf("\nPodaj ilosc elementow w zbiorze:\n");
	do
	{
        scanf("%lld", &n);
		if(n < 1) printf("\nPodano zla ilosc. Podaj ilosc jeszcze raz:\n");
		else break;
	}
	while (1); //brak warunku, poniewaz wewnatrz petli znajduje sie warunek, ktory konczy dzialanie

        switch(ch)
        {
        case 'c':
            {
                printf("\nPodaj ilosc losowanych elementow:\n");
                do
                {
                    scanf("%lld", &k);
        	        if((k < 1) || (n < k)) printf("\nPodano zla ilosc. Podaj ilosc jeszcze raz:\n");
                    else break;
                }
                while(1); //brak warunku, poniewaz wewnatrz petli znajduje sie warunek, ktory konczy dzialanie

                res = (factorial(n))/(factorial(k)*factorial(n - k));
                printf("\nIstnieje %lld mozliwosci wylosowania %lld elementow sposrod %lld (nie istotna kolejnosc)", res, k, n);
                break;
            }
        case 'p':
            {
                res = factorial(n);
                printf("\nIstnieje %lld mozliwych ustawien zbioru %lld elementow", res, n);
                break;
            }
        case 'w':
            {
                printf("Podaj ilosc kolejno wybieranych elementow:\n");
                do
                {
                    scanf("%lld", &k);
        	        if((k < 1) || (n < k)) printf("\nPodano zla ilosc. Podaj ilosc jeszcze raz:\n");
                    else break;
                }
                while(1); //brak warunku, poniewaz wewnatrz petli znajduje sie warunek, ktory konczy dzialanie

                res = pow(n, k);
                printf("\nIstnieje %lld mozliwosci wylosowania kolejno %lld elementow sposrod %lld (z powtorzeniami)", res, k, n);
                break;
            }
        case 'v':
            {
                printf("Podaj ilosc kolejno wybieranych elementow:\n");
                do
                {
                    scanf("%lld", &k);
        	        if((k < 1) || (n < k)) printf("\nPodano zla ilosc. Podaj ilosc jeszcze raz:\n");
                    else break;
                }
                while(1); //brak warunku, poniewaz wewnatrz petli znajduje sie warunek, ktory konczy dzialanie

                res = (factorial(n))/(factorial(n - k));
                printf("\nIstnieje %lld mozliwosci wylosowania kolejno %lld elementow sposrod %lld (bez powtorzen)", res, k, n);
                break;
            }
        }
    }
}

long long int factorial (long long int n)
{
    int i = n;
    n = 1;
    for(i;i;i--) n *= i;
}
