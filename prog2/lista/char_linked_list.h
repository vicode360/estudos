#ifndef ESTUDOS_CHAR_LINKED_LIST_H
#define ESTUDOS_CHAR_LINKED_LIST_H

#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

static void printnodes(Node* head) {
    for (Node* p = head; p != NULL; p = p->next)
        printf("%c ", p->data);
}

// criar um no dinamicamente

static Node* new_node(char c) {
    Node* node = malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    return node;
}

// inserir item na frente da lista

static Node* push_front(Node* head, char c) {
    Node* new_head = new_node(c);
    new_head->next = head;
    return new_head;
}

// remover item da frente da lista

static Node* pop_front(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* new_head = head->next;
    free(head);
    return new_head;
}


// buscar no
static Node* find_node(Node* head, char c) {
    for (Node* n = head; n != NULL; n = n->next)
        if (c == n->data)
            return n;
    return NULL;
}

// inserir apos elemento

static void push_after(Node* node, char c) {
    if (node != NULL) {
        Node* n = new_node(c);
        n->next = node->next;
        node->next = n;
    }

}






#endif //ESTUDOS_CHAR_LINKED_LIST_H
