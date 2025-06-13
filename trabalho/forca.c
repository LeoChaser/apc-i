#include <time.h> // para gerar o dia da morte e para o srand
#include <stdio.h>
#include <string.h> // para uso do strcmp e strlen
#include <stdlib.h> // para uso do srand e system("cls")
#ifdef _WIN32
#define clrscr() system("cls")
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int main() {
    srand(time(NULL));

    char opcao_sair = '0';
    char dificuldade = 'm';
    char quebra = '\n';
    char *palavra = "palavrateste";
    char *dica = "dicateste";
    short int fim = 0;
    short int desafio = 0;
    short int modo_desafio_ativo = 0;
    char *mostrar_tema = "temateste";
    char *mostrar_dificuldade = "dificuldadeteste";
    char tema = '1';

    char *animais[3][5] = {
        "gato", "vaca", "anta", "iguana", "abelha",
        "capivara", "lagarto", "tamandua", "lemure", "borboleta",
        "ornitorrinco", "rinoceronte", "equidna", "salamandra", "uirapuru"
    };
    char *dicas_animais[3][5] = {
        "domestico", "fazenda", "floresta", "reptil", "sociedade",
        "roedor", "reptil", "lingua", "Madagascar", "delicada",
        "evolucao", "chifre", "espinhos?", "reptil", "ave"
    };
    char desafio_animais[4] = "gnu";
    char dica_desafio_animais[17] = "Richard Stallman";

    char *frutas[3][5] = {
        "banana", "pequi", "manga", "figo", "jambo",
        "tomate", "graviola", "pitaia", "carambola", "damasco",
        "lichia", "feijoa", "jenipapo", "maracuja", "jabuticaba"
    };
    char *dicas_frutas[3][5] = {
        "pintas", "espinhos", "a queridinha do DF", "comido em calda ou seco", "moreno",
        "molhos e salada", "jaca do Para", "cacto", "estrela", "comido \"in natura\" ou seco",
        "exotica", "\"goiaba-serrana\"", "da em arvores que chegam a 20 m de altura", "azedo", "vinho"
    };
    char desafio_frutas[7] = "marula";
    char dica_desafio_frutas[32] = "o espirito da Africa, canhoeiro";

    char *caes[3][5] = {
        "poodle", "dalmata", "collie", "fila", "maltes",
        "shiba", "basset", "buldogue", "schnauzer", "labrador",
        "pinscher", "canaa", "weimaraner", "shihtzu", "rottweiler"
    };
    char *dicas_caes[3][5] = {
        "madame", "101", "Lassie", "brasileiro", "Malta",
        "japones", "orelhas", "toureiro", "cavanhaque", "guia",
        "pequeno", "da terra santa", "pelo curto cinza", "Tibete", "forte, de guarda e pastoreio"
    };
    char desafio_caes[6] = "corgi";
    char dica_desafio_caes[17] = "o cao da realeza";
    
    short int menu_principal = 1;
    short int menu_dificuldade = 0;
    short int menu_tema = 0;
    while(menu_principal) {
        short int venceu = 0;
        short int vivo = 1;
        short int jogar = 0;
        short int resultado_menu_principal = 0;
        short int resultado_sair = 0;
        struct pessoa_t {
            char nome[21];
            int dia;
            int mes;
            int ano;
        };
        struct pessoa_t pessoa;
        // char nome[20] = "nometeste";
        // int dia = 99, mes = 99, ano = 9999;
        if(menu_dificuldade == 0) {
            do {
                clrscr();
                printf("====================================== FORCA ======================================\n");
                char opcao_menu_principal = '0';
                printf("================================== MenuPrincipal ==================================\n");
                printf("Por obsequio, digite uma opcao:\n");
                printf("1 para jogar.\n");
                printf("0 para encerrar.\n");
                resultado_menu_principal = scanf("%c%c", &opcao_menu_principal, &quebra);
                switch(opcao_menu_principal) {
                    case '1':
                        jogar = 1;
                        menu_principal = 0;
                        break;
                    case '0':
                        printf("Poxa... Tem certeza que deseja encerrar? S/N\n");
                        resultado_menu_principal = 0;
                        do {
                            resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                            if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                clrscr();
                                printf("Obrigado, encerrando...\n");
                                return 0;
                            } else if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                break;
                            }
                        } while(resultado_sair != 2 || quebra != '\n');
                        resultado_sair = 0;
                        break;
                    default:
                        printf("Por gentileza, digite uma opcao valida.\n");
                        printf("Pressione ENTER para continuar.\n");
                        getchar();
                }
            } while(resultado_menu_principal != 2 || quebra != '\n');
        }
        short int menu_nome = 1;
        short int resultado_menu_novamente = 0;
        while(jogar) {
            if(vivo == 1 && menu_nome == 1) {
                menu_nome = 0;
                strcpy(pessoa.nome, "nometeste");
                pessoa.dia = 99;
                pessoa.mes = 99;
                pessoa.ano = 9999;
                clrscr();
                printf("====================================== FORCA ======================================\n");
                do {
                    printf("Digite seu primeiro nome:\n");
                    scanf("%[^\n]s", pessoa.nome);
                    getchar();
                } while(strcmp(pessoa.nome, "nometeste") == 0);
                printf("Boas vindas, %s!\n", pessoa.nome);
                do {
                    printf("Que dia voce nasceu? Numeral: \n");
                    scanf("%i", &pessoa.dia);
                    getchar();
                } while(pessoa.dia < 1 || pessoa.dia > 31);
                do {
                    printf("Que mes voce nasceu? Numeral: \n");
                    scanf("%i", &pessoa.mes);
                    getchar();
                } while(pessoa.mes < 1 || pessoa.mes > 12);
                do {
                    printf("Que ano voce nasceu? Digite quatro digitos: \n");
                    scanf("%i", &pessoa.ano);
                    getchar();
                } while(pessoa.ano < 1111 || pessoa.ano > 2025);
            }
            if(venceu == 0 && vivo == 0 && fim == 1) {
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
                printf("                 |                   %s\n", pessoa.nome);
                printf("                 |_____.-.______                ____/|________|\n");
                if(pessoa.dia < 10 && pessoa.mes < 10) {
                    printf("                                | * 0%i/0%i/%i |\n", pessoa.dia, pessoa.mes, pessoa.ano);
                } else if(pessoa.dia < 10 && pessoa.mes > 9) {
                    printf("                                | * 0%i/%i/%i |\n", pessoa.dia, pessoa.mes, pessoa.ano);
                } else if(pessoa.dia > 9 && pessoa.mes < 10) {
                    printf("                                | * %i/0%i/%i |\n", pessoa.dia, pessoa.mes, pessoa.ano);
                } else {
                    printf("                                | * %i/%i/%i |\n", pessoa.dia, pessoa.mes, pessoa.ano);
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
                resultado_menu_novamente = scanf("%c%c", &opcao_sair, &quebra);
                do {
                    if(opcao_sair == 'n' || opcao_sair == 'N') {
                        clrscr();
                        printf("Obrigado por jogar, %s! Encerrando...\n", pessoa.nome);
                        return 0;
                    } else if(opcao_sair == 's' || opcao_sair == 'S') {
                        jogar = 0;
                        menu_principal = 1;
                        menu_dificuldade = 0;
                        menu_tema = 0;
                        modo_desafio_ativo = 0;
                    } else {
                        printf("Por gentileza, %s, escolha uma dificuldade valida.\n", pessoa.nome);
                        printf("Pressione ENTER para continuar.\n");
                        getchar();
                    }
                } while(resultado_menu_novamente != 2 && quebra != '\n');
            }
            if(modo_desafio_ativo) {
                menu_dificuldade = 0;
            } else {
                menu_dificuldade = 1;
            }
            short int max_erros = 4;
            short int posicao_dificuldade = 1;
            short int resultado_menu_dificuldade = 0;
            while(menu_dificuldade) {
                do {
                    clrscr();
                    printf("====================================== FORCA ======================================\n");
                    printf("Agora, %s, escolha uma dificuldade:\n", pessoa.nome);
                    printf("f para facil.\n");
                    printf("m para moderada.\n");
                    printf("d para dificil.\n");
                    printf("0 para encerrar.\n");
                    resultado_menu_dificuldade = scanf("%c%c", &dificuldade, &quebra);
                    switch(dificuldade) {
                        case 'f':
                            mostrar_dificuldade = "facil";
                            posicao_dificuldade = 0;
                            menu_dificuldade = 0;
                            break;
                        case 'm':
                            mostrar_dificuldade = "moderada";
                            posicao_dificuldade = 1;
                            max_erros = 5;
                            menu_dificuldade = 0;
                            break;
                        case 'd':
                            mostrar_dificuldade = "dificil";
                            posicao_dificuldade = 2;
                            max_erros = 6;
                            menu_dificuldade = 0;
                            break;
                        case '0':
                            printf("Poxa, %s! Tem certeza que deseja encerrar? S/N\n", pessoa.nome);
                            resultado_menu_dificuldade = 0;
                            do {
                                resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                                if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                    clrscr();
                                    printf("Obrigado, %s, encerrando...\n", pessoa.nome);
                                    return 0;
                                } else if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                    break;
                                }
                            } while(resultado_sair != 2 || quebra != '\n');
                            resultado_sair = 0;
                            break;
                        default:
                            printf("Por gentileza, %s, escolha uma dificuldade valida.\n", pessoa.nome);
                            printf("Pressione ENTER para continuar.\n");
                            getchar();
                    }
                } while(resultado_menu_dificuldade != 2 || quebra != '\n');
            }

            if(modo_desafio_ativo) {
                menu_tema = 0;
            } else {
                menu_tema = 1;
                tema = '1';
            }
            short int resultado_menu_tema = 0;

            while(menu_tema) {
                do {
                    clrscr();
                    printf("====================================== FORCA ======================================\n");
                    printf("Agora, %s, escolha um tema:\n", pessoa.nome);
                    printf("a para animais.\n");
                    printf("f para frutos/frutas/pseudofrutos.\n");
                    printf("c para caes.\n");
                    printf("0 para encerrar.\n");
                    int aleatorio = rand() % 5;
                    resultado_menu_tema = scanf("%c%c", &tema, &quebra);
                    switch(tema) {
                        case 'a':
                            palavra = animais[posicao_dificuldade][aleatorio];
                            dica = dicas_animais[posicao_dificuldade][aleatorio];
                            mostrar_tema = "animais";
                            menu_tema = 0;
                            break;
                        case 'f':
                            palavra = frutas[posicao_dificuldade][aleatorio];
                            dica = dicas_frutas[posicao_dificuldade][aleatorio];
                            mostrar_tema = "frutos/frutas/pseudofrutos";
                            menu_tema = 0;
                            break;
                        case 'c':
                            palavra = caes[posicao_dificuldade][aleatorio];
                            dica = dicas_caes[posicao_dificuldade][aleatorio];
                            mostrar_tema = "caes";
                            menu_tema = 0;
                            break;
                        case '0':
                            printf("Poxa, %s! Tem certeza que deseja encerrar? S/N\n", pessoa.nome);
                            resultado_menu_tema = 0;
                            do {
                                resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                                if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                    clrscr();
                                    printf("Obrigado, %s, encerrando...\n", pessoa.nome);
                                    return 0;
                                } else if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                    break;
                                }
                            } while(resultado_sair != 2 || quebra != '\n');
                            resultado_sair = 0;
                            break;
                        default:
                            printf("Por gentileza, %s, escolha um tema valido.\n", pessoa.nome);
                            printf("Pressione ENTER para continuar.\n");
                            getchar();
                    }
                } while(resultado_menu_tema != 2 || quebra != '\n');
            }
            if(modo_desafio_ativo) {
                switch(tema) {
                    case 'a':
                        palavra = desafio_animais;
                        dica = dica_desafio_animais;
                        break;
                    case 'f':
                        palavra = desafio_frutas;
                        dica = dica_desafio_frutas;
                        break;
                    case 'c':
                        palavra = desafio_caes;
                        dica = dica_desafio_caes;
                        break;
                }
            }
            int tamanho_palavra = strlen(palavra);
            short int acertou = 0;

            char chutes_certos[tamanho_palavra];
            for(short int i = 0; i < tamanho_palavra; i++) {
                chutes_certos[i] = '_';
            }
            short int acertos = 0;
            short int erros = 0;
            short int quant_chutes = 0;
            clrscr();
            vivo = 1;
            while(vivo) {
                char chute;
                char chutes[max_erros];
                if(acertos < tamanho_palavra) {
                    printf("====================================== FORCA ======================================\n");
                    if(modo_desafio_ativo) {
                        printf("Dificuldade: DESAFIO; Tema: %s.\n\n\n", mostrar_tema);
                    } else {
                        printf("Dificuldade: %s; Tema: %s.\n\n\n", mostrar_dificuldade, mostrar_tema);
                    }
                    printf("Palavra:\n");
                    short int i;
                    for(i = 0; i < tamanho_palavra; i++) {
                        if(chutes_certos[i]) {
                            printf("%c ", chutes_certos[i]);
                        } else {
                            printf("_ ");
                        }
                    }
                    printf("\n\n");
                    printf("Chutes restantes: %i!\n\n", max_erros - erros);
                    if(max_erros - erros <= 2) {
                        printf("Dica: %s!\n", dica);
                    } else {
                        printf("\n");
                    }
                    acertou = 0;

                    printf("Chutes feitos:\n");
                    if(quant_chutes == 0) {
                        printf("\n\n\n");
                    } else if(quant_chutes == 1) {
                        printf("\n%c\n\n", chutes[0]);
                    } else if(quant_chutes > 1) {
                        printf("\n%c", chutes[0]);
                        for(i = 1; i < quant_chutes; i++) {
                            printf(" - %c", chutes[i]);
                        }
                        printf("\n\n");
                    }
                    
                    if(erros == max_erros) {
                        printf("______\n");
                        printf("|    :\n");
                        printf("|    O\n");
                        printf("|   /|\\\n");
                        printf("|   / \\   _\n");
                        printf("|        | |  \n");
                        printf("--------------\n");
                        printf("Enforcado(a)!\n");
                        printf("Pressione ENTER para continuar!\n");
                        getchar();
                        vivo = 0;
                        venceu = 0;
                        fim = 1;
                        acertos = 0;
                        tamanho_palavra = 0;
                        menu_dificuldade = 0;
                        menu_tema = 0;
                        break;
                    } else {
                        printf("______\n");
                        printf("|    :\n");
                        printf("|    O\n");
                        printf("|   /|\\\n");
                        printf("|   /_\\\n");
                        printf("|   | |  \n");
                        printf("--------------\n");
                    }
                    
                    short int resultado_chute;
                    do {
                        printf("%s, chute uma letra minuscula 'a-z':\n", pessoa.nome);
                        printf("0 para encerrar.\n");
                        resultado_chute = scanf("%c%c", &chute, &quebra);
                        if(quebra != '\n') {
                            printf("Caractere invalido.\n");
                            getchar();
                        }
                    } while(resultado_chute != 2 || quebra != '\n');
                    while(chute == '0') {
                        printf("Poxa, %s! Tem certeza que deseja encerrar? S/N\n", pessoa.nome);
                        do {
                            resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                            if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                clrscr();
                                printf("Que pena, %s, encerrando...\n", pessoa.nome);
                                return 0;
                            } else if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                printf("%s, chute uma letra minuscula 'a-z':\n");
                                scanf("%c", &chute);
                                getchar();
                                break;
                            }
                        } while(resultado_sair != 2 || quebra != '\n');
                        resultado_sair = 0;
                    }
                    short int testa_chute;
                    for(testa_chute = 0; testa_chute <= tamanho_palavra; testa_chute++) {
                        if(palavra[testa_chute] == chute) {
                            acertou = 1;
                            ++acertos;
                            chutes_certos[testa_chute] = chute;
                        }
                    }
                    chutes[quant_chutes] = chute;
                    ++quant_chutes;
                    if(acertou == 0) {
                        ++erros;
                    }
                } else {
                    printf("====================================== FORCA ======================================\n");
                    if(modo_desafio_ativo) {
                        printf("Dificuldade: DESAFIO; Tema: %s.\n\n\n", mostrar_tema);
                    } else {
                        printf("Dificuldade: %s; Tema: %s.\n\n\n", mostrar_dificuldade, mostrar_tema);
                    }
                    printf("Palavra:\n");
                    short int i;
                    for(i = 0; i < tamanho_palavra; i += 1) {
                        if(chutes_certos[i]) {
                            printf("%c ", chutes_certos[i]);
                            chutes_certos[i] = '_';
                        } else {
                            printf("_ ");
                        }
                    }
                    printf("\n\n");
                    printf("Chutes restantes: %i!\n\n", max_erros - erros);

                    acertou = 0;
                    if(quant_chutes == 1) {
                        printf("\n%c\n", chutes[0]);
                    } else if(quant_chutes > 1) {
                        printf("\n%c", chutes[0]);
                        for(i = 1; i < quant_chutes; i++) {
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
                if(venceu) {
                    erros = 0;
                    venceu = 0;
                    acertos = 0;
                    acertou = 0;
                    tamanho_palavra = 0;
                    quant_chutes = 0;
                    clrscr();
                    printf("====================================== FORCA ======================================\n");
                    printf("                   %s, sua resposta esta certa: %s!\n\n",pessoa.nome, palavra);
                    printf("                       =============================\n");
                    printf("                      |                     \\O/     |\n");
                    printf("                      |      Voce venceu!!!  |      |\n");
                    printf("                      |                     / \\     |\n");
                    printf("                       =============================\n");

                    if(dificuldade == 'd' && modo_desafio_ativo == 0) {
                        short int menu_desafio = 1;
                        short int resultado_menu_desafio = 0;
                        printf("Voce desbloqueou o modo desafio!\n");
                        do {
                            do {
                                printf("Por obsequio, digite uma opcao:\n");
                                printf("d para jogar o modo desafio!\n");
                                printf("0 para sair...\n");
                                resultado_menu_desafio = scanf("%c%c", &desafio, &quebra);
                                switch(desafio) {
                                    case 'd':
                                        modo_desafio_ativo = 1;
                                        menu_desafio = 0;
                                        vivo = 0;
                                        break;
                                    case '0':
                                        printf("Poxa, %s! Tem certeza que deseja encerrar? S/N\n", pessoa.nome);
                                        do {
                                            resultado_sair = scanf("%c%c", &opcao_sair, &quebra);
                                            if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 's' || opcao_sair == 'S') {
                                                clrscr();
                                                printf("Obrigado, %s, encerrando...\n", pessoa.nome);
                                                return 0;
                                            } else if(resultado_sair == 2 && quebra == '\n' && opcao_sair == 'n' || opcao_sair == 'N') {
                                                break;
                                            }
                                        } while(resultado_sair != 2 || quebra != '\n');
                                        resultado_sair = 0;
                                        break;
                                    default:
                                        printf("Por gentileza, %s, digite uma opcao valida.\n", pessoa.nome);
                                        printf("Pressione ENTER para continuar.\n");
                                        getchar();
                                }
                            } while(resultado_menu_desafio != 2 || quebra != '\n');
                        } while(menu_desafio);
                    } else {
                        modo_desafio_ativo = 0;
                        printf("Deseja jogar novamente? S/N\n");
                        char opcao_jogar_novamente = '0';
                        do {
                            resultado_menu_novamente = scanf("%c%c", &opcao_jogar_novamente, &quebra);
                            if(opcao_jogar_novamente == 'n' || opcao_jogar_novamente == 'N') {
                                clrscr();
                                printf("Obrigado, %s, encerrando...\n", pessoa.nome);
                                return 0;
                            } else if(opcao_jogar_novamente == 's' || opcao_jogar_novamente == 'S') {
                                printf("Selecione uma opcao:\n");
                                printf("t para trocar dificuldade e tema.\n");
                                printf("m para menu principal (novo participante).\n");
                                char opcao_menu_vencedor = '0';
                                short int resultado_menu_vencedor = scanf("%c%c", &opcao_menu_vencedor, &quebra);
                                do {
                                    vivo = 0;
                                    switch(opcao_menu_vencedor) {
                                        case 't':
                                            menu_nome = 0;
                                            menu_dificuldade = 1;
                                            break;
                                        case 'm':
                                            jogar = 0;
                                            menu_nome = 1;
                                            menu_principal = 1;
                                            break;
                                        default:
                                            printf("Por gentileza, %s, digite uma opcao valida.\n", pessoa.nome);
                                            printf("Pressione ENTER para continuar.\n");
                                            getchar();
                                    }
                                } while(resultado_menu_vencedor != 2 || quebra != '\n');
                            } else {
                                printf("Por gentileza, %s, digite uma opcao valida.\n", pessoa.nome);
                                printf("Pressione ENTER para continuar.\n");
                                getchar();
                            }
                        } while(resultado_menu_novamente != 2 || quebra != '\n');
                    }
                }
                clrscr();
            }
            
        }
    }
    return 0;
}