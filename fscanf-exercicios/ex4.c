// 4. Fazer um programa em c para ler o arquivo pessoa.txt e imprimir
// todas as pessoas entre 20 e 29 anos inclusive.

#include <stdio.h>
#include <stdlib.h>


int main() {
    char nome[20];
    int idade, dia, mes , ano, p2029 = 1;
    FILE *fptr;
    fptr = fopen("pessoa.txt", "r");
    if (fptr == NULL) {
        printf("erro ao abrir o arquivo");
        fclose(fptr);
    }
    while (fscanf(fptr, "%s %d %d %d %d", nome, &idade, &dia, &mes, &ano) == 5) {
        if (idade >= 20 && idade <= 29) {
            if (p2029 == 1) {
                printf("Pessoas entre 20 e 29 anos: \n");
                p2029 = 0;
            }
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);
            printf("Data de nascimento: %d/%d/%d\n\n", dia, mes, ano);
        }
    }
}