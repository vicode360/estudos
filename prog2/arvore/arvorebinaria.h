
#ifndef ESTUDOS_ARVOREBINARIA_H
#define ESTUDOS_ARVOREBINARIA_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* make_node(int data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int x) {
    if (root == NULL) {
        return make_node(x);
    }
    if (x < root->data) {
        root->left = insert(root->left, x);
    }
    else if (x > root->data) {
        root->right = insert(root->right, x);
    }
    return root;
}

TreeNode* search(TreeNode* root, int x) {
    if (root == NULL || root->data == x) {
        return root;
    }
    if (x < root->data) {
        root->left = search(root->left, x);
    }
    else if (x > root->data) {
        root->right = search(root->right, x);
    }
}

void pre_order(TreeNode* A) {
    if (A!=NULL) {
        printf("%d ", A->data);
        pre_order(A->left);
        pre_order(A->right);
    }
}

void post_order(TreeNode* A){
    if(A != NULL){
        post_order(A->left);
        post_order(A->right);
        printf("%d ", A->data);
    }
}


void in_order(TreeNode* A) {
    if (A!=NULL) {
     in_order(A->left);
        printf("%d ", A->data);
        in_order(A->right);
    }
}

void free_tree(TreeNode* root) {
    if (root!=NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int soma_total(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + soma_total(root->left) + soma_total(root->right);
}


#endif //ESTUDOS_ARVOREBINARIA_H
