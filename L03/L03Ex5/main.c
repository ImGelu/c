/// 3.5. Să se scrie un program care citeşte un număr natural din intervalul [1600, 4900] ce reprezintă un an şi verifică dacă este bisect sau nu.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int an;

    printf("Introduceti un an intre 1600 si 4900: ");
    scanf("%d", &an);

    if(an<1600 || an>4900) printf("%d nu este in intervalul [1600, 4900]", an);
    else if(an%4==0 && an%100!=0 || an%400==0) printf("%d este an bisect", an);
    else printf("%d nu este an bisect", an);

    return 0;
}
