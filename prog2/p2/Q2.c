// implemente uma arvore binaria atraves
// de uma struct chamada TreeNode, contendo
// um valor inteiro, sua frequencia,
// e os ponteiros para as sub-avores da esquerda e direita,
// escreva as funcoes:
//
// free_tree(T): libera toda a memoria alocada para a arvore binaria raiz T
// huffman_tree(L): recebe uma lista encadeada L e cria uma arvore binaria
// aplicando o seguinte algoritmo:
//     para cada elemento da lista L crie um no da arvore binaria
// com os mesmos dados (valor e frequencia) e sem filhos e o adicione
// a uma fila de prioridadde F, onde os elementos com menor frequencia
// tem prioridade maior. utilize a interface dada pela lib
// priority_queue.h
// equanto a fila de prioridade F nao estiver vazias:
//     retire os proximos dois nos da fila ( se houver apenas um no entao a
// arvore ta completa, retorne esse no como raiz)
// crie um novo no da arvore com frequencia iguadl a soma
// das frequencias dos nos removidos, e esses nos sendo seus filhos
// e adicione esse novo no a fila F


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int frequency;
    struct Node* next;
} Node;