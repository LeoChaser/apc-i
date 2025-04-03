#include <stdio.h>

int main() {
    char tecla;

    printf("Pressione uma tecla e depois Enter: ");
    scanf("%c", &tecla);    // nao sabe a tecla = valor
                            // entao precisa acessar endereco
                            // da variavel com o operador &
    getchar();
    printf("Voce pressionou a tecla '%c'\n", tecla);

    printf("Pressione uma tecla e depois Enter: ");
    scanf("%c", &tecla);
    getchar();
    printf("Voce pressionou a tecla '%c'\n", tecla);
    
    char nome[31];
    printf("Informe seu nome: ");
    scanf("%[^\n]s", nome);
    printf("Olá, %s!\n", nome);

    return 0;
}