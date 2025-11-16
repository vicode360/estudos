// 2. Fazer um programa em c para ler o arquivo pessoa.txt e imprimir
// todas as pessoas com 37 anos.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[35];
    int idade, dia, mes, ano, p37 = 0;

    FILE *fptr;
    fptr = fopen("pessoa.txt", "r");
    if (fptr == NULL) {
        fclose(fptr);
        printf("Nao foi possivel abrir o arquivo.");
    }
    rewind(fptr);
    while (fscanf(fptr, "%s %d %d %d %d", nome, &idade, &dia, &mes, &ano) == 5){
        if (idade == 37) {
            if (p37 == 0) {
                printf("Pessoas com 37 anos: \n");
            }
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);
            printf("Nascimento: %d/%d/%d\n\n",  dia, mes, ano);
            p37++;
        }
    }
    fclose(fptr);
}
