#include "abb.h"



//
//  Sao arvores binarias
//  Sao ordenadas
//



int main(){
  int esc, x, esc2;
  TreeNode *A = NULL;
  FILE *fptr;
  fptr = fopen("arq.txt", "r");
  int loop = 0;
  do {
    menu();
    scanf("%d", &esc);
    switch(esc){
      case 1:
      clear();
      A = read_tree(fptr);
      break;
    case 2:
      clear();
      menu2();
      scanf("%d", &esc2);
      switch (esc2) {
      case 1:
        clear();
        pre_order(A);
        break;
      case 2:
        clear();
        in_order(A);
        break;
      case 3:
        clear();
        post_order(A);
        break;
      case 4:
        clear();
        emLarguraRecursivo(A);
        printf("\n");
        break;
      }
      break;
    case 3:
      clear();
      printf("digite o numero: ");
      scanf("%d", &x);
      if (verifyx(A, x)) {
        printf("%d existe na arvore\n", x);
      } else {
        printf("%d nao existe na arvore\n", x);
      }
      break;
    case 4:
      clear();
      printf("escolha um valor para x: ");
      scanf("%d", &x);
      int level = print_level_is_x(A, x);
      if (level == -1) {
        printf("%d nao existe na arvore\n", x);
      } else {
        printf("%d esta no nivel %d\n", x, level);
      }
      break;
    case 5:
      clear();
      printf("Digite o valor de X: ");
      scanf("%d", &x);
      print_small_x_leaf(A, x);
      printf("\n");
      break;
    case 6:
      clear();
      printf("Digite o numero a inserir: ");
      scanf("%d", &x);
      A = insert(A, x);
      break;
    case 7:
      clear();
      printf("Digite o numero a remover: ");
      scanf("%d", &x);
      A = remove(A, x);
      break;
    case 8:
      free_tree(A);
      loop = 1;
      break;
    default:
      break;
    }
}while(loop == 0);



}
