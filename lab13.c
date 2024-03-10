#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
typedef struct node NODE;
int insertrear( int); 
void deletefront( ); 
void display( ); 
NODE *front=NULL;
NODE *rear=NULL;
void main()
{
    int num, choice;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1. Insert at rear\n");
        printf("2. Delete at front\n");
        printf("3. Display\n");
        printf("4. Stop\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: printf(" Enter data to insert\n");
        scanf("%d",&num);
        insertrear(num);
        break;
        case 2: deletefront();
        break;
        case 3: display();
        break;
        case 4: exit(0);
         }
    }
}
int insertrear(int n)
{
 NODE *new_node;
 new_node = (NODE *) malloc(sizeof(struct node)); 
 new_node ->num = n;
 new_node ->next = front;
 
 if((front == NULL) &&(rear == NULL)) // If List empty
 { 
    front = new_node ;
    front->next = front;
    rear = front;
 }
 rear->next = new_node ;
 new_node ->next = front; 
 rear = new_node ;
 return 0 ;
 }

 void deletefront()
{
 NODE *ptr;
 if((front == NULL) &&(rear == NULL)) 
 {
 printf("Queue Empty\n");
 }
 else if(front->next == front) // only one node
 { 
 printf("Item deleted: %d\n",front->num);
 free(front);
 front = rear = NULL;
 }
 else
{ // more than 1 nodes
ptr = front; 
front = front->next;
rear->next = front;
printf("Item deleted: %d\n",ptr->num);
 free(ptr);
}
}
void display( )
{
 NODE *ptr;
 ptr = front;
 
 if (ptr == NULL)
 printf("Queue empty\n"); 
 else
 { 
 printf("The Queue data are \n");
 do
 {
 printf("%d\n", ptr ->num);
 ptr = ptr ->next;
 }
 while(ptr != front); 
 }
 }