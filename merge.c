#include<stdio.h>
const int m;
void merge(int x[],int first,int mid,int last)
{ int B[m];
  int j=0;
  int lpt=first;
  int upt=mid+1;
  int n=last-first+1;
  while((lpt<mid+1)&&(upt<last+1))
  {
    if(x[lpt]<x[upt])
    { B[j]=x[lpt];
      lpt=lpt+1;
      j=j+1;
    }
    else
    { B[j]=x[upt];
      upt=upt+1;
      j=j+1;
    }
  }
  while(lpt<mid+1)
  { B[j]=x[lpt];
    j=j+1;
    lpt=lpt+1;
  }
  while(upt<last+1)
  { B[j]=x[upt];
    j=j+1;
    upt=upt+1;
  }
  lpt=first;
  for(j=0;j<n;j++)
  { x[lpt]=B[j];
    lpt=lpt+1;
  }
 
}
 void mergesort(int x[],int first, int last)
{ if(first==last)
     return;
  else
  {int mid=(first+last)/2;
  mergesort(x,first,mid);
  mergesort(x,mid+1,last);
  merge(x,first,mid,last);
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
  mergesort(x,0,m-1);
  printf("\nSorted array:");
  for(i=0;i<m;i++)
    printf("%d ",x[i]); 
  return 0;
}     
