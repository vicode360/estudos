#include <stdio.h>

int main() {
    /*int c = 1;
    int b = 100;
    int z = 0;
    z = (c + b)*100 / 2;
    printf("z = %d \n", z);*/

    int soma = 0;
    for (int i = 1; i <= 100; i++) {
        int soma_ant = soma;
        soma = soma + i;
        printf("%d = %d + %d (quando i = %d)\n", soma, soma_ant, i , i);
    }
}