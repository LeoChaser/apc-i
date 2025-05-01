#ifdef _WIN32
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#else
#include <time.h>
#include <stdio.h>
#include <string.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif


int main() {
    short int venceu = 0;
    char opcao_sair = '0';
    char dificuldade = 'm';
    short int desafio = 0;
    char quebra = '\n';

    char *facil_animais[5] = {
        "gato", "vaca", "anta", "iguana", "abelha"
    };

    char *dica_facil_animais[5] = {
        "domestico", "fazenda", "floresta", "reptil", "sociedade"
    };

    char *moderada_animais[5] = {
        "capivara", "lagarto", "tamandua", "lemure", "borboleta"
    };

    char *dica_moderada_animais[5] = {
        "roedor", "reptil", "lingua", "Madagascar", "delicada"
    };

    char *dificil_animais[5] = {
        "ornitorrinco", "rinoceronte", "equidna", "salamandra", "uirapuru"
    };

    char *dica_dificil_animais[5] = {
        "evolucao", "chifre", "espinhos?", "reptil", "ave"
    };

    char desafio_animais[3] = "gnu";
    char dica_desafio_animais[16] = "Richard Stallman";

    char *facil_frutas[5] = {
        "banana", "pequi", "manga", "figo", "jambo"
    };

    char *dica_facil_frutas[5] = {
        "pintas", "espinhos", "a queridinha do DF", "comido em calda ou seco", "moreno"
    };

    char *moderada_frutas[5] = {
        "tomate", "graviola", "pitaia", "carambola", "damasco"
    };

    char *dica_moderada_frutas[5] = {
        "molhos e salada", "jaca do Para", "cacto", "estrela", "comido \"in natura\" ou seco"
    };

    char *dificil_frutas[5] = {
        "lichia", "feijoa", "jenipapo", "maracuja", "jabuticaba"
    };

    char *dica_dificil_frutas[5] = {
        "exotica", "\"goiaba-serrana\"", "da em arvores que chegam a 20 m de altura", "azedo", "vinho"
    };

    char desafio_frutas[6] = "marula";
    char dica_desafio_frutas[31] = "o espirito da Africa, canhoeiro";

    char *facil_caes[5] = {
        "poodle", "dalmata", "collie", "fila", "maltes"
    };

    char *dica_facil_caes[5] = {
        "madame", "101", "Lassie", "brasileiro", "Malta"
    };

    char *moderada_caes[5] = {
        "shiba", "basset", "buldogue", "schnauzer", "labrador"
    };

    char *dica_moderada_caes[5] = {
        "japones", "orelhas", "toureiro", "cavanhaque", "guia"
    };

    char *dificil_caes[5] = {
        "pinscher", "canaa", "weimaraner", "shihtzu", "rottweiler"
    };

    char *dica_dificil_caes[5] = {
        "pequeno", "da terra santa", "pelo curto cinza", "Tibete", "forte, de guarda e pastoreio"
    };

    char desafio_caes[5] = "corgi";
    char dica_desafio_caes[16] = "o cao da realeza";
    
    short int menu_principal = 1;
    while (menu_principal) {
        short int jogar = 0;
        short int resultado_menu_principal = 0;
        short int resultado_sair = 0;
        do {
            clrscr();
            printf("====================================== FORCA ======================================\n");
            char opcao_menu_principal = '0';
            printf("Por obsequio, digite uma opcao:\n");
            printf("1 para jogar.\n");
            printf("0 para encerrar.\n");
            resultado_menu_principal = scanf("%c%c", &opcao_menu_principal, &quebra);
            switch (opcao_menu_principal) {
                case '1':
                    jogar = 1;
                    menu_principal = 0;
                    break;
                case '0':
                    printf("Tem certeza que deseja encerrar? S/N\n");
                    resultado_menu_principal = 0;
                    do {
                        resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                        if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                            clrscr();
                            printf("Obrigado, encerrando...\n");
                            return 0;
                        } else if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                            break;
                        }
                    } while (resultado_sair != 2 || quebra != '\n');
                    resultado_sair = 0;
                    break;
                default:
                    printf("Por gentileza, digite uma opcao valida.\n");
                    printf("Pressione ENTER para continuar.\n");
                    getchar();
            }
        } while (resultado_menu_principal != 2 || quebra != '\n');
        while (jogar) {
            clrscr();
            printf("====================================== FORCA ======================================\n");
            char nome[20] = "nometeste";
            do {
                printf("Digite seu primeiro nome:\n");
                scanf("%[^\n]s", nome);
            } while (strcmp(nome, "nometeste") == 0);
            printf("Bem-vindo, %s!\n", nome);

            int dia = 99, mes = 99, ano = 9999;
            do {
                printf("Que dia voce nasceu? Digite dois digitos: \n");
                scanf("%i", &dia);
                getchar();
            } while (dia < 1 || dia > 31);
            do{
                printf("Que mes voce nasceu? Digite dois digitos: \n");
                scanf("%i", &mes);
                getchar();
            } while (mes < 1 || mes > 12);
            do {
                printf("Que ano voce nasceu? Digite quatro digitos: \n");
                scanf("%i", &ano);
                getchar();
            } while (ano < 1111 || ano > 2025);

            short int menu_dificuldade = 1;
            short int max_erros = 4;
            char *mostrar_dificuldade = "alala";
            do {
                clrscr();
                printf("====================================== FORCA ======================================\n");
                printf("Agora, escolha uma dificuldade:\n");
                printf("f para facil.\n");
                printf("m para moderada.\n");
                printf("d para dificil.\n");
                printf("0 para encerrar.\n");
                scanf("%c", &dificuldade);
                getchar();
                short int resultado_menu_dificuldade = 0; // fazeeeeeerrr
                switch (dificuldade) {
                    case 'f':
                        mostrar_dificuldade = "facil";
                        menu_dificuldade = 0;
                        break;
                    case 'm':
                        mostrar_dificuldade = "moderada";
                        max_erros = 5;
                        menu_dificuldade = 0;
                        break;
                    case 'd':
                        mostrar_dificuldade = "dificil";
                        max_erros = 6;
                        menu_dificuldade = 0;
                        break;
                    case '0':
                        printf("Tem certeza que deseja encerrar? S/N\n");
                        resultado_menu_dificuldade = 0;
                        do {
                            resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                            if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                clrscr();
                                printf("Obrigado, encerrando...\n");
                                return 0;
                            } else if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                break;
                            }
                        } while (resultado_sair != 2 || quebra != '\n');
                        resultado_sair = 0;
                        break;
                    default:
                        printf("Por gentileza, escolha uma dificuldade valida.\n");
                        printf("Pressione ENTER para continuar.\n");
                        getchar();
                }
            } while (menu_dificuldade);

            short int menu_tema = 1;
            char *mostrar_tema = "alala";
            do {
                clrscr();
                printf("====================================== FORCA ======================================\n");
                printf("Agora, escolha um tema:\n");
                printf("a para animais.\n");
                printf("f para frutos/frutas/pseudofrutos.\n");
                printf("c para caes.\n");
                printf("0 para encerrar.\n");
                char tema = '1';
                scanf("%c", &tema);
                getchar();
                short int resultado_menu_tema = 0; // fazeeeeeerrr
                switch (tema) {
                    case 'a':
                        mostrar_tema = "animais";
                        menu_tema = 0;
                        break;
                    case 'f':
                        mostrar_tema = "frutos/frutas/pseudofrutos";
                        menu_tema = 0;
                        break;
                    case 'c':
                        mostrar_tema = "caes";
                        menu_tema = 0;
                        break;
                    case '0':
                        printf("Tem certeza que deseja encerrar? S/N\n");
                        resultado_menu_tema = 0;
                        do {
                            resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                            if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                clrscr();
                                printf("Obrigado, encerrando...\n");
                                return 0;
                            } else if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                break;
                            }
                        } while (resultado_sair != 2 || quebra != '\n');
                        resultado_sair = 0;
                        break;
                    default:
                        printf("Por gentileza, escolha um tema valido.\n");
                        printf("Pressione ENTER para continuar.\n");
                        getchar();
                }
            } while (menu_tema);
    
            // selecionar palavra aleatoriamente, de acordo com o tema
            char *palavra = "alala";
            int tamanho_palavra = 5;
            short int vivo = 1;
            short int acertou = 0;
            char chutes_certos[tamanho_palavra];
            for (short int i = 0; i < tamanho_palavra; i += 1) {
                chutes_certos[i] = '_';
            }
            short int acertos = 0;
            short int erros = 0;
            short int quant_chutes = 0;
            clrscr();
            while (vivo) {
                char chute;
                char chutes[max_erros];
                if (acertos < tamanho_palavra) {
                    printf("====================================== FORCA ======================================\n");
                    printf("Dificuldade: %s; Tema: %s.\n", mostrar_dificuldade, mostrar_tema);
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
                    } else if (quant_chutes > 1) {
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
                    while (chute == '0') {
                        printf("Tem certeza que deseja encerrar? S/N\n");
                        do {
                            resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                            if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                clrscr();
                                printf("Obrigado, encerrando...\n");
                                return 0;
                            } else if (resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                printf("Chute uma letra 'a-z':\n");
                                scanf("%c", &chute);
                                getchar();
                                break;
                            }
                        } while (resultado_sair != 2 || quebra != '\n');
                        resultado_sair = 0;
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
                    printf("Dificuldade: %s; Tema: %s.\n", mostrar_dificuldade, mostrar_tema);
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
                    printf("                   A resposta esta certa: %s!\n\n", palavra);
                    printf("                       =============================\n");
                    printf("                      |                     \\O/     |\n");
                    printf("                      |      Voce venceu!!!  |      |\n");
                    printf("                      |                     / \\     |\n");
                    printf("                       =============================\n");

                    if (dificuldade == 'd') {
                        short int menu_desafio = 1;
                        printf("Voce desbloqueou o modo desafio!\n");
                        do {
                            printf("Por obsequio, digite uma opcao:\n");
                            printf("1 para jogar o modo desafio!\n");
                            printf("0 para sair...\n");
                            scanf("%c", desafio);
                            getchar();
                            switch (desafio) {
                                case '1':
                                    max_erros = 4;
                                    menu_desafio = 0;
                                    break;
                                case '0':
                                    printf("Tem certeza que deseja encerrar? S/N\n");
                                    scanf("%c", &opcao_sair);
                                    getchar();
                                    if (opcao_sair == 's' || opcao_sair == 'S') {
                                        clrscr();
                                        printf("Obrigado, encerrando...\n");
                                        return 0;
                                    }
                                    break;
                                default:
                                    printf("Por gentileza, digite uma opcao valida.\n");
                                    printf("Pressione ENTER para continuar.\n");
                                    getchar();
                            }
                        } while (menu_desafio);
                    } else {
                        printf("Deseja jogar novamente? S/N\n");
                        scanf("%c", &opcao_sair);
                        getchar();
                        if (opcao_sair == 'n' || opcao_sair == 'N') {
                            clrscr();
                            printf("Obrigado, encerrando...\n");
                            return 0;
                        } else {
                            venceu = 0;
                            jogar = 0;
                            menu_principal = 1; // testar
                        }
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
            printf("                    ___.______%%_|              |_______  _____\n");
            printf("                  _/                                   \\|     |\n");
            printf("                 |                   %s\n", nome);
            printf("                 |_____.-.______                ____/|________|\n");
            // testar!
            if (dia < 10 && mes < 10) {
                printf("                                | * 0%i/0%i/%i |\n", dia, mes, ano);
            } else if (dia < 10 && mes > 9) {
                printf("                                | * 0%i/%i/%i |\n", dia, mes, ano);
            } else if (dia > 9 && mes < 10) {
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
            printf("                               %%|              |%%\n");
            printf("                            |/.%%|            -< @%%%%%%\n");
            printf("                            `%%`@|     v        |@@%%%%@%%%%    - mfj\n");
            printf("                          .%%%%%%@@@|%%    |    %%%%%%%%%%%% @@@%%%%%%%%%%%%@%%%%%%%%%%%%\n");
            printf("                     _.%%%%%%%%%%%%@@@@@@%%%%_/%%\\_%%@@%%%%%%%%@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");

            printf("Deseja jogar novamente? S/N\n");
            scanf("%c", &opcao_sair);
            getchar();
            if (opcao_sair == 'n' || opcao_sair == 'N') {
                clrscr();
                printf("Obrigado, encerrando...\n");
                return 0;
            } else {
                venceu = 0;
                menu_principal = 1; // testar
            }
        }
    }
    return 0;
}