#include <stdio.h>
#include <stdlib.h>

#include "arvorebinaria.h"

int main() {
    TreeNode* A = make_node(65);
    TreeNode* B = make_node(66);
    TreeNode* C = make_node(67);
    TreeNode* D = make_node(68);
    TreeNode* E = make_node(69);
    A->left = B;
    A->right = C;
    C->left = D;
    C->right = E;

    pre_order(A);
    printf("\n");
    in_order(A);
    printf("\n");
    post_order(A);


    free(A);
    free(B);
    free(C);
    free(D);
    free(E);

}
