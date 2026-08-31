#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

// Arvore AVL -> Adelson, Velsky, Landis
//
// - Arvores binarias.  | ABB
// - Ordenadas          |
//    elementos menores - esq, maiores - direita
// - Balanceadas
//    estar bem distribuido
//      diferenca de altura da subarv dir e esq <= 1
//
//  Rotacao à dir.
//    Seja p o nó desbalanceado
//      b = p->esq;
//      p->esq = b->dir;
//      b->dir = p;
//      return b;
//
// Rotacao à esq.
//  b = p->dir;
//  p->dir = b->esq;
//  b->esq = p;
//  return b;
//
//

int main(){

}
