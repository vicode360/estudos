#include <stdio.h>

// Arvore Rubro-Negra
//  Propriedades:
//    - ABB
//    - Nós pretos e vermelhos
//    - Raiz preta
//    - NULL é preto
//    - Não existem nós vermelhos consecutivos
//    - Altura Negra: o caminho da raiz até qualquer NULL
//      passa pela mesma quantidade de nós pretos
//

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    char color; // V = Vermelho, P = Preto
}node;


// 1- faca uma funcao que verifique se um elemento x existe na arvore rubro negra (tirar proveito da ordenacao)
int verify_x(node *root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == x) {
        return 1;
    }
    if (x < root->data){
        return verify_x(root->left, x);
    } else {
        return verify_x(root->right, x);
    }
}



// 2- calcule a altura negra de uma arvore rubro negra
// 3- dada uma arvore binaria de busca de nos vermelhos e pretos, verifique se ela tem a propriedade da altura negra (0 ou 1)
// 4- dada uma arvore binaria de busca de nos vermelhos e pretos, verifique se ela possui nos vermelhos consecutivos
//
