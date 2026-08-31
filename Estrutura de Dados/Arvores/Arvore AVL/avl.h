#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {

  int data;
  struct TreeNode* left;
  struct TreeNode* right;

} TreeNode;


TreeNode* create_node(int x){
  TreeNode* a = malloc(sizeof(TreeNode));
  a->data = x;
  a->left = NULL;
  a->right = NULL;
  return a;
}

TreeNode* insert(TreeNode* node, int x){
  if(node == NULL){
    return create_node(x);
  }
  if( x < node->data){
    node->left = insert(node->left, x);
  }
  if( x > node->data){
    node->right = insert(node->right, x);
  }
  return node;
}
