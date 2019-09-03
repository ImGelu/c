/// 3.8. Scrieţi un program care citeşte o literă mare şi o afişează sub formă de literă mică.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];

    printf("Dati o linie de text: ");

    fgets(s, 100, stdin);

    for(int i=0; i<s[i]; i++)
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';

    puts(s);

    return 0;
}
