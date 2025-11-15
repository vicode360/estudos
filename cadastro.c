#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
FILE *fptr;
char nome[30];
int idade, dia, mes, ano, qtd, num = 0;

fptr = fopen("cadastros.txt", "w");
    if (fptr == NULL) {
        printf("Erro ao abrir/criar o arquivo.");
        exit(1);
    }

    do{
        printf("Digite quantas pessoas deseja cadastrar: ");
            if((scanf("%d", &qtd)) != 1){
                printf("Por favor digite um numero.\n");
                fseek(stdin,0,SEEK_END);
            }else{
                num = 1;
            }
    }while(num == 0);

    for (int i = 1; i <= qtd; i++) {
        printf("Pessoa %d\n\n", i);
        printf("Nome(sem espacos): \n");
        scanf("%s", nome );
        printf("Idade: ");
        scanf("%d", &idade );
        printf("Dia de nascimento: \n");
        scanf("%d", &dia );
        printf("Mes de nascimento: \n");
        scanf("%d", &mes );
        printf("Ano de nascimento: \n");
        scanf("%d", &ano );
        printf("Pessoa %d cadastrada com sucesso!\n", i);
        fprintf(fptr, "Nome: %s \nIdade: %d - %d/%d/%d \n", nome, idade, dia, mes, ano);
    }
fclose(fptr);
    printf("\nArquivo 'cadastros.txt' criado com sucesso!");
 printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    fptr = fopen("cadastros.txt", "r");
    char nome_busca[30];
    int loopar;
do {
    int encontrou = 0;
    rewind(fptr);
    printf("\nPesquisa por nome.\n");
    printf("Digite o nome a procurar no arquivo:");
    scanf("%s", nome_busca);

    while (fscanf(fptr, "%s %d %d %d  %d", nome, &idade, &dia, &mes, &ano) == 5) {
        if (strcmp(nome, nome_busca) == 0) {
            printf("Registro encontrado no sistema!\n");
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);
            printf("Nascimento: %d/%d/%d\n", dia, mes, ano);
            encontrou = 1;
            break;
        }
        }
    if (encontrou == 0) {
        printf("Nao foi possivel localizar o nome no banco de dados, deseja realizar a consulta novamente?\n");
        printf("[1] Sim | [2] Nao\n");
        scanf("%d", &loopar);
        if (loopar == 2) {
            printf("Encerrando...");
            break;
        }
    }
    if (encontrou == 1) {
    printf("Deseja realizar a consulta novamente?\n");
        printf("[1] Sim | [2] Nao\n");
        scanf("%d", &loopar);
        if (loopar == 2) {
            printf("Encerrando...");
            break;
        }
    }
}while (loopar == 1);
}
