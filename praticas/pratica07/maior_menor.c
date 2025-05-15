#include <stdio.h>

int main() {
    int numero = 0;
    int maior = 0;
    int menor = 0;
    printf("Digite um numero:\n");
    scanf("%i", &numero);
    maior = numero;
    menor = numero;
    while(numero != 0) {
        if (numero > maior) {
            maior = numero;
        }
        if (numero < menor) {
            menor = numero;
        }
         
        printf("Digite um numero:\n");
        scanf("%i", &numero);
    }
    printf("Maior: %i; Menor: %i\n", maior, menor);
    return 0;
}