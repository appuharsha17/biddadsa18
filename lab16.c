#include <stdio.h>
# define size 10
int largest(int arr[], int n);
void radix_sort(int arr[], int n);
void main()   {
     int arr[size], i, n;
     printf("\n Enter the value of n: ");
     scanf("%d", &n);
     printf("\n Enter the array elements: ");
     for(i=0;i<n;i++)
             scanf("%d", &arr[i]);
     radix_sort(arr, n);
     printf("\n The sorted array is: \n");
     for(i=0;i<n;i++)
            printf(" %d\t", arr[i]);   
}

int largest(int arr[], int n)
{
    int large=arr[0], i;
    for(i=1;i<n;i++)
    {
 	    if(arr[i]>large)
 	    large = arr[i];
    }
    return large;
}

void radix_sort(int arr[ ], int n)
   {
     int buket[size][size], bcount[size];
     int i, j, k, rem;
     int NOD=0, divisor=1, large, pass;
     
     large = largest(arr, n);
     while(large>0)
     {
	  NOD++;
      large = large/size;
     }
     // Initialize the buckets
     for(pass=0; pass<NOD; pass++)
     {
         for(i=0;i<size;i++)     //0-9
	        bcount[i]=0;
            for(i=0;i<n;i++)  
            { 
                rem = (arr[i]/divisor)%size;
                buket[rem][bcount[rem]] = arr[i];
                bcount[rem] = bcount[rem]+1;
            }
            i=0;  
            for(k=0;k<size;k++)
            {
                for(j=0;j<bcount[k];j++)
         	    arr[i++] = buket[k][j];
            }
            divisor = divisor*size;
        }
}

