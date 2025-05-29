#include <stdio.h>

int main() {
    char frase[31];
    printf("Digite uma frase: \n");
    scanf("%[^\n]s", frase);
    getchar();
    char matriz[6][5];
    int k = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 5; j++) {
            matriz[i][j] = frase[k++];
        }
    }
    printf("Transposicao da frase: ");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 6; j++) {
            printf("%c", matriz[j][i]);
        }
    }

    return 0;
}