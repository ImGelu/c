/// 3.3 Scrieţi un program pentru a verifica ce se afişează de către funcţia putch atunci când parametrul său este o valoare în afara intervalului [32,126].

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char car;
    int cod_car;

    car=getch();
    cod_car=car;

    if(cod_car<32 || cod_car>126) printf("Ai introdus un cod din afara intervalului [32, 126]: \'%c\'", car);
    else printf("Ai apasat o tasta normala: %c", car);

    return 0;
}
