#include <stdio.h>
#include <stdlib.h>
void dijkstras(int a[10][10],int n,int source,int distance[10])
{
 int i,j,visited[10],min,v,count=1;
 for(i=1;i<=n;i++)
 {
     visited[i]=0;
     distance[i]=a[source][i];
 }
 visited[source]=1;
 distance[source]=0;
 while(count<n)
 {
     min=999;
     for(i=1;i<=n;i++)
        if(distance[i]<min && visited[i]==0)
     {
         min=distance[i];
         v=i;

     }
     visited[v]=1;
     count++;
     for(i=1;i<=n;i++)
        if(distance[i]>distance[v]+a[v][i] && visited[i]==0)
     distance[i]=distance[v]+a[v][i];
 }

}
int main()
{
    int n,i,j,a[10][10],source,distance[10];
    printf("\n read number of vertices:");
    scanf("%d",&n);
    printf("\n read the cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=999;
        }
    }
    printf("\n read source vertex:");
    scanf("%d",&source);
    dijkstras(a,n,source,distance);
    for(i=1;i<=n;i++)
    {
        if(source!=i)
            printf("\n the shortest path from %d to %d is %d",source,i,distance[i]);

    }
    return 0;
}
