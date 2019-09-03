/// 3.4. Să se scrie un program recursiv care citeşte n cuvinte şi le afişează în ordinea inversă a introducerii lor.

#include <stdio.h>
#include <stdlib.h>

void invers(FILE* pf){
    char s[20];

    if(fscanf(pf, "%s", s)<1) return ;
    invers(pf);
    printf("%s ", s);
}

int main()
{
    FILE *pf = fopen("cuvinte.txt", "r");

    if(pf==NULL){
        perror("cuvinte.txt");
        exit(1);
    }

    invers(pf);
    fclose(pf);

    return 0;
}
