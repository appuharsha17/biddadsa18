#include<stdio.h>
#include<stdlib.h>
struct TIME
{
    int hr,min,sec;
    struct TIME *next;
};
struct TIME *T1,*T2;
void display(struct TIME*);
int main()
{
    T1=(struct TIME*)malloc(sizeof(struct TIME));
    printf("Enter the hours,minutes and seconds of T1\n");
    scanf("%d %d %d", &T1->hr, &T1->min, &T1->sec);
    T2=(struct TIME*)malloc(sizeof(struct TIME));
    printf("Enter the hours,minutes and seconds of T2\n");
    scanf("%d %d %d", &T2->hr, &T2->min, &T2->sec);
    T1->next=T2;
    display(T1);
    return 0;
}
void display(struct TIME* start)
{
    struct TIME *temp=start;
    printf("Time- %d : %d : %d\n", temp->hr,temp->min,temp->sec);
    temp=temp->next;
    printf("Time- %d : %d : %d\n", temp->hr,temp->min,temp->sec);
}
