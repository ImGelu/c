/// 3.9. Convertiţi în binar, prin calcul, anul naşterii şi anul curent. Arătaţi cum se reprezintă ca o dată de tip int. Efectuaţi operaţiile de deplasare stânga cu 4 biţi, dreapta cu 2 biţi, complement faţă de 1 asupra lor, precum şi operaţiile pe biţi &, ^, | , având ca operanzi cele două date. Scrieţi un program pentru a verifica corectitudinea calculelor dumneavoastră.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int an1, an2;

    printf("Introduceti anul nasterii: ");
    scanf("%d", &an1);

    printf("Introduceti anul curent: ");
    scanf("%d", &an2);

    printf("Anul nasterii in hexa: %x\nAnul curent in hexa: %x\n\n", an1, an2);

    printf("an1<<4 = %x\n", an1<<4);
    printf("an1>>2 = %x\n", an1>>2);

    return 0;
}
