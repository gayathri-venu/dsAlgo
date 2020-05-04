#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * next;
}*head;


void createList(struct node ** head, int n);
void displayList(struct node ** head);
void deleteAll(struct node ** head, int key);
void insertAtBeginning(int data);
void insertAtN(int data, int position);

int main()
{
    int n, key, data, choice=1;

    head = NULL;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(&head, n);
    printf("\nData in the list \n");
    displayList(&head);

    while(choice != 4)
    {
        printf("\nMENU\n1-Insert a node at the beginning of the list\n2-Insert a node after a particular node in the list\n3-Delete a node containing a particular item");
        printf("\n4-Exit");    
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        

        switch(choice)
        {
            case 1:printf("Enter data to be inserted at beginning: ");
                   scanf("%d", &data);
                   insertAtBeginning(data);
                   printf("\nData in the list \n");
                   displayList(&head);
                   break;

            case 2:printf("Enter node position: ");
                   scanf("%d", &n);
                   printf("Enter data you want to insert at %d position: ", n);
                   scanf("%d", &data);
                   insertAtN(data, n);
                   printf("\nData in the list \n");
                   displayList(&head);
                   break;

            case 3:printf("Enter key to delete from list: ");
                   scanf("%d", &key);
                   deleteAll(&head, key);
                   printf("\nData in the list \n");
                   displayList(&head);
                   break;

            case 4:exit(0);
                   break;

            default:
                printf("Error! Invalid choice. Please choose between 0-3");
        }

        printf("\n\n\n\n");
    }

    return 0;
}



void deleteAll(struct node ** head, int key)
{
    int i, count;
    struct node *prev, *cur;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    count = 0;
    cur   = *head;
    prev  = cur;


    while (prev->next != *head) 
    {
        prev = prev->next;
        count++;
    }

 
    i = 0;
    while (i <= count)
    {
        if (cur->data == key)
        {
            if (cur->next != cur)
                prev->next = cur->next;
            else
                prev->next = NULL;

            if (cur == *head)
                *head = prev->next;

            
            free(cur);

            if (prev != NULL) 
                cur = prev->next;
            else
                cur = NULL;
        }
        else 
        {
            prev = cur;
            cur  = cur->next;
        }


        i++;

    }
}


void createList(struct node ** head, int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    prevNode = NULL;

  
    for(i=1; i<=n; i++)
    {
        newNode = malloc(sizeof(struct node));

        printf("Enter data of %d node: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

       
        if (prevNode != NULL) 
            prevNode->next = newNode;

       
        if (*head == NULL)
            *head = newNode;

        
        prevNode = newNode;
    }

    
    prevNode->next = *head;

    printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
}



void displayList(struct node ** head)
{
    struct node *current;
    int n = 1;

    if(*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    current = *head;
    printf("DATA IN THE LIST:\n");

    do {
        printf("Data %d = %d\n", n, current->data);

        current = current->next;
        n++;
    }while(current != *head);
}





void insertAtBeginning(int data)
{
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;

        
        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;

       
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY\n");
    }
}


void insertAtN(int data, int position)
{
    struct node *newNode, *current;
    int i;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(position == 1)
    {
        insertAtBeginning(data);
    }
    else
    {
        
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;

        current = head;
        for(i=2; i<=position-1; i++)
        {
            current = current->next;
        }

       
        newNode->next = current->next;
        current->next = newNode;

        printf("NODE INSERTED SUCCESSFULLY.\n");
    }
}
