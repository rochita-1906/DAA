#include <stdio.h>
#include <stdlib.h>
 int count;
 void merge(int A[10],int l,int m,int r)
 {
     int i,j,k,B[10];
     i=l;
     j=m+1;
     k=l;
     while (i<=m && j<=r)
     {
         count=count+1;
         if(A[i]<A[j])
            B[k++]=A[i++];
         else
            B[k++]=A[j++];
     }
     while (i<=m)
        B[k++]=A[i++];
     while (j<=r)
        B[k++]=A[j++];
     for(i=l;i<=r;i++)
        A[i]=B[i];
 }
 void mergesort(int A[10],int l,int r)
 {
     int m;
     if(l<r)
     {
         m=(l+r)/2;
         mergesort(A,l,m);
         mergesort(A,m+1,r);
         merge(A,l,m,r);
     }
 }
 int main()
 {
     int i,n,A[10];
     printf("\n read array size:");
     scanf("%d",&n);
     printf("\n read array elements\n");
     for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    mergesort(A,0,n-1);
    printf("\n sorted elements are\n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\n total number of comparision =%d",count);
    return 0;
     }
