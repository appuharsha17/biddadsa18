#include<stdio.h>
int fibo(int n);
int main(){
    int n,i=0,res;
    printf("enter the number of terms: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        res=fibo(i);
        printf("%d",res);
    }
    printf(" The nth term of fibonnaci series is: %d",res);
    return 0;
}
int fibo(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return(fibo(n-1)+fibo(n-2));
    }
}