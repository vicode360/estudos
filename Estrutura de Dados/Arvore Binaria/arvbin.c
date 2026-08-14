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
            case 4:
                clear();
                x = count_tree(A);
                printf("Sua arvore tem %d elementos\n", x);
                break;
            case 5:
                clear();
                print_leaf_nodes(A);
                printf("\n");
                break;
            case 6:
                loop = 1;
                break;
            default:
                break;
        }
    }while (loop == 0);
}

