// 7. Fazer um programa em c para ler o arquivo pessoa.txt e imprimir o
// total de pessoas entre 20 e 40 anos inclusive.



#include <stdio.h>

int main() {
    char nome[20];
    int idade, dia, mes , ano, p2040 = 1;
    int cont = 0;
    FILE *fptr;
    fptr = fopen("pessoa.txt", "r");
    if (fptr == NULL) {
        printf("erro ao abrir o arquivo");
        fclose(fptr);
    }
    while (fscanf(fptr, "%s %d %d %d %d", nome, &idade, &dia, &mes, &ano) == 5) {
        if (idade >= 20 && idade <= 40) {
            if (p2040 == 1) {
                printf("Pessoas entre 20 e 40 anos: \n");
                p2040 = 0;
            }
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);
            printf("Data de nascimento: %d/%d/%d\n\n", dia, mes, ano);
            cont++;
        }
    }
    printf("Quantidade de pessoas entre 20 e 40 anos: %d", cont);
}