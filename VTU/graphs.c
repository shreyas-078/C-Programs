#include <stdio.h>
#include <stdlib.h>

int adjacency_matrix[10][10], n, m, i, j, source, s[10], b[10], visited[10];

void create_graph()
{
  printf("Enter number of vertices of graph \n");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &adjacency_matrix[i][j]);
    }
  }
}

void bfs()
{
  int q[10], u, front = 0, rear = -1;
  printf("Enter source vertex to check other nodes reachable or not \n");
  scanf("%d", &source);
  q[++rear] = source;
  visited[source] = 1;
  printf("The reachable vertices are: \n");
  while (front <= rear)
  {
    u = q[front++];
    for (i = 1; i <= n; i++)
    {
      if (adjacency_matrix[u][i] == 1 && visited[i] == 0)
      {
        q[++rear] = i;
        visited[i] = 1;
        printf("%d \t", i);
      }
    }
  }
}

void dfs(int source)
{
  int v, top = -1;
  s[++top] = 1;
  b[source] = 1;
  for (v = 1; v <= n; v++)
  {
    if (adjacency_matrix[v][i] == 1 && b[i] == 0)
    {
      printf("%d -> %d \n", source, v);
      dfs(v);
    }
  }
}

int main(void)
{
  int ch;
  while (1)
  {
    printf("GRAPHS!! \n");
    printf("1. Input Adjacency Matrix \n");
    printf("2. BFS \n");
    printf("3. DFS \n");
    printf("4. Exit \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      create_graph();
      break;

    case 2:
      bfs();
      for (i = 1; i <= n; i++)
      {
        if (visited[i] == 0)
        {
          printf("The Vertex %d not reachable \n", i);
        }
      }
      break;

    case 3:
      printf("Enter source vertex to find connectivity: \n");
      scanf("%d", &source);
      dfs(source);
      for (int i = 1; i <= n; i++)
      {
        if (b[i] == 0)
        {
          m = 0;
        }
      }
      if (m == 1)
      {
        printf("Graph is Connected \n");
      }
      else
      {
        printf("Graph is not connected \n");
      }
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid Choice \n");
    }
  }
}