/// 3.7. Scrieţi un program care citeşte o literă mică şi o afişează sub formă de literă mare.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];

    printf("Dati o linie de text: ");

    fgets(s, 100, stdin);

    for(int i=0; i<s[i]; i++)
        if(s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';

    puts(s);

    return 0;
}
