#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void clear() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

typedef struct TreeNode {
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

TreeNode* read_tree(FILE* arq){
  char c;
  int num;
  
  fscanf(arq, " %c", &c); //ler o '('
  fscanf(arq, " %d", &num); // ler a raiz
  
  if (num == -1){
     fscanf(arq, " %c", &c);
        return NULL;
    }
    TreeNode* a = malloc(sizeof(TreeNode));
    a->data = num;
    a->left = LerArvore(arq); //Subesq;
    a->right= LerArvore(arq); //Subdir;
    fscanf(arq, " %c", &c); // ler ')';
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

int print_level_is_x(TreeNode* root, int x) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == x) {
        return 0;
    }

    int left_level = print_level_is_x(root->left, x);
    if (left_level != -1) {
        return left_level + 1;
    }

    int right_level = print_level_is_x(root->right, x);
    if (right_level != -1) {
        return right_level + 1;
    }

    return -1;
}

int verifyx(TreeNode* arq, int x) {
    if (arq == NULL) {
        return false;
    }
    if (x == arq->data) {
        return true;
    }
    if(x < arq->data) {
        return verifyx(arq->left, x);
    }else {
        return verifyx(arq->right, x);
    }
}

int altura(TreeNode* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int altEsq = altura(raiz->left);
    int altDir = altura(raiz->right);

    return (altEsq > altDir ? altEsq : altDir) + 1;
}

void imprimirNivel(TreeNode* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }
    if (nivel == 1) {
        printf("%d ", raiz->data);
    } else if (nivel > 1) {
        imprimirNivel(raiz->left, nivel - 1);
        imprimirNivel(raiz->right, nivel - 1);
    }
}

void emLarguraRecursivo(TreeNode* raiz) {
    int h = altura(raiz);
    for (int i = 1; i <= h; i++) {
        imprimirNivel(raiz, i);
    }
    printf("\n");
}

void print_small_x_leaf(TreeNode* arq, int x){
  if (arq == NULL){
    return;
  }
  if(arq->left == NULL && arq->right == NULL){
    if(arq->data < x){
        printf("%d ", arq->data);
    }
  }

  print_small_x_leaf(arq->left, x);
  if(arq->data < x){
  print_small_x_leaf(arq->right, x);
  }
}

TreeNode* insert(TreeNode* a, int x){
  if(a == NULL){
    a = malloc(sizeof(TreeNode));
    a->data = x;
    a->left = NULL;
    a->right = NULL;
  }
  else if(x <= a->data){
    a->left = insert(a->left, x);
  }
  else{
    a->right = insert(a->right, x);
  }
  return a;
}

TreeNode* remove(TreeNode* a, int x) {
    if (a == NULL) {
        return NULL;
    }
    // procurar o no
    if (x < a->data) {
        a->left = remove(a->left, x);
    } else if (x > a->data) {
        a->right = remove(a->right, x);
    } else {
        // 3 casos:

        // caso 1: no folha (sem filhos)
        if (a->left == NULL && a->right == NULL) {
            free(a);
            return NULL;
        }
        // caso 2: apenas 1 filho (right)
        else if (a->left == NULL) {
            TreeNode* aux = a->right;
            free(a);
            return aux;
        }
        // caso 2: apenas 1 filho (left)
        else if (a->right == NULL) {
            TreeNode* aux = a->left;
            free(a);
            return aux;
        }
        // caso 3: possui 2 filhos
        else {
            TreeNode* aux = a->left;
            while (aux->right != NULL) {
                aux = aux->right;
            }
            a->data = aux->data;
            a->left = remove(a->left, aux->data);
        }
    }
    return a;
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
    printf("| 4- imprimir o nivel que esta x    |\n");
    printf("| 5- Imprimir folhas menor que x    |\n");
    printf("| 6- inserir no x na arvore.        |\n");
    printf("| 7- remover no x na arvore.        |\n");
    printf("| 8- Sair.                          |\n");
    printf("|___________________________________|\n");
    printf("-> ");
}

void menu2() {
    printf("|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n");
    printf("| 1- Pré-ordem    |\n");
    printf("| 2- Em-ordem     |\n");
    printf("| 3- Pós-ordem    |\n");
    printf("| 4- Largura      |\n");
    printf("|_________________|\n");
    printf("-> ");
}
