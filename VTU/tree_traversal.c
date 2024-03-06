#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int element)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = element;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void display_list_inorder(struct node *node)
{
  if (node == NULL)
    return;

  display_list_inorder(node->left);
  printf("%d \n", node->data);
  display_list_inorder(node->right);
}

void display_list_preorder(struct node *node)
{
  if (node == NULL)
    return;

  printf("%d \n", node->data);
  display_list_preorder(node->left);
  display_list_preorder(node->right);
}

void display_list_postorder(struct node *node)
{
  if (node == NULL)
    return;

  display_list_postorder(node->left);
  display_list_postorder(node->right);
  printf("%d \n", node->data);
}

int main(void)
{
  struct node *root = (struct node *)malloc(sizeof(struct node));
  root->data = 0;
  root->left = create_node(3);
  root->right = create_node(1);
  root->right->right = create_node(2);
  display_list_inorder(root);
  display_list_preorder(root);
  display_list_postorder(root);
}