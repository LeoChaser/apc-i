#include <stdio.h>

int main() {
    int nota = 0;
    printf("Digite uma nota:\n");
    scanf("%i", &nota);
    getchar();
    while(nota < 1 || nota > 10) {
        printf("Nota invalida. Tente novamente!\n");
        scanf("%i", &nota);
        getchar();
    }
    return 0;
}