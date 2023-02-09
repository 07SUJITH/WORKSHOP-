#include <stdio.h>
#include <stdlib.h>

int graph[20][20],visited[20],q[20];
int n, front=-1,rear=-1; 

void bfs(int start){
    front=rear=0;
    q[rear]=start;
    visited[start]=1;
    printf("%d -> ",start);
    while(front<=rear){
        for(int i=0;i<n;i++)
            if(graph[start][i] && !visited[i]){
                q[++rear]=i;
                visited[i]=1;
                printf("%d -> ",i);
            }
        start=q[++front];
    }
}

void dfs(int start) {
  printf("%d -> ", start);
  visited[start] = 1; 
  for (int i = 0; i < n; i++) 
        if (graph[start][i] && !visited[i])
            dfs(i);
}

int main() {
  
  int start;
  printf("Enter the number of vertex: ");
  scanf("%d", &n);
  printf("Enter the adjacency matrix: \n");
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) 
         scanf("%d", &graph[i][j]);

  printf("Enter the start vertex: ");
  scanf("%d", &start);
  printf("\nDFS : ");
  dfs(start);

  for(int i=0;i<n;i++)
      visited[i]=0;

  printf("\nBFS : ");
  bfs(start);
  return 0;
}
