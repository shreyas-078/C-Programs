#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} NODE;

NODE *root = NULL;

NODE *create_tree(NODE *root, int element)
{
  if (root == NULL)
  {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = element;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
  }
  else if (root->data > element)
  {
    root->left = create_tree(root->left, element);
  }
  else if (root->data < element)
  {
    root->right = create_tree(root->right, element);
  }
  else if (root->data == element)
  {
    printf("Cannot insert \n");
  }
  return root;
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

void search(NODE *root, int target)
{
  if (root == NULL)
  {
    printf("Element not found \n");
  }
  else if (root->data == target)
  {
    printf("Target found \n");
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

int main()
{
  int ch;
  int n;
  int ele;
  while (1)
  {
    printf("\n1. Create Tree \n");
    printf("2. Search \n");
    printf("3. Preorder Traversal \n");
    printf("4. Inorder Traversal\n");
    printf("5. Postorder Traversal \n");
    printf("6. Exit \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      root = NULL;
      printf("Enter number of nodes \n");
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        int ele;
        printf("Enter data: \n");
        scanf("%d", &ele);
        root = create_tree(root, ele);
      }
      break;
    case 2:
      printf("Enter element to search: \n");
      scanf("%d", &ele);
      search(root, ele);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      inorder(root);
      break;
    case 5:
      postorder(root);
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid Choice! \n");
    }
  }
  return 0;
}