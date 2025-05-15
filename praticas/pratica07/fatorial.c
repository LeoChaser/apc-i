#include <stdio.h>

int main() {
    int numero = 0;
    int fatorial = 1;
    printf("Digite um numero:\n");
    scanf("%i", &numero);
    getchar();
    for(int i=numero; i>0; i--) {
        fatorial = fatorial * i;
        printf("Numero: %i; Fatorial: %i\n", numero, fatorial);
    }
    return 0;
}