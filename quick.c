#include<stdio.h>

int partition(int x[],int lb,int ub)
{ int pivot=x[lb];
  int up =ub;
  int down=lb;
  while(down<up)
  {
     while((x[down]<=pivot)&&(down<ub))
        down+=1;
     while(x[up]>pivot)
        up-=1;
     if(down<up)
     {int temp=x[down];
      x[down]=x[up];
      x[up]=temp;
     }
   }
   x[lb]=x[up];
   x[up]=pivot;
   return up;
}
 void quicksort(int x[],int lb, int ub)
{ if(lb>=ub)
     return;
  int j=partition(x,lb,ub);
  quicksort(x,lb,j-1);
  quicksort(x,j+1,ub);
  return;
}
int main()
{ const int n;
  int i;
  printf("\nEnter no. of elements:");
  scanf("%d",&n);
  int x[n];
  printf("\nEnter elements:");
  for(i=0;i<n;i++)
    scanf("%d",&x[i]);
  quicksort(x,0,n-1);
  printf("\nSorted array:");
  for(i=0;i<n;i++)
    printf("%d ",x[i]); 
  return 0;
}     
