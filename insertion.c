#include<stdio.h>
int main()
{ int i,j,key;
  const int n;
  printf("\nEnter no. of elements:");
  scanf("%d",&n);
  int a[n];
  printf("\nEnter elements:");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=1;i<n;i++)
  { key=a[i];
    for(j=i-1;j>=0,a[j]>key;j--)
    { 
         a[j+1]=a[j];
    }
    a[j+1]=key;
  }
  printf("\nSorted array:");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}
