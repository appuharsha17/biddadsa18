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
NODE* deletekey(NODE *, int);  
void display(NODE *); 

void main()
{
NODE *start=NULL;
int num,choice,k;
while(1)
{
	printf("\nEnter your choice\n");
	printf("1. Insert at front\n");
	printf("2. Delete a key node\n");
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
NODE* deletekey(NODE *start,  int key)
{
     NODE  *ptr, *temp;       
      if (start == NULL)  // No Nodes
      {
              printf("List Empty\n");
      }
      else if(start->data==key ) //first node is key
      {
               ptr=start;
               start = start->rlink;
              
	  printf("Item Deleted: %d\n", ptr->data); 
               free(ptr);
      }           
      else
   {
        ptr=start;
         while((ptr!= NULL)&&(ptr->data!=key))
              {
                     //temp = temp->rlink;
                     temp=ptr;
	           ptr= ptr->rlink;
               }
         if(ptr == NULL)  // Searched till end of list
                   printf("Invalid key number\n");
         else
             {
	      temp->rlink = ptr->rlink;
if(ptr->rlink !=NULL)
                  (ptr->rlink)->leftlink = temp;
                 printf("Item deleted:  %d\n",ptr->data);   
                 free(ptr);
             }
      }
return start;   
} 

