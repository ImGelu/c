/// 3.9. Să se scrie o funcţie care primind ca parametru un număr arab în baza 10, calculează şirul de caractere ce reprezintă numărul respectiv sub formă romană.

#include <stdio.h>
#include <stdlib.h>

void toRoman(int nr){
    int i=0;
    char *rom[]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arab[14]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for(i=0; i<12; i++){
        while(nr>=arab[i]){
            nr-=arab[i];
            printf("%s", rom[i]);
        }
    }
}

int main()
{
    int nr;

    printf("Numar in cifre arabe: ");
    scanf("%d", &nr);

    toRoman(nr);

    return 0;
}
