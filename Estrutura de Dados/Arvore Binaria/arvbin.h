#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool emptyQueue(Queue* q){
    return q->front == NULL;
}

void enqueue(Queue* q, TreeNode* node){
    QueueNode* newNode = malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if(emptyQueue(q)) {
        q->front = newNode;
        q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

TreeNode* dequeue(Queue* q){
    if (emptyQueue(q)) return NULL;
    QueueNode* temp = q->front;
    TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}

void clear() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

TreeNode* LerArvore(FILE* arq) {
    char c;
    int num;

    fscanf(arq, "%c", &c); // ler '('
    fscanf(arq, "%d", &num); // ler a raiz

    if (num == -1) {
        fscanf(arq, "%c", &c);
        return NULL;
    }
    TreeNode* a = malloc(sizeof(TreeNode));
    a->data = num;
    a->left = LerArvore(arq); //Subesq;
    a->right = LerArvore(arq); //Subdir;
    fscanf(arq, "%c", &c); // ler ')';
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

int verifyx(TreeNode* arq, int x) {
    if (arq == NULL) {
        return false;
    }
    if (x == arq->data) {
        return true;
    }
    return verifyx(arq->left, x) || verifyx(arq->right, x);
}


int count_tree(TreeNode* arq) {
    if (arq == NULL) {
        return 0;
    }
    return 1 + count_tree(arq->left) + count_tree(arq->right);
}

void print_leaf_nodes(TreeNode* arq) {
    if (arq == NULL) {
        return;
    }
    if (arq->left == NULL && arq->right == NULL) {
        printf("%d ", arq->data);
    }
    print_leaf_nodes(arq->left);
    print_leaf_nodes(arq->right);
}

void print_tree_level(TreeNode* arq, int qnt, int level) {
    if (arq != NULL) {
        if (qnt == level) {
            printf("%d ", arq->data);
        }
        else {
            print_tree_level(arq->left, qnt+1, level);
            print_tree_level(arq->right, qnt+1, level);
        }
    }
}

int count_tree_level(TreeNode* arq, int count, int l) {
    if (arq == NULL) {
        return 0;
    }
    if (count == l) {
        return 1;
    }
    return count_tree_level(arq->left, count+1, l) + count_tree_level(arq->right, count+1, l);
}


// full tree: total de nos =  2^h - 1.
// ou ultimos nos = 2^h-1.


//(adicionar imprimir arvore em largura
// verificar se uma arvore esta ordenada
//verificar se a arvore e completa
//imprimir o nivel a qual o no x pertence

void level_order(TreeNode* root){
    if (root == NULL) {
        return;
    }
    Queue* q = createQueue();
    enqueue(q, root);

    while(!emptyQueue(q)){
        TreeNode* current = dequeue(q);
        printf("%d ", current->data);
        if(current->left != NULL){
            enqueue(q, current->left);
        }
        if(current->right != NULL){
            enqueue(q, current->right);
        }
    }

    free(q);
}


int height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh) {
        return lh + 1;
    }
    return rh + 1;
}

bool is_ordered_recursive(TreeNode* root, long long min_value, long long max_value) {
    if (root == NULL) {
        return true;
    }

    if ((long long)root->data < min_value || (long long)root->data > max_value) {
        return false;
    }

    return is_ordered_recursive(root->left, min_value, (long long)root->data - 1) &&
           is_ordered_recursive(root->right, (long long)root->data + 1, max_value);
}

bool is_ordered(TreeNode* root) {
    return is_ordered_recursive(root, LLONG_MIN, LLONG_MAX);
}

bool is_complete_tree(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    Queue* q = createQueue();
    enqueue(q, root);
    bool found_null = false;

    while (!emptyQueue(q)) {
        TreeNode* current = dequeue(q);

        if (current == NULL) {
            found_null = true;
            continue;
        }

        if (found_null) {
            free(q);
            return false;
        }

        enqueue(q, current->left);
        enqueue(q, current->right);
    }

    free(q);
    return true;
}

int print_level_x(TreeNode* root, int x) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == x) {
        return 0;
    }

    int left_level = print_level_x(root->left, x);
    if (left_level != -1) {
        return left_level + 1;
    }

    int right_level = print_level_x(root->right, x);
    if (right_level != -1) {
        return right_level + 1;
    }

    return -1;
}

bool verifygap(TreeNode* root, int current, int total){
    if (root == NULL) return true;
    if (current >= total) return false;
    return verifygap(root->left, 2 * current + 1, total) &&
    verifygap(root->right, 2 * current, total);
}


void free_tree(TreeNode* arq) {
    if (arq != NULL) {
        free_tree(arq->left);
        free_tree(arq->right);
        free(arq);
    }
}

void print_between_x_y(TreeNode* root, int x, int y) {
    if (root != NULL) {
        if(root->data < x){
            print_between_x_y(root->right, x, y);

        }
        else if(root->data > y){
            print_between_x_y(root->left, x, y);
        }
        else if(root->data == y){
            printf("%d ", root->data);
            print_between_x_y(root->left, x, y);
        }
        else{
            printf("%d ", root->data),
            print_between_x_y(root->left, x, y);
            print_between_x_y(root->right, x, y);
        }
    }
}

void print_outside_x_y(TreeNode* root, int x, int y){
    if (root != NULL){
        if (root->data < x || root->data > y){
            printf("%d ", root->data);
        }
        print_outside_x_y(root->left, x, y);
        print_outside_x_y(root->right, x, y);
    }   
}

void menu() {
    printf("|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n");
    printf("| 1- Ler uma arvore de um arquivo   |\n");
    printf("| 2- Imprimir a árvore              |\n");
    printf("| 3- Verificar se existe x elemento |\n");
    printf("| 4- Contar número de elementos     |\n");
    printf("| 5- Imprimir os nós folhas         |\n");
    printf("| 6- verificar se esta ordenada     |\n");
    printf("| 7- verificar se esta completa     |\n");
    printf("| 8- imprimir o nivel que esta x    |\n");
    printf("| 9- Sair                           |\n");
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
