#include "arvbin.h"

int main() {
    int x, esc, esc2;
    TreeNode* A;
    FILE* fptr;
    fptr = fopen("arq.txt", "r");
    int loop = 0;
    do {
        menu();
        scanf("%d", &esc);
        switch (esc) {
            case 1:
                clear();
                A = LerArvore(fptr);
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
                    case 4:
                        clear();
                        level_order(A);
                        printf("\n");
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
                clear();
                if (is_ordered(A)) {
                    printf("A arvore esta ordenada\n");
                } else {
                    printf("A arvore nao esta ordenada\n");
                }
                break;
            case 7:
                clear();
                if (is_complete_tree(A)) {
                    printf("A arvore esta completa\n");
                } else {
                    printf("A arvore nao esta completa\n");
                }
                break;
            case 8:
                clear();
                printf("escolha um valor para x: ");
                scanf("%d", &x);
                int level = print_level_x(A, x);
                if (level == -1) {
                    printf("%d nao existe na arvore\n", x);
                } else {
                    printf("%d esta no nivel %d\n", x, level);
                }
                break;
            case 9:
                free_tree(A);
                loop = 1;
                break;
            default:
                break;
        }
    }while (loop == 0);
}

