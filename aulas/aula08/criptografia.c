#include <stdio.h>

int main() {
    char frase[30] = {'E', 'u', ' ', 'p', 'r', 'o', 'g', 'r', 'a', 'm', 'o', ' ', 'e', 'm', ' ', 'C', '\0'};
    // char frase[16] = "Eu programo em C";
    for (int i = 0; i <30; i++) {
        printf("%c", frase[i]);
    }
    printf("\n");
    printf("%s\n", frase);

    printf("Digite uma frase: \n");
    scanf("%[^\n]s", frase);
    while (getchar() != '\n');

    char cesar[6][5];
    int k = 0;
    for(int i = 0; i < 6; i++){
        for (int j = 0; j < 5; j++) {
            cesar[i][j] = frase[k];
            k++;
        }
    }
    printf("Sua frase codificada: ");
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 6; i++) {
            printf("%c", cesar[i][j]);
        }
    }
    printf("\n");

    return 0;
}