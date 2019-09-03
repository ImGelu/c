/// 3.5. Să se scrie o funcţie care sortează în ordine crescătoare n şiruri de caractere.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **citeste(int *pn){ /// ** pentru ca este vector de caractere (cum ar fi c[][])
    int i;
    char tmp[100];

    printf("Numar de siruri: ");
    scanf("%d%*c", pn);

    char **s=calloc(*pn, sizeof(char*));
    if(s==NULL){
        printf("Memorie insuficienta");
        exit(1);
    }

    for(i=0; i<*pn; i++){
        fgets(tmp, 100, stdin);
        s[i]=calloc(strlen(tmp)+1, sizeof(char));
        if(s[i]==NULL){
            printf("Memorie insuficienta");
            exit(1);
        }
        strcpy(s[i], tmp);
    }
    return s;
}

void bubble(char** s, int n){
    int i, sortat=0;
    char *aux;

    while(!sortat){
        sortat=1;
        for(i=1; i<n; i++)
        if(strcmp(s[i], s[i-1])>0){
            aux=s[i-1];
            s[i-1]=s[i];
            s[i]=aux;
            sortat=0;
        }
        n--;
    }
}

void afisare(int n, char **s){
    int i;
    for(i=0; i<n; i++) printf("%s", s[i]);
}

int main()
{
    int n;
    char **s;

    s=citeste(&n);
    bubble(s, n);
    afisare(n, s);

    free(s);

    return 0;
}
