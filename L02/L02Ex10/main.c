/// 3.10. Scrieţi un program pentru a verifica modul de afişare a valorii lui π = 3.14159265 cu diferiţi descriptori de format.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    printf("%f %.7f %.10f\n", M_PI, M_PI, M_PI);
    printf("%d \n", M_PI);

    return 0;
}
