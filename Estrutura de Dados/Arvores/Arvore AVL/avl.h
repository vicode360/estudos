#ifndef AVL_H
#define AVL_H

#include <stdio.h>

typedef struct AVL {
    int info;
    int FB;
    struct AVL *esq;
    struct AVL *dir;
} AVL;

AVL *LerAVL(FILE *arq);
void AjustarFB(AVL *a);
int altura(const AVL *a);
void pre_order(const AVL *a);
void in_order(const AVL *a);
void post_order(const AVL *a);
void emLarguraRecursivo(const AVL *a);
int verifyx(const AVL *a, int x);
int print_level_is_x(const AVL *a, int x);
void print_small_x_leaf(const AVL *a, int x);
AVL *insert(AVL *a, int x);
AVL *remove_avl(AVL *a, int x);
void free_tree(AVL *a);
void menu(void);
void menu2(void);

#endif
