#include<stdio.h>
#include<stdlib.h>
#define max 4

int top=-1,stack[max];

int overflow(){
    if(top == max-1)
    {
        printf("overflow\n");
        return 1;
    }
    return 0;
}
int underflow(){
    if(top== -1)
    {
        printf("underflow\n");
        return 1;
    }
    return 0;
}
int push(int x){
    if(overflow()== 0){
        stack[++top]=x;
    }
    return top;
}
int pop(){
    if(underflow())
    {
        return top;
    }
    else{
        printf("deleted item: %d\n",stack[top--]);
    }
    return top;
}
void display(){
    int i;
    if(underflow())
    {
        printf("stack is empty\n");
    }
    else{
        printf("stack elements are: ");
        for(int i=top; i>=0; i--){
        printf("%d ",stack[i]);}
        printf("\n");
    }
}
int main(){
    int choice,num;
    while(1){
        printf("enter your choice\n");
        printf("1.push\n2.pop\n3.check overflow and underflow\n4.display\n5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter an element: ");
                    scanf("%d",&num);
                    top=push(num);
                    break;

            case 2:top=pop();
                    break;
            case 3: if(overflow())
                    printf("stack is full\n");
                    if(underflow())
                    printf("stack is empty\n");
                    break;

            case 4: display();
                    break;
            case 5:exit(0);
        }

    }
    return 0;
}