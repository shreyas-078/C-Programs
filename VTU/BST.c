#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} NODE;

NODE *root = NULL;

NODE *create_tree(NODE *, int);
void search(NODE *, int);
void preorder(NODE *);
void inorder(NODE *);
void postorder(NODE *);

int main(void)
{
  int ch;
  while (1)
  {
    printf("\nBST IMPLEMENTATION \n");
    printf("1. Create BST \n");
    printf("2. Search \n");
    printf("3. Inorder Traversal \n");
    printf("4. Preorder Traversal \n");
    printf("5. Postorder Traversal \n");
    printf("6. Exit \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
    int n = 0;
    int target = 0;
    switch (ch)
    {
    case 1:
      printf("Enter number of nodes \n");
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        int data = 0;
        printf("Enter element \n");
        scanf("%d", &data);
        root = create_tree(root, data);
      }
      break;
    case 2:
      printf("Enter element to search \n");
      scanf("%d", &target);
      search(root, target);
    case 3:
      inorder(root);
      break;
    case 4:
      preorder(root);
      break;
    case 5:
      postorder(root);
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid Choice \n");
    }
  }
}

NODE *create_tree(NODE *root, int data)
{
  if (root == NULL)
  {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }
  else if (data > root->data)
  {
    root->right = create_tree(root->right, data);
  }
  else if (data < root->data)
  {
    root->left = create_tree(root->left, data);
  }
  return root;
}

void search(NODE *root, int target)
{
  if (root == NULL)
  {
    printf("Target Not found \n");
    return;
  }
  if (root->data == target)
  {
    printf("Target Found! \n");
    return;
  }
  else if (root->data > target)
  {
    search(root->left, target);
  }
  else if (root->data < target)
  {
    search(root->right, target);
  }
}

void preorder(NODE *root)
{
  if (root == NULL)
    return;
  printf("%d \t", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(NODE *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d \t", root->data);
  inorder(root->right);
}

void postorder(NODE *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d \t", root->data);
}