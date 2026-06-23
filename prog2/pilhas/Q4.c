//
// Created by Victor Iorio on 15/06/26.
//


#include <stdio.h>
#include <stdlib.h>


typedef struct Frame {
    int a;
    int b;
    int x;
    int pos;
    struct Frame* next;
}Frame;

Frame* push(int a, int b, Frame* top) {
    Frame* new_top = malloc(sizeof(Frame));
    new_top->next = top;
    new_top->a = a;
    new_top->b = b;
    new_top->x = 0;
    new_top->pos = 0;
    return new_top;
}

Frame* pop(Frame* top) {
    Frame* new_top = top->next;
    free(top);
    return new_top;
}

void f(int a, int b) {
    Frame* top = push(x, NULL);
    while (top) {
        a = top->a;
        b = top->b;
        if (a > b) {
            printf("alfafa %d %d\n", a, b);
            top = pop(top);
        }else{
            if (top->pos == 0) {
                    top->x = rand()%10;
                    printf("chicoria %d\n", a);
                    top->pos++;
                    top = push(a+top->x, b, top);
            }else if (top->pos == 1) {
                printf("beterraba %d\n", b);
                top->pos++;
                top = push(a, b-top->x, top);
            }else if ( top->pos == 2) {
                printf("azeitona %d\n",top->x);
                top = pop(top);
            }
        }
    }
}



Frame* push(TreeNode* node, Frame* top) {
    Frame* new_top = (Frame*)malloc(sizeof(Frame));
    new_top->node = node;
    new_top->pos = 0;
    new_top->next = top;
    return new_top;
}

Frame* pop(Frame* top) {
    if (!top) return NULL;
    Frame* new_top = top->next;
    free(top);
    return new_top;
}

int soma_total_iterativa(TreeNode* root) {
    Frame* top = push(root, NULL);
    int soma = 0;
    while (top) {
        TreeNode* node = top->node;
        if (node == NULL) {
            top = pop(top);
        }
        else {
            if (top->pos == 0) {
                soma += node->data;
                top->pos++;
                top = push(node->left, top);
            }
            else if (top->pos == 1) {
                top->pos++;
                top = push(node->right, top);
            }
            else if (top->pos == 2) {
                top = pop(top);
            }
        }
    }
    return soma;
}


