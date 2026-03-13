#include <stdio.h>
#include <stdlib.h>
int topo[10],k;
void dfs(int a[10][10],int n,int visited[10],int source)
{
  int i;
  visited[source]=1;
  for(i=1;i<=n;i++)
  {
      if(visited[i]==0&& a[source][i]==1)
        dfs(a,n,visited,i);
  }
  topo[++k]=source;
}
int main()
{
    int n,a[10][10],i,j,visited[10];
    printf("\n read number of nodes:");
    scanf("%d",&n);
    printf("\n read adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
      if(visited[i]==0)
      {
          dfs(a,n,visited,i);
      }
    }
   printf("\n topological sort is\n");
   for(i=k;i>=1;i--)
        printf("%d\t",topo[i]);
   return 0;
}
