#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE* insertfront(NODE *, int); 
NODE* deletekey(NODE *, int);
void display(NODE *); 

void main()
{
NODE *start=NULL;
int num,choice,k,p;
while(1)
{
	printf("Enter your choice\n");
	printf("1. Insert at front\n");
	printf("2. Delete a node\n");
	printf("3. Display\n");
	printf("4. Stop\n");
	scanf("%d", &choice);
	switch(choice)
   {
        case 1: printf(" Enter data to insert\n");
                    scanf("%d",&num);
  	                start= insertfront(start,num);
                    break;
        case 2: printf(" Enter the key value");
             scanf("%d",&k);
	         start= deletekey(start,k);
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

NODE* deletekey(NODE *start,  int key)
{
     NODE  *temp, *ptr;
             
      if (start == NULL)  // No Nodes
      {
	   printf("List Empty\n");
       }
       else if (start->data==key ) //first node is key
      {
               printf("Item Deleted: %d\n", start->data);  
               ptr=start;
               start = start->next;
	  free(ptr);
      }           
           
else
   {// Traverse till key is found or till last node
         ptr=start;
         while((ptr != NULL)&&(ptr->data !=key))
              {
                temp=ptr;
	          ptr = ptr->next;
               }
         if(ptr == NULL)  // Searched till end of list
                   printf("Invalid key\n");
         else
             {
	      temp->next = ptr->next;
                 printf("Item deleted:  %d\n",ptr->data);   
                 free(ptr);
             }
      }
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


