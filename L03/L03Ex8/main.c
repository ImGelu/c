/// 3.8. Scrieţi un program pentru a indica numărul de octeţi ocupaţi în memorie de tipurile de date din limbajul C.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("char: %d\nunsigned char: %d\nshort int: %d\nunsigned short int: %d\nint: %d\nunsigned int: %d\nlong long int: %d\nunsigned long long int: %d\nfloat: %d\ndouble: %d\nlong double: %d", sizeof(char), sizeof(unsigned char), sizeof(short int), sizeof(unsigned short int), sizeof(int), sizeof(unsigned int), sizeof(long int), sizeof(long int), sizeof(unsigned long int), sizeof(long long int), sizeof(unsigned long long int), sizeof(float), sizeof(double), sizeof(long double));
    return 0;
}
