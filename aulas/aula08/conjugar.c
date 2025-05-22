#include <stdio.h>
#include <string.h>

int main() {
    // VERBO PROGRAM + AR
    // EU PROGRAM + O
    // TU PROGRAM + AS
    // ELE PROGRAM + A
    // NOS PROGRAM + AMOS
    // VOS PROGRAM + AIS
    // ELES PROGRAM + AM
    char verbo[21];
    char pronomes[6][5] = {"EU", "TU", "ELE", "NOS", "VOS", "ELES"};
    char sufixos[6][5] = {"O", "AS", "A", "AMOS", "AIS", "AM"};

    printf("Entre com um verbo terminado em AR: ");
    scanf("%s", verbo);
    int tamanho = strlen(verbo);
    int ultima_posicao = tamanho -1;
    int penultima_posicao = ultima_posicao -1;

    if (verbo[penultima_posicao] == 'A' && verbo[ultima_posicao] == 'R') {
        printf("Verbo %s no presente do indicativo\n", verbo);
        char radical[21];
        strcpy(radical, verbo); // copia verbo para radical
        radical[penultima_posicao] = '\0';
        for (int i = 0; i < 6; i++) {
            char conjugacao[100];
            strcpy(conjugacao, pronomes[i]);
            strcat(conjugacao, " ");
            strcat(conjugacao, radical);
            strcat(conjugacao, sufixos[i]);
            printf("%s\n", conjugacao);
        }
    } else {
        printf("Verbo %s nao termina em AR!", verbo);
    }




    return 0;
}