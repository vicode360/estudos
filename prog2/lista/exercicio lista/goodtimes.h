#ifndef GOODTIMES_H
#define GOODTIMES_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* make_node(int data, Node* next) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}


static Node* aleatorios(int n) {
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        Node* new_node = malloc(sizeof(Node));
        new_node->data = rand() % 100;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

static void free_list(Node* head) {
    Node* atual = head;
    Node* prox;
    while (atual!= NULL) {
        prox = atual->next;
        free(atual);
        atual = prox;
    }
}

static void print_list(Node* head) {
    for (Node* i = head; i != NULL; i = i->next)
        printf("%d ", i->data);
}

static void print_even(Node* head) {
    for (Node* i = head; i != NULL; i = i->next) {
        if (i->data % 2 == 0) {
            printf("%d ", i->data);
        }
    }
}


int count_nodes(Node* head) {
    int c = 0;
    for (Node* i = head; i != NULL; i = i->next) {
        c++;
    }
    return c;
}

static Node* revert_list(Node* head) {
    Node* new_list = NULL;
    Node* atual = head;
    Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->next;
        atual->next = new_list;
        new_list = atual;
        atual = proximo;
    }
    return new_list;
}


#endif //GOODTIMES_H
