#include<stdio.h>
void search(int *a,int *n,int *key){
    for(int i=0;i<*n;i++){
        if(a[i]==*key){
            printf("The key is present at index %d",i);
            return;
        }
    }
    printf("Key not found");
}
void main()
{
    int n,key;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key to be searched :");
    scanf("%d",&key);
    search(a,&n,&key);
}