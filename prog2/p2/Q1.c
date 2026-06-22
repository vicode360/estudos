#include <stdio.h>
#include <stdlib.h>

// implementar uma lista encadeada
// que armazena valores inteiros unicos
// e conta a frequencia de cada valor
// (qtdade de vezes q foi inserido)

// add_value(L, x) se o valor x nao estiver na lista L
// adicione na lista um novo no,
// contendo o valor o valor de x e frequencia igual a 1
// se o valor ja estiver na lista, incremente
// o campo de frequencia do no correspondente, retorne um ponteiro
// para o inicio da lista aspos a alteracao

//free_list(L): libera toda a memoria alocada para a lista L

typedef struct Node {
    int value;
    int frequency;
    struct Node* next;
} Node;

Node* add_value(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == x) {
            current->frequency++;
            return head;
        }
        current=current->next;
    }
    return new_node(head);
}

Node* new_node(Node* head, int x) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = x;
    new_node->frequency = 1;
    new_node->next = head;
    return new_head;
}

void free_list(Node* head) {
    if (head == NULL) {
        return;
    }
  free_list(head->next);
    free(head);
}
