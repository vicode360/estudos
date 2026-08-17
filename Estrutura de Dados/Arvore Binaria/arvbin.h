#ifndef ESTUDOS_ARVBIN_H
#define ESTUDOS_ARVBIN_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void clear() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

TreeNode* LerArvore(FILE* arq) {
    char c;
    int num;

    fscanf(arq, "%c", &c); // ler '('
    fscanf(arq, "%d", &num); // ler a raiz

    if (num == -1) {
        fscanf(arq, "%c", &c);
        return NULL;
    }
    TreeNode* a = malloc(sizeof(TreeNode));
    a->data = num;
    a->left = LerArvore(arq); //Subesq;
    a->right = LerArvore(arq); //Subdir;
    fscanf(arq, "%c", &c); // ler ')';
    return a;
}

void pre_order(TreeNode* arq) {
    if (arq != NULL) {
        printf("%d\n", arq->data);
        pre_order(arq->left);
        pre_order(arq->right);
    }
}
void in_order(TreeNode* arq) {
    if (arq != NULL) {
        in_order(arq->left);
        printf("%d\n", arq->data);
        in_order(arq->right);
    }
}

void post_order(TreeNode* arq) {
    if (arq != NULL) {
        post_order(arq->left);
        post_order(arq->right);
        printf("%d\n", arq->data);
    }
}

int verifyx(TreeNode* arq, int x) {
    if (arq == NULL) {
        return false;
    }
    if (x == arq->data) {
        return true;
    }
    return verifyx(arq->left, x) || verifyx(arq->right, x);
}


int count_tree(TreeNode* arq) {
    if (arq == NULL) {
        return 0;
    }
    return 1 + count_tree(arq->left) + count_tree(arq->right);
}

void print_leaf_nodes(TreeNode* arq) {
    if (arq == NULL) {
        return;
    }
    if (arq->left == NULL && arq->right == NULL) {
        printf("%d ", arq->data);
    }
    print_leaf_nodes(arq->left);
    print_leaf_nodes(arq->right);
}

void free_tree(TreeNode* arq) {
    if (arq != NULL) {
        free_tree(arq->left);
        free_tree(arq->right);
        free(arq);
    }
}


void menu() {
    printf("|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n");
    printf("| 1- Ler uma arvore de um arquivo   |\n");
    printf("| 2- Imprimir a árvore              |\n");
    printf("| 3- Verificar se existe x elemento |\n");
    printf("| 4- Contar número de elementos     |\n");
    printf("| 5- Imprimir os nós folhas         |\n");
    printf("| 6- Sair                           |\n");
    printf("|___________________________________|\n");
    printf("-> ");
}

void menu2() {
    printf("|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n");
    printf("| 1- Pré-ordem    |\n");
    printf("| 2- Em-ordem     |\n");
    printf("| 3- Pós-ordem    |\n");
    printf("|_________________|\n");
    printf("-> ");
}



#endif //ESTUDOS_ARVBIN_H
