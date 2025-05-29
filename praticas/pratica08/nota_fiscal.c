#include <stdio.h>

int main() {
    float total = 0.0f;
    float nota_fiscal[5][3];
    for (int i = 0; i < 5; i++) {
        printf("Digite o primeiro numero:\n");
        scanf("%f", &nota_fiscal[i][0]);
        getchar();
        printf("Digite o segundo numero:\n");
        scanf("%f", &nota_fiscal[i][1]);
        getchar();
        nota_fiscal[i][2] = nota_fiscal[i][0] * nota_fiscal[i][1];
        total = total + nota_fiscal[i][2];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j<3; j++) {
            printf("Valor: %.2f, na posicao[%i][%i]\n", nota_fiscal[i][j], i, j);
        }
    }
    printf("Total: %.2f\n", total);
    return 0;
}