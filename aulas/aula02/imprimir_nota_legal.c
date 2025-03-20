#include <stdio.h>

int main() {
    printf(" ------------------------------------\n");
    printf("|            NOTA    LEGAL           |\n");
    printf("|------------------------------------|\n");
    printf("| Item          Quant.   Prc   Valor |\n");
    printf("| %-15s %03i %6.2f %7.2f |\n", "Caneta Azul", 2, 2.0, 4.0);
    printf("| %-15s %03i %6.2f %7.2f |\n", "Borracha", 1, 5.0, 5.0);
    printf("| %-15s %03i %6.2f %7.2f |\n", "Resma de Papel", 1, 10.0, 10.0);
    printf("|------------------------------------|\n");
    printf("|                   TOTAL: R$  19.00 |\n");
    printf(" ------------------------------------\n");

    return 0;
}