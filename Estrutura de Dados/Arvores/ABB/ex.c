#include <stddef.h>

typedef struct Tree{
    int data;
    Tree* left;
    Tree* right;
}Tree;

// verificar se a arvore A esta contida na B

int saoiguais(Tree* a, Tree* b){
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    if (a->data == b->data && saoiguais(a->left, b->right) && saoiguais(a->right, b->right)){
    return 1;
    }
    else{
        return 0;
    }
}

int ehsub(Tree* a, Tree* b){
    if (a == NULL) return 1;
    if (b == NULL) return 0;
    if(saoiguais(a, b) == 1) return 1;
    return saoiguais(b->left, a) || saoiguais(b->right, a);
}

// Uma árvore binária de busca (ABB)
// é estritamente binária se todos os nós desta árvore 
// têm 2 filhos (ambos não-nulos) ou nenhum filho (ambos nulos).
// Implemente uma função que verifica se uma ABB é estritamente binária.

int ebinaria (Tree* a){
    if (a==NULL) return 1;
    if (a->left != NULL && a->right != NULL) return 1;
    if (a->left != NULL && a->right != NULL){
        return ebinaria(a->left) && ebinaria(a->right);
    }
    return 0;
}

// implemente uma função que, dados uma árvore binária de busca 
// $a$ e um valor inteiro $x$ ($x$ existe em $a$), retorne o elemento $y$ existente em $a$ mais próximo
// de $x$, tal que $y < x$. Se não existir um número menor que $x$ em $a$, retorne $x$.   

int antecess(Tree* a, int x){
    int y = x;
    while (a != NULL){
        if(a->data < x){
            y = a->data;
            a = a->right;
        }else
        a = a->left;
    }
    return y;
}


// Dada uma árvore binária de busca a, implemente uma função que imprima
// os elementos de a que estão no nível n e que são menores ou iguais a y 
// (n e y são parâmetros de entrada desta função).


void leveless(Tree* a, int n, int y){
    if (a == NULL) return;
    if (n == 0){
        if(a->data <= y){
            printf("%d", a->data);
        }
    }else if(n > 0){
        leveless(a->left, n-1, y);
        leveless(a->right, n-1, y);
    }
}

// Dada uma árvore binária a,
// implemente uma função que retorne a maior
// diferença (em módulo) entre as alturas das
// subárvores esquerda e direita de um nó de a.
// Obs.: Pode supor que a função “Altura” está disponível para uso. 

int maxdiff(Tree* a){
    if (a==NULL) return 0;

    int diff = altura(a->left) - altura(a->right);
    if (diff < 0){
        diff = diff * -1;
    }

    int esq = maxdiff(a->left);
    int dir = maxdiff(a->right);

    int maior = diff;
    if(esq > maior) maior = esq;
    if(dir > maior) maior  = dir;

    return maior;

}


// Dada duas árvores AVL $a$ e $b$, implemente uma função 
// que conte a quantidade de elementos que existem em $a$ e não existem em $b$.

int existe (Tree* a, int n){
    while (a!=NULL){
        if(a->data == n){
            return 1;
        }
        if (a->data > n){
            a = a->left;
        }
        if (a->data < n){
            a = a->right;
        }
    }
    return 0;
}

int existeanb(Tree* a, Tree* b){
    if (a == NULL) return 0;

    int nexiste = !existe(b, a->data);

    return nexiste + existeanb(a->left, b) + existeanb(a->right, b);
}


// Dada uma árvore binária a, implemente uma função que conte o número de folhas por nível de a.

int countleaf(Tree* a, int l) {
    if (a == NULL) return 0;

    if(l == 0){
        if (a->left == NULL && a->right == NULL){
            return 1;
        }
        return 0;
    }
    return countleaf(a->left, l-1) + countleaf(a->right, l-1);
}


// Implemente uma função que verifique se duas árvores AVL $A$ e $B$ possuem os mesmos valores
// (não precisam estar na mesma posição),
// ou seja, se um valor existe em $A$, 
// então este valor também existe em $B$ (e vice-versa).

int existe(Tree* a, int b){
    if (a == NULL) return 0;
    if (a->data == b) return 1;
    if (a->data > b)  return existe(a->left, b);
    if (a->data < b)  return existe(a->right, b);
}

int existeaeb(Tree* a, Tree* b){
    if (a == NULL) return 0;

    int exist = existe(a, b->data);
    return exist + existe(a->left, b->data) + existe(a->right, b->data);


}