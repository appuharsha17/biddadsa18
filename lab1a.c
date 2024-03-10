#include<stdio.h>
void max(int *a,int *b,int *c){
    if(*a>*b && *a > *c){
        printf("%d is greatest among 3 numbers",*a);
    }
    else if(*b > *c){
        printf("%d is greatest among 3 numbers",*b);
    }
    else
        printf("%d is greatest among 3 numbers",*c);
}
void main(){
    int a,b,c;
    printf("Enter the integers to be compared:");
    scanf("%d %d %d",&a,&b,&c);
    max(&a,&b,&c);
}