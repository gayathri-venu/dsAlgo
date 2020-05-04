#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;           
    struct node *next;  
}*head;


void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtMiddle(int data, int position);
void insertNodeAtEnd(int data);
void deleteByKey(int key);
void displayList();


int main()
{
    int n, data,position,key,totalDeleted,ch=1;

    
    printf("Enter the total number of nodes: ");
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
    { case 1:printf("\nEnter data to insert at beginning of the list: ");
             scanf("%d", &data);
             insertNodeAtBeginning(data);
             printf("\nData in the list \n");
             displayList();
             break;
      case 2:printf("Enter data to insert at middle of the list: ");
             scanf("%d", &data);
             printf("Enter the position to insert new node: " );
             scanf("%d", &position);
             insertNodeAtMiddle(data, position);
             printf("\nData in the list \n");
             displayList ();
             break;
      case 3:printf("\nEnter data to insert at end of the list: ");
             scanf("%d", &data);
             insertNodeAtEnd(data);
             printf("\nData in the list \n");
             displayList();
             break;
      case 4:printf("\nEnter element to delete with key: ");
             scanf("%d", &key);
             deleteByKey(key);
             printf("\nData in list after deletion\n");
             displayList();
             break;
      case 5:break;
    
    
     }


   }
    return 0;
}


void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; 
        head->next = NULL; 

        temp = head;

      
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 

                temp->next = newNode; 
                
                temp = temp->next; 
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 

        head = newNode;          

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL;

        temp = head;

        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            
            newNode->next = temp->next; 

            
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}



void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL; 

        temp = head;

        
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; 

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void deleteByKey(int key)
{
   
    struct node *prev, *cur;

    
    while (head != NULL && head->data == key)
    {
        
        prev = head;

        
        head = head->next;

        
        free(prev);

      
    }

    prev = NULL;
    cur  = head;

    
    while (cur != NULL)
    {
        
        if (cur->data == key)
        {
            
            if (prev != NULL) 
            {
                prev->next = cur->next;
            }

            
            free(cur);

            cur = prev->next;

            
        } 
        else
        {
            prev = cur;
            cur = cur->next;
        }        

    }

   
}

void displayList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                 
        }
    }
}
