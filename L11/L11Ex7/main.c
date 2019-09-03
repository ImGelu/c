/// 3.7. Să se scrie un program de rezolvare a problemei celor 8 regine (determinarea tuturor aşezărilor pe tabla de şah a celor 8 regine astfel încât să nu se atace).

#include <stdio.h>
#include <stdlib.h>

void citire(int *pn, int rez[100]){
    int i;

    printf("Introduceti n = ");
    scanf("%d", pn);

    for(i=0; i<=*pn; i++) rez[i]=0;
}

int valid(int *rez, int k){
    int i;
    for(i=1; i<=k-1; i++)
        if(rez[k]==rez[i] || (abs(rez[k]-rez[i])==k-i)) return 0;

    return 1;
}

void afisare(int *rez, int n){
    for(int i=1; i<=n; i++) printf("%d ", rez[i]);
    printf("\n");
}

void back(int *rez, int n, int k){
    int i;

    for(i=1; i<=n; i++){
        rez[k]=i;
        if(valid(rez, k))
            if(k==n) afisare(rez, n);
            else back(rez, n, k+1);
    }
}

int main()
{
    int n, rez[100], i;

    citire(&n, rez);
    back(rez, n, 1);


    return 0;
}
