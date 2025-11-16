// 3. Fazer um programa em c para ler o arquivo pessoa.txt e imprimir
// todas as pessoas com 37 ou 51 anos.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[20];
    int idade, dia, mes , ano, p3751 = 1;
    FILE *fptr;
    fptr = fopen("pessoa.txt", "r");
    if (fptr == NULL) {
        printf("erro ao abrir o arquivo");
        fclose(fptr);
    }
    while (fscanf(fptr, "%s %d %d %d %d", nome, &idade, &dia, &mes, &ano) == 5) {
        if (idade == 37 || idade == 51) {
            if (p3751 == 1) {
                printf("Pessoas com 37 ou 51 anos: \n");
                p3751 = 0;
            }
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);
            printf("Data de nascimento: %d/%d/%d\n\n", dia, mes, ano);
        }
    }
}