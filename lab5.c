#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE* insertfront(NODE *, int); 
NODE* searchkey(NODE *,  int);
void display(NODE *); 

void main()
{
NODE *start=NULL;
int num,choice,k,p;
while(1)
{
	printf("Enter your choice\n");
	printf("1. Insert at front\n");
	printf("2. Searching a key\n");
	printf("3. Display\n");
	printf("4. Stop\n");
	scanf("%d", &choice);
	switch(choice)
   {
        case 1: printf(" Enter data to insert\n");
                    scanf("%d",&num);
  	                start= insertfront(start,num);
                    break;
        case 2: printf(" Enter key to be searched\n");
             scanf("%d",&k);
	          
  	          start= searchkey(start,k);
             break;
 	    case 3:  display(start);
                 break;
        case 4: 
                exit(0);
   } 
 }
}
NODE* insertfront(NODE *start, int n)
{
     NODE *new_node;
     new_node = (NODE *) malloc(sizeof(struct node)); 
     new_node ->data = n;
     new_node ->next = start;
     start = new_node;
     return start;
}

void display(NODE *start)
{
          NODE *ptr;
          if (start == NULL)
          {         
               printf("List is empty\n"); 
                
           }
           ptr = start;
           printf("The list data are \n");
           while(ptr != NULL)
          {
            	printf("%d\n", ptr->data);
            	ptr = ptr->next;
          }
      
}
NODE* searchkey(NODE *start,  int key)
{
     NODE  *ptr;
             
      if (start == NULL) 
      {    
                printf("List Empty\n");
       }
                  
else
   {    // Traverse till key is found or till last node
         ptr = start;  
         while((ptr != NULL)&&(ptr->data!=key))
         {
                         ptr = ptr->next;
          }
          if(ptr == NULL) // Searched till end of list
         {
                   printf("Invalid key\n"); 
         }
         else
         {
                   printf("Key %d found  \n", ptr->data); 
	}  
      }    
    return start;   
} 

