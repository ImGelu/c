/// 3.17. Se citește un număr natural n.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nrCifre(int n){ return log10(n)+1; }

int elimCifra(int n, int c){
    int p=1, rez=0;
    while(n){
        if(n%10!=c){
            rez=rez+(n%10)*p;
            p*=10;
        }
        n/=10;
    }
    return rez;
}

int main()
{
    int cifre[10], i, nr, n, n_aux, j, aux, fr[10]={0}, cifMaxima=-1, nrAparMax=-1;

    printf("Introduceti numarul n: ");
    scanf("%d", &nr);

    n=nrCifre(nr);
    n_aux=nr;

    /// Să se găsească numărul obţinut prin eliminarea cifrelor care apar de mai multe ori în număr.
    for(i=n-1; i>=0; i--){
        fr[nr%10]++;
        cifre[i]=nr%10;
        nr/=10;
    }

    for(i=0; i<=9; i++)
        if(fr[i]>nrAparMax){
            nrAparMax=fr[i];
            cifMaxima=i;
        }

    printf("Numarul %d fara cifra %d: %d\n", nr, cifMaxima, elimCifra(n_aux, cifMaxima));

    /// b) Să se găsească numărul obţinut prin interschimbarea între ele a primei cifre cu ultima, a celei de a doua cu penultima ş.a.m.d.
    for(i=0; i<n/2; i++){
        aux=cifre[i];
        cifre[i]=cifre[n-i-1];
        cifre[n-i-1]=aux;
    }

    printf("Numarul obtinut prin interschimbari: ");
    for(i=0; i<n; i++) printf("%d", cifre[i]);
    printf("\nCel mai mare numar obtinut din cifrele lui %d: ", nr);

    /// c) Să se găsească cel mai mare număr ce se poate obţine din cifrele sale.â
    for(i=9; i>=0; i--)
        for(j=1; j<=fr[i]; j++)
            printf("%d", i);

    return 0;
}
