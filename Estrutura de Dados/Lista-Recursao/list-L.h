#ifndef ESTUDOS_LIST_L_H
#define ESTUDOS_LIST_L_H
#include <stdlib.h>

typedef struct List {
    int info;
    struct list* next;
} List;

// 1: adicionar elemento na lista comeco
// 2: inserir um item ordenamente numa lista
// 3: remover um elemento da lista
// 4: contar numero de ocorrencias de um elemento x na lista
// 5: somar os elementos da lista
// 6: some 1 unidade em cada elemento impar da lista

List make_node(List L, int x) {
    List L2 = malloc(sizeof(List));
    L2->info = x;
    L2->next = L;
    return L2;
}

List add_ord_node(List L, int x) {
    if (L == NULL) {
        List tmp = malloc(sizeof(List));
        tmp->info = x;
        tmp->next = NULL;
        return tmp;
    }
    if (L->info <= x) {
        return make_node(L, x);
    }
    L->next = add_ord_node(L->next, x);
}

List remove_node(List L, int x) {
    if (L == NULL) {
        return NULL;
     }
    if (L->info == x) {
        List LNext = L->next;
        free(L);
        return LNext;
    }
    L->next = remove_node(L->next, x);
    return L;
}

int node_frequency(List L, int x) {
    if (L == NULL) {
        return 0;
    }
    if (L->info == x) {
        return 1 + node_frequency(L->next, x);
    }
    return node_frequency(L->next, x);
}

int list_adder(List L) {
    if (L == NULL) {
        return 0;
    }
    return L->info + list_adder(L->next);
}




#endif //ESTUDOS_LIST_L_H
