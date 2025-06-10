#include <stdio.h>

int main(){
    int input;
    printf("escreva um numero: ");
    scanf(" %d", &input);
    printf("tabuada do %d\n", input);
    int output;
    int loop = 1;

    while (loop <= 10){  // ate onde vai sua tabuada
        output = input * loop;
        printf("%d x %d = %d\n", input, loop, output);
        loop++;
    }
}