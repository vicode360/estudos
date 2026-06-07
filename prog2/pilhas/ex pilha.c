#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct {
    int vector[MAXSIZE];
    int top;
}Stack;

void push(int valor, Stack *stack) {

    //checar
    if (stack->top < MAXSIZE) {
        //push
        stack->vector[stack->top++] = valor;
    }else {
        printf("stack overflow\n");
    }
}

void pop(Stack *stack) {
    if (stack->top > 0) {
        stack->top--;
        printf("elemento retirado: %d\n", stack->vector[stack->top]);
    }
    else {
        printf("stack underflow\n");
    }
}

int ischeia(Stack *stack) {
    if (stack->top >= MAXSIZE) return 1;
    else return 0;
}

int isvazia(Stack *stack) {
    if (stack->top == 0) return 0;
    else return 1;
}

void imprime(Stack *stack) {
    int i;
    int j = stack->top;
    for (i = stack->top - 1; i >= 0; i--) {
        printf("%d <- elemento %d \n", stack->vector[i], j);
        j--;
    }
}

void remover(int elemento, Stack *stack) {
    if (elemento == stack->top) {
        pop(stack);
        return;
    }
    stack->top--;
    int valor_desempilhado = stack->vector[stack->top];
    remover(elemento, stack);
    push(valor_desempilhado, stack);
}

int main() {
    char opcao;
    Stack s;
    s.top = 0;

    do{
        printf("Escolha uma opção: \n a: adiciona um elemento \n r: remove um elemento \n s: exibe elementos\n x: Sair\n");
        scanf(" %c", &opcao);
        switch (opcao) {
            case 'a':
                int valor;
                printf("Digite um valor:");
                scanf(" %d", &valor);
                push(valor, &s);
                printf("\n");
                break;

            case 's':
                imprime(&s);
                printf("\n");
                break;

            case 'r':
                int ele;
                printf("Qual elemento deseja retirar? \n");
                imprime(&s);
                scanf(" %d", &ele);
                remover(ele, &s);
                break;
            case 'x':
                break;

            default:
                break;
        }
    }while (opcao != 'x');
}