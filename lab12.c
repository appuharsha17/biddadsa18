#include<stdio.h> 
#include<stdlib.h>
#define MAX 5
int  queue[5], front=-1, rear=-1;
void enqueue(int); 
void dequeue(); 
void display(); 
int main() 
{ 
    int choice, num;
    while(1)
    { 
        printf("\n1.INSERT\n2.DELETE \n3.DISPLAY \n4.EXIT\n");
        printf("\n Enter the Choice: "); 
        scanf("%d",&choice);
        switch(choice) 
        { 
            case 1: printf("Enter value to push ");
            scanf("%d",&num);
            enqueue(num); 
            break; 
            case 2: dequeue(); 
            break;
            case 3: display(); 
            break; 
            case 4: printf("\n EXIT POINT\n"); 
            exit(0);
            default: printf ("\nEnter Valid Choice\n");
        }
    }
    return 0; 
}

void enqueue (int num) 
 {
    if(rear == MAX-1) 
    {
        printf("\n OVERFLOW");
        return;
    }
    else if(front == -1 && rear == -1) 
    { 
    front = rear = 0; 
    }
    else 
    {
    rear++; 
    }
queue[rear] = num;
}

void dequeue() 
{ 
    if(front == -1 || front>rear)
    { 
        printf("\n UNDERFLOW"); 
    } 
    else
    { 
        int val = queue[front]; 
        printf("Deleted Item: %d", val);
        front++; 
        if(front > rear) 
        {
            front = rear = -1; 
        }
    }
}


void display()
{ 
    int i;
    if(front == -1 || front > rear) 
    {
        printf("\n QUEUE EMPTY"); 
    }
    else 
    { 
        printf("Queue data \n");
        for(i = front; i <= rear; i++) 
        {
            printf("\t %d", queue[i]);
        } 
    }
 }