#include<stdio.h>

int main()
{
    int a,brust_t[25],p[20],wat_t[20],avg_wat=0,i,j;
    printf("Enter total number of process:");
    scanf("%d",&a);

    printf("\n Enter Burst time:\n");
    for(i=0;i<a;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&brust_t[i]);
        p[i]=i+1;
    }
    wat_t[0]=0;

    for(i=1;i<a;i++)
    {
        wat_t[i]=0;
        for(j=0;j<i;j++)
            wat_t[i]=wat_t[i]+brust_t[j];
    }
     printf("\nProcess\t\tBrust Time\tWating Time");
    for(i=0;i<a;i++)
    {

        avg_wat+=wat_t[i];
        printf("\nP%d\t\t%d\t\t%d",p[i],brust_t[i],wat_t[i]);
    }

    avg_wat=avg_wat/a;
    printf("\n\nAverage wating Time:%d",avg_wat);

    return 0;
}
