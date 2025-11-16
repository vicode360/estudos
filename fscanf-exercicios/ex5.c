// 5. Fazer um programa em c para ler o arquivo pessoa.txt e imprimir
// todas as pessoas com mais de 40 anos inclusive.


#include <stdio.h>

int main() {
    char nome[20];
    int idade, dia, mes , ano, p40 = 1;
    FILE *fptr;
    fptr = fopen("pessoa.txt", "r");
    if (fptr == NULL) {
        printf("erro ao abrir o arquivo");
        fclose(fptr);
    }
    while (fscanf(fptr, "%s %d %d %d %d", nome, &idade, &dia, &mes, &ano) == 5) {
        if (idade > 40) {
            if (p40 == 1) {
                printf("Pessoas com mais de 40 anos: \n");
                p40 = 0;
            }
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);
            printf("Data de nascimento: %d/%d/%d\n\n", dia, mes, ano);
        }
    }
}
