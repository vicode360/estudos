#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Sleep function for windows. If linux then add ##include<unistd.h>, and change Sleep to sleep(seconds);

void menu () {
    printf("|------------------------|\n");
    printf("|          Menu          |\n");
    printf("|                        |\n");
    printf("|[1] Cadastrar           |\n");
    printf("|[2] Buscar              |\n");
    printf("|[3] Listar              |\n");
    printf("|[4] Sair                |\n");
    printf("|------------------------|\n\n");
    }
void cadastro () {
    FILE *fp;
    char nm[30];
    int a, b, c, d, e, f, num = 0;
    fp = fopen("cadastros.txt", "a");
    if (fp == NULL) {
        printf("Erro ao abrir/criar o arquivo.");
        exit(1);
    }
        do{
            printf("Digite quantas pessoas deseja cadastrar: ");
            if((scanf("%d", &b)) != 1){
                printf("Por favor digite um numero.\n");
                fseek(stdin,0,SEEK_END);
            }else{
                num = 1;
            }
        }while(num == 0);
    for (a = 1; a <= b; a++) {
        printf("Pessoa %d\n\n", a);
        printf("Nome(sem espacos): \n");
        scanf("%s", nm );
        printf("Idade: ");
        scanf("%d", &c );
        printf("Dia de nascimento: \n");
        scanf("%d", &d );
        printf("Mes de nascimento: \n");
        scanf("%d", &e );
        printf("Ano de nascimento: \n");
        scanf("%d", &f );
        printf("Pessoa %d cadastrada com sucesso!\n", a);
        fprintf(fp, "%s %d %d %d %d\n", nm, c, d, e, f);
    }
    fclose(fp);
    printf("\nDados salvos com sucesso!\n");
}
void buscar() {
    FILE *fp;
    fp = fopen("cadastros.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    char nome[30], nome_busc[30];
    int id, di, me, an, loop = 1, enc = 0;
    do {
        enc = 0;
        rewind(fp);
        printf("\nPesquisa por nome.\n");
        printf("Digite o nome a procurar no arquivo:");
        scanf(" %[^\n]", nome_busc);
        while (fscanf(fp, "%s %d %d %d %d", nome, &id, &di, &me, &an) == 5) {
            if (strcmp(nome, nome_busc) == 0) {
                printf("Registro encontrado no sistema!\n");
                printf("Nome: %s\n", nome);
                printf("Idade: %d\n", id);
                printf("Nascimento: %d/%d/%d\n", di, me, an);
                enc = 1;
                break;
            }
        }
        if (enc == 0 || enc == 1) {
            if (enc == 0) {
                printf("Nao foi possivel localizar o nome no banco de dados\n");
            }
            printf("\nDeseja realizar outra busca? \n [1] Sim [2] Nao \n");
            scanf("%d", &loop);
            if (loop == 2) {
                printf("Encerrando...\n");
                break;
            }
        }
    }while (loop == 1);
}

void listar () {
    FILE *fp;
    char nome[30];
    int idade, dia, mes, ano;
    fp = fopen("cadastros.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    printf("Pessoas cadastradas atualmente:\n");
    while (fscanf(fp, "%s %d %d %d %d", nome, &idade, &dia, &mes, &ano) == 5) {
        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", idade);
        printf("Nascimento: %d/%d/%d\n\n", dia, mes, ano );
    }
}
    int main() {
    int escolha;
    int loop = 1;
    do{ menu();
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                cadastro();
                break;
            case 2:
                buscar();
                break;
            case 3:
                listar();
                break;
            case 4:
                printf("encerrando...");
                loop = 0;
                break;
            default:
                printf("Invalido.");
                break;
        }
        Sleep(1500);
    }while(loop != 0);
}




