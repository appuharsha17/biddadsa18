#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
   	int data;
   	struct node *left;
   	struct node *right;
 }NODE;

NODE *root;
NODE *root;

NODE *insertnode(NODE *, int);
void preorderTraversal(NODE *);
void inorderTraversal(NODE *);
void postorderTraversal(NODE *);
int main()
{
  int option, val;
  NODE *root=NULL;
  while(1)
  {
     printf("\n 1. Insert Element");
     printf("\n 2. Preorder Traversal");
     printf("\n 3. Inorder Traversal");
     printf("\n 4. Postorder Traversal");
     printf("\n 5. Exit");
     printf("\nEnter your option :\n ");
     scanf("%d", &option);
     switch(option)
     {
        case 1:  printf("\n Enter Value : ");
                      scanf("%d", &val);
 	      root = insertnode(root, val);
	      break;
        case 2:
            printf("\nPre-order Traversal: \n");
            preorderTraversal(root);
            break;
        case 3:
             printf("\nIn-order Traversal : \n");
            inorderTraversal(root);
            break;
        case 4: 
            printf("\nPost-order Traversal : \n");
            postorderTraversal(root);
            break;
        case 5:
         exit(0);
      }  
  }      
    return 0;     
}

NODE *insertnode(NODE *root, int val)
{
         NODE *new_node, *ptr, *temp;
         new_node = (NODE*)malloc(sizeof(struct node));
         new_node -> data = val;
         new_node ->left = NULL;
         new_node ->right = NULL;
         if(root==NULL)
                 root= new_node;
         else
         {
            ptr=root;
            while(ptr!=NULL)
            {
                temp=ptr;
                if(val < (ptr ->data))
	     	        ptr=ptr ->left;
                else
                 	ptr = ptr ->right;
            }
            if(val < (temp ->data))
                temp ->left = new_node;
            else
                temp ->right = new_node;
        }
    return root;
}
void preorderTraversal(NODE *root)
 {
     if(root != NULL)
     {
        	printf("%d\t", root->data);
        	preorderTraversal(root->left);
        	preorderTraversal(root->right);
      }    
}
void inorderTraversal(NODE *root)
 {
     if(root != NULL)
     {
   inorderTraversal(root->left);
    printf("%d\t", root->data);
    inorderTraversal(root->right);
     }   
}
void postorderTraversal(NODE *root)
 {
       if(root != NULL)
       {
          	postorderTraversal(root->left);
          	postorderTraversal(root->right);
          	printf("%d\t", root->data);
       }  
}



