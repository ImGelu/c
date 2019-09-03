/// 3.6. Să se scrie două funcţii, una care converteşte un număr întreg sau real într-un şir de caractere, iar cealaltă face operaţia inversă. Se va scrie şi programul care testează aceste funcţii.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void inverseaza(char s[]){
    int i, n=strlen(s);
    for(i=0; i<n/2; i++){
        char aux=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=aux;
    }
}

char *intToStr(int nr){
    char aux[N];
    int i=-1, cifra, semn=1;

    if(nr<0) semn=-1, nr=-nr;
    else if(nr==0) semn=0;

    while(nr>0){
        cifra=nr%10;
        nr/=10;
        aux[++i]=cifra+'0';
    }

    if(semn==-1) aux[++i]='-';
    else if(semn==0) i=0, aux[0]='0';

    aux[++i]='\0';
    inverseaza(aux);

    char *s=calloc(strlen(aux)+1, sizeof(char));

    if(s==NULL){
        printf("Memorie insuficienta");
        exit(1);
    }

    strcpy(s, aux);

    return s;
}

int main()
{
    int nr;

    printf("Introduceti numarul: ");
    scanf("%d", &nr);

    char *s=intToStr(nr);

    printf("%s", s);

    free(s);

    return 0;
}
