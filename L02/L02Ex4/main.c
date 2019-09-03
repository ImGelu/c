/// 3.4. Scrieţi un program care afişează codul ASCII corespunzător unei taste apăsate.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char car;
    int cod_car;

    car=getch();
    cod_car=car;

    if(cod_car<32 || cod_car>126) printf("Ai introdus un cod din afara intervalului [32, 126]: \'%c\'", car);
    else printf("Codul ASCII al tastei %c este %d", car, cod_car);

    return 0;
}
