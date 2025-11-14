#include <stdio.h>
#include <stdlib.h>

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


}