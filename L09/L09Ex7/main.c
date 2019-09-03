/// 3.7. Să se scrie un program care citeşte n şiruri de caractere şi afişează şirul cel mai lung şi şirul cel mai mare alfanumeric.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **citeste(int *pn){  /// ** pentru ca este vector de caractere (cum ar fi c[][])
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

void *celMaiLungSir(char **s, int n){
    int nMax=0, i;
    char *cMax=malloc(sizeof(char)*n+1);

    for(i=0; i<n; i++)
        if(strlen(s[i])>nMax){
            nMax=strlen(s[i]);
            strcpy(cMax, s[i]);
        }

    return cMax;
}

void afisare(int n, char **s){
    int i;
    for(i=0; i<n; i++) printf("%s", s[i]);
}

int main()
{
    int n;
    char **s, *cmls;

    s=citeste(&n);
    cmls=celMaiLungSir(s, n);

    printf("Cel mai lung sir este sirul: %s", cmls);

    free(s);

    return 0;
}
