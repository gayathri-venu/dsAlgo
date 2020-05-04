#include<stdio.h>
int main()
{ int i,j,small;
  const int n;
  printf("\nEnter no. of elements:");
  scanf("%d",&n);
  int a[n];
  printf("\nEnter elements:");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<=n-1;i++)
  { small=i;
    for(j=i+1;j<n;j++)
    { if(a[j]<a[small]) 
        small=j;
     }
    int temp=a[i];
    a[i]=a[small];
    a[small]=temp;
   }
  printf("\nSorted array:");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}
