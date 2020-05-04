#include<stdio.h>
const int m;
int temp;
void heapify(int x[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && x[l] > x[largest])
        largest = l;
    if (r < n && x[r] > x[largest])
        largest = r;
    if (largest != i)
    {
        temp=x[i];
        x[i]=x[largest];
        x[largest]=temp;
        heapify(x, n, largest);
    }
}
void heapsort(int x[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(x, n, i);
 
    
    for (int i=n-1; i>=0; i--)
    {
        temp=x[0];
        x[0]=x[i];
        x[i]=temp;
        heapify(x, i, 0);
    }
}
int main()
{ 
  int i;
  printf("\nEnter no. of elements:");
  scanf("%d",&m);
  int x[m];
  printf("\nEnter elements:");
  for(i=0;i<m;i++)
    scanf("%d",&x[i]);
  heapsort(x,m);
  printf("\nSorted array:");
  for(i=0;i<m;i++)
    printf("%d ",x[i]); 
  return 0;
}     

