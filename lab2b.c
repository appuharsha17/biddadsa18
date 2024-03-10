#include<stdio.h>
int c;
void search(int (*ks)[c],int *r,int *c){
    for(int i=0;i<*r;i++){
        int max=-1;
        for(int j=0;j<*c;j++){
                if(max<ks[i][j]){
                    max=ks[i][j];
                }
        }printf("Max element in %dth row is %d\n",i,max);
    }
}
void main(){
    int r;
    printf("Enter the value of row and column:");
    scanf("%d",&r);
    scanf("%d",&c);
    int ks[r][c];
    printf("Enter the elements of Matrix :");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&ks[i][j]);
        }
    }
    search(ks,&r,&c);
}