/// 3.7. Fiind date anul, luna, ziua, să se scrie o funcţie care să returneze a câtea zi din an este ziua respectivă şi câte zile au mai rămas din anul respectiv.

#include <stdio.h>
#include <stdlib.h>

typedef struct{ unsigned short zi, luna, an; } DataCalendaristica;

int eBisect(int an){
    if((an%4==0 && an%100!=0) || an%400==0) return 1;
    return 0;
}

int nrZileLuna(unsigned short l, unsigned short a){
    switch(l){
        case 2: return 28+eBisect(a);
        case 4: case 6: case 9: case 11: return 30;
    }
    return 31;
}

int aCataZi(DataCalendaristica d){
    int n=0;
    unsigned short l;
    for(l=1; l<d.luna; l++) n+=nrZileLuna(l, d.an);

    return n+d.zi;
}

int eCorecta(DataCalendaristica d){
    if(d.an<1600 || d.an>4900) return 0;
    if(d.luna<1 || d.luna>12) return 0;
    if(d.zi<1 || d.zi>nrZileLuna(d.luna, d.an)) return 0;

    return 1;
}

DataCalendaristica citesteData(){
    DataCalendaristica d;
    do{
        printf("Data (zz/ll/aaaa): ");
        scanf("%2hu/%2hu/%4hu", &d.zi, &d.luna, &d.an);
        fflush(stdin);
    } while(!eCorecta(d));

    return d;
}

int main()
{
    DataCalendaristica d;
    d=citesteData();

    int n=aCataZi(d);
    printf("Este a %d-a zi\n", n);
    printf("Au ramas %d zile\n", 365+eBisect(d.an)-n);

    return 0;
}
