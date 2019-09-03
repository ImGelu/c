/// 3.6. Scrieţi un program care să conţină apelul gets(s), unde s a fost definit ca un tablou șir de caractere. Verificaţi ce conţine fiecare element al tabloului. De ce caracterul '\n' a fost înlocuit cu '\0'?

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[21];

    printf("Dati un text (maxim 20 de caractere): ");

    fgets(s, 21, stdin);

    for(int i=0; i<21; i++) printf("%c, %d\n", s[i], s[i]);

    return 0;
}
