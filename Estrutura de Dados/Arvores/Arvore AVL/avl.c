#include "avl.h"
#include <stdlib.h>

int altura(const AVL *a) {
    if (a == NULL) return 0;
    int esquerda = altura(a->esq);
    int direita = altura(a->dir);
    return (esquerda > direita ? esquerda : direita) + 1;
}

void AjustarFB(AVL *a) {
    if (a != NULL) {
        AjustarFB(a->esq);
        AjustarFB(a->dir);
        a->FB = altura(a->dir) - altura(a->esq);
    }
}

static AVL *ler_arvore(FILE *arq) {
    char parenteses;
    int num;
    if (fscanf(arq, " %c %d", &parenteses, &num) != 2) return NULL;
    if (num == -1) {
        fscanf(arq, " %c", &parenteses);
        return NULL;
    }
    AVL *a = malloc(sizeof(*a));
    if (a == NULL) return NULL;
    a->info = num;
    a->esq = ler_arvore(arq);
    a->dir = ler_arvore(arq);
    fscanf(arq, " %c", &parenteses);
    a->FB = 0;
    return a;
}

AVL *LerAVL(FILE *arq) {
    if (arq == NULL) return NULL;
    AVL *a = ler_arvore(arq);
    AjustarFB(a);
    return a;
}

void pre_order(const AVL *a) {
    if (a != NULL) {
        printf("%d ", a->info);
        pre_order(a->esq);
        pre_order(a->dir);
    }
}

void in_order(const AVL *a) {
    if (a != NULL) {
        in_order(a->esq);
        printf("%d ", a->info);
        in_order(a->dir);
    }
}

void post_order(const AVL *a) {
    if (a != NULL) {
        post_order(a->esq);
        post_order(a->dir);
        printf("%d ", a->info);
    }
}

static void imprimir_nivel(const AVL *a, int nivel) {
    if (a == NULL) return;
    if (nivel == 1) printf("%d ", a->info);
    else {
        imprimir_nivel(a->esq, nivel - 1);
        imprimir_nivel(a->dir, nivel - 1);
    }
}

void emLarguraRecursivo(const AVL *a) {
    for (int nivel = 1; nivel <= altura(a); nivel++) imprimir_nivel(a, nivel);
}

int verifyx(const AVL *a, int x) {
    if (a == NULL) return 0;
    if (x == a->info) return 1;
    return verifyx(a->esq, x) || verifyx(a->dir, x);
}

int print_level_is_x(const AVL *a, int x) {
    if (a == NULL) return -1;
    if (a->info == x) return 0;
    int nivel_esquerda = print_level_is_x(a->esq, x);
    if (nivel_esquerda != -1) return nivel_esquerda + 1;
    int nivel_direita = print_level_is_x(a->dir, x);
    return nivel_direita == -1 ? -1 : nivel_direita + 1;
}

void print_small_x_leaf(const AVL *a, int x) {
    if (a == NULL) return;
    if (a->esq == NULL && a->dir == NULL && a->info < x) printf("%d ", a->info);
    print_small_x_leaf(a->esq, x);
    print_small_x_leaf(a->dir, x);
}

static void atualizar_fb(AVL *a) {
    if (a != NULL) a->FB = altura(a->dir) - altura(a->esq);
}

static AVL *rotacao_direita(AVL *a) {
    AVL *b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    atualizar_fb(a);
    atualizar_fb(b);
    return b;
}

static AVL *rotacao_esquerda(AVL *a) {
    AVL *b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    atualizar_fb(a);
    atualizar_fb(b);
    return b;
}

static AVL *balancear(AVL *a) {
    atualizar_fb(a);
    if (a->FB < -1) {
        if (a->esq->FB > 0) a->esq = rotacao_esquerda(a->esq);
        return rotacao_direita(a);
    }
    if (a->FB > 1) {
        if (a->dir->FB < 0) a->dir = rotacao_direita(a->dir);
        return rotacao_esquerda(a);
    }
    return a;
}

static AVL *create_node(int x) {
    AVL *a = malloc(sizeof(*a));
    if (a != NULL) {
        a->info = x;
        a->FB = 0;
        a->esq = NULL;
        a->dir = NULL;
    }
    return a;
}

AVL *insert(AVL *a, int x) {
    if (a == NULL) return create_node(x);
    if (x < a->info) a->esq = insert(a->esq, x);
    else if (x > a->info) a->dir = insert(a->dir, x);
    else return a;
    return balancear(a);
}

AVL *remove_avl(AVL *a, int x) {
    if (a == NULL) return NULL;
    if (x < a->info) a->esq = remove_avl(a->esq, x);
    else if (x > a->info) a->dir = remove_avl(a->dir, x);
    else {
        if (a->esq == NULL || a->dir == NULL) {
            AVL *filho = a->esq != NULL ? a->esq : a->dir;
            free(a);
            return filho;
        }
        AVL *sucessor = a->dir;
        while (sucessor->esq != NULL) sucessor = sucessor->esq;
        a->info = sucessor->info;
        a->dir = remove_avl(a->dir, sucessor->info);
    }
    return balancear(a);
}

void free_tree(AVL *a) {
    if (a != NULL) {
        free_tree(a->esq);
        free_tree(a->dir);
        free(a);
    }
}

void menu(void) {
    printf("\n1 - Ler arvore de um arquivo\n2 - Imprimir arvore\n3 - Verificar se x existe\n4 - Imprimir nivel de x\n5 - Imprimir folhas menores que x\n6 - Inserir x\n7 - Remover x\n8 - Sair\nOpcao: ");
}

void menu2(void) {
    printf("\n1 - Pre-ordem\n2 - Em-ordem\n3 - Pos-ordem\n4 - Largura\nOpcao: ");
}

int main(void) {
    int esc, x, esc2;
    AVL *A = NULL;
    FILE *fptr = fopen("arq.txt", "r");
    int loop = 0;

    do {
        menu();
        scanf("%d", &esc);
        switch (esc) {
        case 1:
            if (fptr == NULL) {
                perror("Nao foi possivel abrir arq.txt");
            } else {
                rewind(fptr);
                free_tree(A);
                A = LerAVL(fptr);
            }
            break;
        case 2:
            menu2();
            scanf("%d", &esc2);
            switch (esc2) {
            case 1:
                pre_order(A);
                break;
            case 2:
                in_order(A);
                break;
            case 3:
                post_order(A);
                break;
            case 4:
                emLarguraRecursivo(A);
                break;
            default:
                break;
            }
            printf("\n");
            break;
        case 3:
            printf("digite o numero: ");
            scanf("%d", &x);
            if (verifyx(A, x)) printf("%d existe na arvore\n", x);
            else printf("%d nao existe na arvore\n", x);
            break;
        case 4: {
            int nivel;

            printf("escolha um valor para x: ");
            scanf("%d", &x);
            nivel = print_level_is_x(A, x);
            if (nivel == -1) printf("%d nao existe na arvore\n", x);
            else printf("%d esta no nivel %d\n", x, nivel);
            break;
        }
        case 5:
            printf("Digite o valor de X: ");
            scanf("%d", &x);
            print_small_x_leaf(A, x);
            printf("\n");
            break;
        case 6:
            printf("Digite o numero a inserir: ");
            scanf("%d", &x);
            A = insert(A, x);
            break;
        case 7:
            printf("Digite o numero a remover: ");
            scanf("%d", &x);
            A = remove_avl(A, x);
            break;
        case 8:
            free_tree(A);
            loop = 1;
            break;
        default:
            break;
        }
    } while (loop == 0);

    if (fptr != NULL) fclose(fptr);
    return 0;
}
