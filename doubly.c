#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;


void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void deleteByKey(struct node*l,int key);


int main()
{
    int n, data,key, ch=1;

    head = NULL;
    last = NULL;

    printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);

    createList(n);
    printf("\nData in the list \n");
    displayList();
    while(ch!= 5)
    {
    printf("\nMENU\n1-Insert a node at the beginning of the list\n2-Insert a node after a particular node in the list\n3-Insert a node at the end of the list\n4-Delete a node containing a particular item");
    printf("\n5-Exit");    
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
        {
            case 1:printf("Enter data of first node : ");
                   scanf("%d", &data);
                   insertAtBeginning(data);
                   printf("\nData in the list \n");
                   displayList();
                   break;
                
            case 2:printf("Enter the position where you want to insert new node: ");
                   scanf("%d", &n);
                   printf("Enter data of %d node : ", n);
                   scanf("%d", &data);
                   insertAtN(data, n);
                   printf("\nData in the list \n");
                   displayList();
                   break;
                
            case 3:printf("Enter data of last node : ");
                   scanf("%d", &data);
                   insertAtEnd(data);
                   printf("\nData in the list \n");
                   displayList();
                   break;
            case 4:printf("\nEnter element to delete with key: ");
                   scanf("%d", &key);
                   deleteByKey(head,key);
                   printf("\nData in list after deletion\n");
                   displayList();
                   break;
                
            case 5:
                   break;
           
        }

        printf("\n\n\n\n\n");
    }

    return 0;
}



void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;

            last->next = newNode; 
            last = newNode;          
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

           
            temp = temp->next;
        }
    }
}



void insertAtBeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head; 
        newNode->prev = NULL; 

        
        head->prev = newNode;

       
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}



void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}


void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; 
            newNode->prev = temp;        

            if(temp->next != NULL)
            {
                
                temp->next->prev = newNode;
            }
            
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}


void deleteByKey(struct node*l,int key)
{struct node*temp,*pre;
 temp=l;
 if(l==NULL)
   printf("\nEmpty list");
 else
  { if(temp->data==key)
      {l=l->next;
       l->next->prev=NULL;
       }
    else
     { while(temp!=NULL && temp->data!=key)
       {pre=temp;
        temp=temp->next;
        }
       pre->next=temp->next;
       temp->next->prev=pre;
        
     }
  }  
    
}
