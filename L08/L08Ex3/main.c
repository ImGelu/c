/// 3.3. Să se scrie un program modularizat care citeşte datele legate de studenţii unei grupe: nume, data naşterii, adresa şi îi afisează în ordine crescătoare lexicografică.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {char nume[30], adresa[60], data_nastere[10];} Student;

void bubble(Student *s, int n){
    int i, sortat=0;
    Student aux;

    while(!sortat){
        sortat=1;
        for(i=1; i<n; i++)
            if(strcmp(s[i-1].nume,s[i].nume)>0){
                aux=s[i-1];
                s[i-1]=s[i]; /// *(a+i-1)=*(a+i)
                s[i]=aux;
                sortat=0;
            }
        n--;
    }
}

Student citeste(int id){
    Student s;

    printf("\nStudentul %d: \n", id);

    printf("\tNume: ");
    gets(s.nume);

    printf("\tAdresa: ");
    gets(s.adresa);

    printf("\tData nasterii: ");
    gets(s.data_nastere);

    return s;
}

int main()
{
    Student s[100];
    int n, i;

    printf("Introduceti numarul de elevi: ");
    scanf("%d%*c", &n);

    for(i=0; i<n; i++) s[i]=citeste(i);

    bubble(s, n);

    printf("\n\n---------LISTA STUDENTILOR--------\n#  \tNume\t\tAdresa\t\tData nasterii\n\n");

    for(i=0; i<n; i++) printf("#%d \t%s\t\t%s\t\t%s\t\n", i, s[i].nume, s[i].adresa, s[i].data_nastere);

    return 0;
}
