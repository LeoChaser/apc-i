#include <stdio.h>

int main() {
    int numero;
    printf("Informe um numero inteiro: ");
    scanf("%i", &numero);
    getchar();
    printf("O numero informado foi %i \n", numero);

    float nota;
    printf("Informe uma nota entre 0.0. a 10.0: ");
    scanf("%f", &nota);
    getchar();
    printf("A sua nota foi %0.1f \n", nota);

    
    return 0;
}