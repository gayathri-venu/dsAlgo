#include <stdio.h>
#include<string.h>

int i,j,k,value,c,hash;
char ch;
char a[26][15];
char sentence[100],s[20];
void insert_lin(int value,char str[15])
{ hash=value%26;
  while(strcmp(a[hash]," ")!=0)
     {hash=(hash+1)%26;}
  strcpy(a[hash],str);
}
void insert_quad(int value,char str[15])
{ hash=value%26;
  int c=hash;
  i=1;
  while(strcmp(a[hash]," ")!=0)
     {hash=(c+i*i)%26;
      i+=1;}
  strcpy(a[hash],str);
}
int search_lin(int value,char str[15])
{ j=1;
  hash=value%26;
  while(strcmp(a[hash],s)!=0)
     {hash=(hash+1)%26;
      j+=1;}
  return j;
}
int search_quad(int value,char str[15])
{ int j=1;
  hash=value%26;
  int c=hash;
  while(strcmp(a[hash],s)!=0)
     {hash=(c+j*j)%26;
      j+=1;
     }
  return j;
}
 int main()
 {    
       for(i=0;i<26;i++)
       {strcpy(a[i]," ");}
       printf("\nEnter the sentence:");
       scanf("%[^\n]%*c",sentence);
       printf("\nMENU\n1-Linear\n2-Quadratic\nEnter choice(1/2):");
       scanf("%c",&ch);
       i=0;
       j=0;
       c=0;
       while(j<=strlen(sentence))
        {
          if((sentence[j]==' ')||(sentence[j]=='\0'))
               {  if(c<=26)
                  {if(ch=='1')
                    insert_lin(strlen(s),s);
                  else
                    insert_quad(strlen(s),s);
                  i=0;
                  c+=1;
                  }
                  else
                    {printf("\nHash table full!");
                     break;
                    } 
                }
          else
               {
                  s[i]=sentence[j];
                  i+=1;

                }
        j+=1;
       }
     
       printf("\n");
       for(i=0;i<26;i++)
       {printf("\n%d %s",i,a[i]);}
        printf("\nEnter the word to search:");
        scanf("%s",s);
        if(ch=='1')
          printf("\nNo. of key comparisons:%d",search_lin(strlen(s),s));
        else
         printf("\nNo. of key comparisons:%d",search_quad(strlen(s),s));
        
       return 0;
 }

 
