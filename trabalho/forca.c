#ifdef _WIN32
#include <time.h>
#include <stdio.h>
#include <conio.h>
#else
#include <time.h>
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif


int main() {
    short int venceu = 0;
    short int acertos = 0;
    short int erros = 0;
    short int max_erros;
    short int tamanho_palavra = 0;
    short int menu_principal = 1;
    char dificuldade;
    short int desafio = 0;
    char opcao_sair;
    short int quant_chutes = 0;

    while (menu_principal) {
        short int jogar;
        clrscr();
        printf("====================================== FORCA ======================================\n");
        char opcao_menu_principal;
        printf("Por obsequio, digite uma opcao:\n");
        printf("1 para jogar.\n");
        printf("0 para encerrar.\n");
        scanf("%[^\n]c", &opcao_menu_principal);
        getchar();

        switch (opcao_menu_principal) {
            case '1':
                jogar = 1;
                menu_principal = 0;
                break;
            case '0':
                printf("Tem certeza que deseja encerrar? S/N\n");
                scanf("%[^\n]c", &opcao_sair);
                if (opcao_sair == 's' || opcao_sair == 'S') {
                    menu_principal = 0;
                    jogar = 0;
                    clrscr();
                    printf("Obrigado, encerrando...\n");
                    return 0;
                }
                break;
            // não mostraaaaa
            default:
                printf("Por gentileza, digite uma opcao valida.\n");
        }
        while (jogar) {
            clrscr();
            printf("====================================== FORCA ======================================\n");
            char nome[20];
            printf("Digite seu primeiro nome:\n");
            scanf("%[^\n]s", nome);
            getchar();
            printf("Bem-vindo, %s!\n", nome);
            int dia, mes, ano;
            printf("Que dia voce nasceu? Digite dois digitos: \n");
            scanf("%i", &dia);
            getchar();
            printf("Que mes voce nasceu? Digite dois digitos: \n");
            scanf("%i", &mes);
            getchar();
            printf("Que ano voce nasceu? Digite quatro digitos: \n");
            scanf("%i", &ano);
            getchar();

            short int menu_dificuldade = 1;
            while (menu_dificuldade) {
                clrscr();
                printf("====================================== FORCA ======================================\n");
                printf("Agora, escolha uma dificuldade:\n");
                printf("1 para facil.\n");
                printf("2 para moderada.\n");
                printf("3 para dificil.\n");
                printf("0 para encerrar.\n");

                scanf("%[^\n]c", &dificuldade);
                getchar();
                switch (dificuldade) {
                    case '1':
                        menu_dificuldade = 0;
                        break;
                    case '2':
                        menu_dificuldade = 0;
                        break;
                    case '3':
                        menu_dificuldade = 0;
                        break;
                    case '0':
                        printf("Tem certeza que deseja encerrar? S/N\n");
                        scanf("%[^\n]c", &opcao_sair);
                        if (opcao_sair == 's' || opcao_sair == 'S') {
                            menu_dificuldade = 0;
                            jogar = 0;
                            clrscr();
                            printf("Obrigado, encerrando...\n");
                            return 0;
                        }
                        break;
                    default:
                        printf("Por gentileza, escolha uma dificuldade valida.\n");
                }
            }
            clrscr();
            printf("====================================== FORCA ======================================\n");
            // temas
            // printf("Escolha um tema:\n");
    
            // selecionar palavra aleatoriamente, de acordo com o tema
            char palavra[5] = "alala";
            tamanho_palavra = 5;
            max_erros = tamanho_palavra - 2;
            short int vivo = 1;
            short int acertou = 0;
            char chutes_certos[tamanho_palavra];
            for (short int i = 0; i < tamanho_palavra; i += 1) {
                chutes_certos[i] = '_';
            }

            clrscr();
            while (vivo) {
                char chute;
                // error: variable-sized object may not be initialized except with an empty initializer
                char chutes[max_erros];
                if (acertos < tamanho_palavra) {
                    printf("====================================== FORCA ======================================\n");
                    printf("Chute uma letra 'a-z':\n");
                    printf("0 para encerrar.\n");
                    
                    short int i;
                    for (i = 0; i < tamanho_palavra; i += 1) {
                        if (chutes_certos[i]) {
                            printf("%c ", chutes_certos[i]);
                        } else {
                            printf("_ ");
                        }
                    }
                    printf("\n");
                    printf("Chutes restantes: %i!\n\n", max_erros - erros);
                    acertou = 0;

                    printf("Chutes feitos:\n");
                    if (quant_chutes == 1) {
                        printf("\n%c\n", chutes[0]);
                    }
                    if (quant_chutes > 1) {
                        printf("\n%c", chutes[0]);
                        for (i = 1; i < quant_chutes; i += 1) {
                            printf(" %c", chutes[i]);
                        }
                        printf("\n\n");
                    }
                    
                    if (erros == max_erros) {
                        printf("______\n");
                        printf("|    :\n");
                        printf("|    O\n");
                        printf("|   /|\\\n");
                        printf("|   / \\   _\n");
                        printf("|        | |  \n");
                        printf("--------------\n");
                        printf("Enforcado!\n");
                        printf("Pressione ENTER para continuar!\n");
                        getchar();
                        vivo = 0;
                    } else {
                        printf("______\n");
                        printf("|    :\n");
                        printf("|    O\n");
                        printf("|   /|\\\n");
                        printf("|   /_\\\n");
                        printf("|   | |  \n");
                        printf("--------------\n");
                    }

                    scanf("%c", &chute);
                    getchar();
                    if (chute == '0') {
                        printf("Tem certeza que deseja encerrar? S/N\n");
                        scanf("%[^\n]c", &opcao_sair);
                        if (opcao_sair == 's' || opcao_sair == 'S') {
                            clrscr();
                            printf("Obrigado, encerrando...\n");
                            return 0;
                        }
                    }                
                    short int testa_chute;
                    for (testa_chute = 0; testa_chute <= tamanho_palavra; testa_chute += 1) {
                        if (palavra[testa_chute] == chute) {
                            acertou = 1;
                            ++acertos;
                            chutes_certos[testa_chute] = chute;
                        }
                    }
                    chutes[quant_chutes] = chute;
                    ++quant_chutes;
                    if (acertou == 0) {
                        ++erros;
                    }
                } else {
                    printf("====================================== FORCA ======================================\n");
                    printf("Chute uma letra 'a-z':\n");
                    printf("0 para encerrar.\n");
                    short int i;
                    for (i = 0; i < tamanho_palavra; i += 1) {
                        if (chutes_certos[i]) {
                            printf("%c ", chutes_certos[i]);
                            chutes_certos[i] = '_';
                        } else {
                            printf("_ ");
                        }
                    }
                    printf("\n");
                    printf("Chutes restantes: %i!\n\n", max_erros - erros);

                    acertou = 0;
                    if (quant_chutes == 1) {
                        printf("\n%c\n", chutes[0]);
                    }
                    if (quant_chutes > 1) {
                        printf("\n%c", chutes[0]);
                        for (i = 1; i < quant_chutes; i += 1) {
                            printf(" - %c", chutes[i]);
                        }
                        printf("\n\n");
                    }
                    printf("______\n");
                    printf("|    :\n");
                    printf("|    O\n");
                    printf("|   /|\\\n");
                    printf("|   /_\\\n");
                    printf("|   | |  \n");
                    printf("--------------\n");
                    venceu = 1;
                    printf("Pressione ENTER para continuar!\n");
                    getchar();
                }
                if (venceu) {
                    erros = 0;
                    venceu = 0;
                    acertos = 0;
                    acertou = 0;
                    quant_chutes = 0;
                    clrscr();
                    printf("====================================== FORCA ======================================\n");
                    // tá mostrando o nomeeeeeeeeeeeeeee
                    printf("                   A resposta esta certa: %s!\n\n", palavra);
                    printf("                       =============================\n");
                    printf("                      |                     \\O/     |\n");
                    printf("                      |      Voce venceu!!!  |      |\n");
                    printf("                      |                     / \\     |\n");
                    printf("                       =============================\n");
                    // e possivel isso abaixo?
                    if (dificuldade == '3') {
                        short int menu_desafio = 1;
                        short int opcao_desafio;
                        printf("Voce desbloqueou o modo desafio!\n");
                        while (menu_desafio) {
                            printf("Por obsequio, digite uma opcao:\n");
                            printf("1 para jogar o modo desafio!\n");
                            printf("0 para sair...\n");
                            switch (opcao_desafio) {
                                case 1:
                                    desafio = 1;
                                    menu_desafio = 0;
                                    break;
                                case 0:
                                    printf("Tem certeza que deseja encerrar? S/N\n");
                                    scanf("%[^\n]c", &opcao_sair);
                                    if (opcao_sair == 's' || opcao_sair == 'S') {
                                        menu_desafio = 0;
                                        jogar = 0;
                                        clrscr();
                                        printf("Obrigado, encerrando...\n");
                                        return 0;
                                    }
                                    break;
                                default:
                                    printf("Por gentileza, digite uma opcao valida.\n");
                            }
                        }
                        while (desafio) {
                            // fazer o modo desafio
                        }
                        
                    } else {
                        printf("Deseja jogar novamente? S/N\n");
                        scanf("%[^\n]c", &opcao_sair);
                        getchar();
                        if (opcao_sair == 'n' || opcao_sair == 'N') {
                            jogar = 0;
                            clrscr();
                            printf("Obrigado, encerrando...\n");
                            return 0;
                        }
                        venceu = 0;
                    }
                }
                clrscr();
            }
            clrscr();
            printf("====================================== FORCA ======================================\n");
            printf("                                 _____  _______\n");
            printf("                                <     `/       |\n");
            printf("                                 >            (\n");
            printf("                                |    _     _   |\n");
            printf("                                |   |_) | |_)  |\n");
            printf("                                |   | \\ | |    |\n");
            printf("                    ___.______\%_|              |_______  _____\n");
            printf("                  _/                                   \\|     |\n");
            printf("                 |                   %s\n", nome);
            printf("                 |_____.-.______                ____/|________|\n");
            // testar!
            if (dia < 10 && mes < 10) {
                printf("                                | * 0%i/0%i/%i |\n", dia, mes, ano);
            }
            if (dia < 10 && mes > 9) {
                printf("                                | * 0%i/%i/%i |\n", dia, mes, ano);
            }
            if (dia > 9 && mes < 10) {
                printf("                                | * %i/0%i/%i |\n", dia, mes, ano);
            } else {
                printf("                                | * %i/%i/%i |\n", dia, mes, ano);
            }
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            printf("                                | + %02d/%02d/%d |\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            printf("                                |              |\n");
            printf("                                |   _          <\n");
            printf("                                |__/           |\n");
            printf("                                 / `--.        |\n");
            printf("                               \%|              |\%\n");
            printf("                            |/.\%\%|            -< @\%\%\%\%\n");
            printf("                            `\%`@|     v        |@@\%\%@\%\%\%\%    - mfj\n");
            printf("                          .\%\%\%@@@|\%    |    \%\%\%\%\%\% @@@\%\%\%\%\%\%@\%\%\%\%\%\%\%\%\n");
            printf("                     _.\%\%\%\%\%\%@@@@@@\%\%_/\%\\_%@@\%\%\%\%@@@@@@@\%\%\%\%\%\%\%\%\%\%\%\%\%\%\n");
            jogar = 0;
        }
    }
    return 0;
}