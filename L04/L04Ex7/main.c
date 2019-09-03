/// 3.7. Se citesc cifrele hexazecimale ale unui număr întreg în baza 16. Să se calculeze şi să se afişeze reprezentarea numărului în baza 10.
/// Observație: Problema este rezolvată pentru orice bază!

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BMAX 36

int main()
{
    char nr[20];

    int b, i, val=0, cifra;

    printf("Baza (intre 2 si %d): ", BMAX);

    scanf("%d%*c", &b);
    printf("Numarul in baza %d: ", b);

    scanf("%s", &nr);

    for(i=0; nr[i]; i++){
        if(nr[i]>='0' && nr[i]<='9') cifra=nr[i]-'0';
        else {
            nr[i]=toupper(nr[i]);
            if(nr[i]>='A' && nr[i]<='Z') cifra=nr[i]-'A'+10;
            else{
                printf("%c: caracter gresit\n", nr[i]);
                exit(1);
            }
        }

        if(cifra>=b){
            printf("%d: cifra gresita\n", cifra);
            exit(1);
        }

        val=val*b+cifra;
    }

    printf("Numarul %s din baza %d are valoarea %d\n", nr, b, val);

    return 0;
}
