/// 3.10. Se citeşte un număr întreg, reprezentând o sumă de bani. Să se găsească numărul minim de bancnote româneşti necesare pentru plata sumei respective.

#include <stdio.h>
#include <stdlib.h>

void suma(int n){
    int bancnote[]={1, 5, 10, 50, 100, 200, 500};
    int i;

    for(i=6; i>=0; i--){
        if(n>=bancnote[i]){
            printf("%d bancnote de %d\n", n/bancnote[i], bancnote[i]);
            n=n-(n/bancnote[i])*bancnote[i];
        }
    }
}

int main()
{

    int s;
    printf("Introduceti suma: ");
    scanf("%d", &s);

    suma(s);

    return 0;
}
