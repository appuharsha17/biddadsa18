 

#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *leftlink; 
	int data; 
	struct node *rlink;
};
typedef struct node NODE;

NODE* insertfront(NODE *, int); 
NODE* i_beforekey(NODE *, int,int); 
void display(NODE *); 

void main()
{
NODE *start=NULL;
int num,choice,k;
while(1)
{
	printf("\nEnter your choice\n");
	printf("1. Insert at front\n");
	printf("2. Insert before data\n");
	printf("3. Display\n");
	printf("4. Stop\n");
	scanf("%d", &choice);
	switch(choice)
         {
        case 1: printf(" Enter data to insert\n");
                    scanf("%d",&num);
  	                start= insertfront(start,num);
                    break;
        case 2: printf(" Enter data to insert\n");
                scanf("%d",&num);
	            scanf("%d",&k);
  	            start= i_beforekey(start,num,k);
                break;
	    case 3:  display(start);
                 break;
        case 4: exit(0);
        } 
    }
}
void display(NODE *start)
{
         NODE *ptr;
          ptr = start;
          if (start == NULL)
         {         
               	printf("List is empty\n"); 
         }
	else
	{
          	printf("The list data are \n");
          	while(ptr != NULL)
          	{
            		printf("%d ->", ptr->data);
            		ptr = ptr->rlink;
          	}
          	printf("NULL");
	}
}
NODE* insertfront(NODE *start, int n)
{
    NODE *new_node;		
   	new_node = (NODE *)malloc(sizeof(struct node)); 
    new_node ->data = n;
	new_node ->leftlink=NULL;
	new_node ->rlink=NULL;
    if(start==NULL)
	{
		start=new_node;
    }   
	else
	{
	       new_node ->rlink = start;
           start->leftlink= new_node;
           start = new_node;
    }
     return start;
} 
NODE* i_beforekey(NODE *start, int n, int key)
{
     NODE * new_node , * temp, * ptr;
     new_node = (NODE *) malloc(sizeof(struct node)); 
     new_node ->data = n;
     if (start== NULL)
     {    
                printf("List Empty, cannot insert\n");
     }
     else if(start ->data==key ) // if start node is the key 
     {
       new_node ->rlink = start;
 	  start ->leftlink =  new_node ; 
	  new_node->leftlink = NULL;
 	  start =  new_node ;
     }
     else
{    // Traverse till key is found or till last node
         ptr= start;
         while((ptr != NULL) && (ptr->data!=key))
         {    
 	         temp = ptr;
                     ptr =  ptr->rlink;
         }
          if(ptr == NULL) // Searched till end of list
                   printf("Invalid key\n");
         else
         {
	         new_node ->rlink =  ptr; 
	         ptr->leftlink =  new_node ;
                     new_node ->leftlink = temp;
	         temp->rlink =  new_node ;   
          }
}
return  start;   
} 
