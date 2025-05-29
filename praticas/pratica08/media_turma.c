#include <stdio.h>

int main() {
    float notas[10];
    float soma = 0.0f, media = 0.0f;
    int qtde_acima_media = 0;
    for (int i = 0; i < 10; i++) {
        printf("Digite a nota[%i]:\n", i+1);
        scanf("%f", &notas[i]);
        getchar();
        soma = soma + notas[i];
    }
    media = soma / 10;
    for (int i = 0; i < 10; i++) {
        if (notas[i] > media) {
            qtde_acima_media++;
        }
    }
    printf("Valor da media: %.2f\nQuantidade acima da media: %i\n", media, qtde_acima_media);

    return 0;
}