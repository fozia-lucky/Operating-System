#include<stdio.h>

int main()
{
    int burst_t[10],arr_t[10],p[10],wat_t[10],prior[10],i,a,t[10],pos=0,temp,completion[10],smallest,avg_wat=0;
    double end;
    printf("Enter Total Number of Process:");
    scanf("%d",&a);

    printf("\nEnter Burst Time,Arrival time and Priority\n");
    for(i=0;i<a;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&burst_t[i]);
        printf("Arrival Time:");
        scanf("%d",&arr_t[i]);
        printf("Priority:");
        scanf("%d",&prior[i]);
        p[i]=i+1;           //contains process number
    }


        for(i=0;i<a;i++)
        t[i]=burst_t[i];

    prior[9]=-1;
    for(temp=0;pos!=a;temp++)
    {
        smallest=9;
        for(i=0;i<a;i++)
        {
            if(arr_t[i]<=temp && prior[i]>prior[smallest] && burst_t[i]>0 )
                smallest=i;
        }
        temp+=burst_t[smallest]-1;
        burst_t[smallest]=-1;
        pos++;
        end=temp+1;
        completion[smallest] = end;
        wat_t[smallest] = end - arr_t[smallest] - t[smallest];

    }
        printf("\nProcess\t    Burst Time\t Arrival time\t Priority\t  Completion Time \tWaiting Time\n");

    for(i=0;i<a;i++)
    {
    printf("\nP[%d]\t\t  %d\t\t    %d\t\t %d\t\t %d\t\t %d\n",p[i],t[i],arr_t[i],prior[i],completion[i],wat_t[i]);
        avg_wat+= wat_t[i];
    }
    avg_wat=avg_wat/a;
    printf("\n\nAverage Waiting Time=%d\n",avg_wat);

    return 0;
}







