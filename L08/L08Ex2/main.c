/// 3.2. Folosind tipul structură pentru data de naştere a D-voastră şi ştiind că în anul curent vă aniversaţi ziua de naştere în ziua de x [luni, marţi, ..., duminică], scrieţi un program pentru a afişa ziua (din săptămână) în care v-aţi născut.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int ceSecol(DataCalendaristica d){
    return d.an/100 + 1;
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

void ceZi(DataCalendaristica d){
    int zi, secol=ceSecol(d);

    zi=(int)(d.zi+floor(2.6*d.luna-0.2)-2*secol + d.an + floor(d.an/4) + floor(secol/4))%7; /// formula de pe net

    switch(zi){
        case 0: printf("Duminica"); break;
        case 1: printf("Luni"); break;
        case 2: printf("Marti"); break;
        case 3: printf("Miercuri"); break;
        case 4: printf("Joi"); break;
        case 5: printf("Vineri"); break;
        case 6: printf("Sambata"); break;
    }
}

int main()
{
    DataCalendaristica d;
    d=citesteData();

    ceZi(d);

    return 0;
}
