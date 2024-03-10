#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100],top=-1;
void push(char n){
    stack[++top]=n;
}
char pop(){
    return stack[top--];
}
int main(){
    char str[100],revstr[100],i;
    printf("Enter the String :");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++){
        push(str[i]);
    }
    for(i=0;i<strlen(str);i++){
        revstr[i]=pop();
    }
    revstr[i]='\0';
    if((strcmp(str,revstr)) == 0){
        printf("%s is a palindrome",str);
    }  
    else{
        printf("%s is not a palindrome",str);
    }  
    return 0;
}