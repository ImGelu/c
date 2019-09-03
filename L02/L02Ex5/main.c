/// 3.5. Scrieţi un program care afişează caracterul corespunzător unui cod ASCII din intervalul [32,126].

#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=32; i<127; i++) printf("%c \t%d ", i, i);
    return 0;
}
