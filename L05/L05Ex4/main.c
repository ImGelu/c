/// 3.4. Se dau două şiruri de caractere care reprezintă numere întregi zecimale foarte mari. Să se scrie un program de efectuare a operaţiilor aritmetice asupra lor.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100

void Shl(int a[], int k){
  memmove(&a[k+1], &a[1], sizeof(int)*a[0]); /// Shifteaza vectorul cu k pozitii
  memset(&a[1], 0, sizeof(int)*k); /// Umple primele Count pozitii cu 0
  a[0]+=k; /// Incrementeaza numarul de cifre
}

int Sgn(int a[], int b[]) {
  while (a[0] && !a[a[0]]) a[0]--; /// Elimina zero-urile semnificative, daca exista.
  while (b[0] && !b[b[0]]) b[0]--;

  if (a[0]<b[0]) return -1;
  else if(a[0]>b[0]) return 1;

  for(int i=a[0]; i>0; i--) {
    if(a[i]<b[i]) return -1;
    else if (a[i]>b[i]) return 1;
  }

  return 0;
}

void citire(char s[NMAX], int a[NMAX], int k){
    int i, n;

    printf("Introduceti numarul %d: ", k);
    gets(s);

    n=strlen(s);

    for(i=n; i>0; i--) a[i]=(int)(s[n-i]-'0');
    a[0]=n; /// punem numarul de cifre astfel incat sa fie usor de accesat
}

void afisare(int a[NMAX], int n){
    int i;

    for(i=n; i>0; i--) printf("%d", a[i]);
}

void suma(int a[], int b[], int s[]){
    int i, cifra, carry=0, max;
    /// completam numarul cel mai mic cu zero-uri nesemnificative la sfarsit
    if(a[0]<b[0]){
        max=b[0];
        for(i=a[0]+1; i<=b[0]; i++) a[i]=0;
    }
    else {
        max=a[0];
        for(i=b[0]+1; i<=a[0]; i++) b[i]=0;
    }

    for(i=1; i<=max; i++){
        cifra=a[i]+b[i]+carry;
        s[i]=cifra%10;
        carry=cifra/10;
    }
    if(carry!=0) s[i]=carry; /// aici i-ul va fi trecut deja la urmatoarea pozitie din stanga numarului
    else i--; /// daca nu exista carry revenim la ultima cifra calculata

    s[0]=i;

}

void diferenta(int a[], int b[], int d[]){
    int i, carry=0;

    if(a[0]<b[0]) diferenta(a, b, d);
    else{
        for(i=1; i<=a[0]; i++){
            d[i]=a[i]-b[i]+carry;
            if(d[i]<0) d[i]+=10, carry=-1;
            else carry=0;
        }
        i--;
        while(i && !d[i]) i--;

        d[0]=i;
    }
}

void produs(int a[], int b[], int p[]){
    int i, j, carry=0, n;

    p[0] = a[0]+b[0];

    for(i=1; i<=p[0];) p[i++]=0;
    for(i=1; i<=a[0]; i++)
        for(j=1; j<=b[0]; j++)
            p[i+j-1]=p[i+j-1]+a[i]*b[j];

    for(i=1; i<=p[0]; i++){
        p[i]=p[i]+carry;
        carry=p[i]/10;
        p[i]%=10;
    }
    if(carry) p[++p[0]]=carry;
}

void impartire(int a[], int b[], int c[], int r[]){
    int i;

    r[0]=0;
    c[0]=a[0];

    for(i=a[0]; i>0; i--){
        Shl(r, 1);
        r[1]=a[i];
        c[i]=0;
        while(Sgn(b, r)!=1){
            c[i]++;
            diferenta(r, b, r);
        }
    }

    while(!c[c[0]] && c[0]>1) c[0]--;
}

int main()
{

    char charA[NMAX], charB[NMAX];
    int a[NMAX], b[NMAX], s[NMAX], d[NMAX], p[NMAX], r[NMAX], imp[NMAX], k, i, n, max;

    citire(charA, a, 1);
    citire(charB, b, 1);

    suma(a, b, s);
    printf("A + B = "); afisare(s, s[0]);
    printf("\n");

    diferenta(a, b, d);
    printf("A - B = "); afisare(d, d[0]);
    printf("\n");

    produs(a, b, p);
    printf("A * B = "); afisare(p, p[0]);
    printf("\n");

    impartire(a, b, imp, r);
    printf("A : B = "); afisare(imp, imp[0]);
    printf(", rest "); afisare(r, r[0]);

    return 0;
}
