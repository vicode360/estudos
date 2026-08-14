#include <stdio.h>
#include <stdlib.h>
#include "arvbin.h"

int main() {
    int x, esc2;
    TreeNode* A;
    FILE* arq;
    arq = fopen ("arq.txt", "rt");
    int loop = 0;
    int esc;
    do {
        menu();
        scanf("%d", &esc);
        switch (esc) {
            case 1:
                clear();
                A = LerArvore(arq);
                break;
            case 2:
                clear();
                menu2();
                scanf("%d", &esc2);
                switch (esc2) {
                    case 1:
                        clear();
                        pre_order(A);
                        break;
                    case 2:
                        clear();
                        in_order(A);
                        break;
                    case 3:
                        clear();
                        post_order(A);
                        break;
                }
                break;
            case 3:
                clear();
                printf("digite o numero: ");
                scanf("%d", &x);
                if (verifyx(A, x)) {
                    printf("%d existe na arvore\n", x);
                }else {
                    printf("%d nao existe na arvore\n", x);
                }
                break;
            default:
                break;
        }
    }while (loop == 0);
}

