#include<stdio.h>
int main()
{
    int i,n,p[10],min,k=1,btime=0;
    int burst_t[10],temp,j,arr_t[10],wat_t[10],tt[10],sum=0;
    float wavg=0,tsum=0,wsum=0;
    printf("\nEnter the No. of processes :");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("\nEnter Arrival Time:\t");
            scanf("%d", &arr_t[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_t[i]);
            p[i]=i+1;
    }
//process ,Arrival time,burst time sort korbo

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr_t[i]<arr_t[j])
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;

                temp=arr_t[j];
                arr_t[j]=arr_t[i];
                arr_t[i]=temp;

                temp=burst_t[j];
                burst_t[j]=burst_t[i];
                burst_t[i]=temp;
            }
        }
    }



    for(j=0; j<n; j++)
    {
        btime=btime+burst_t[j];
        min=burst_t[k];
        for(i=k; i<n; i++)
        {
            if (btime>=arr_t[i] && burst_t[i]<min)
            {
                temp=p[k];
                p[k]=p[i];
                p[i]=temp;

                temp=arr_t[k];
                arr_t[k]=arr_t[i];
                arr_t[i]=temp;

                temp=burst_t[k];
                burst_t[k]=burst_t[i];
                burst_t[i]=temp;
            }
        }
        k++;
    }
    wat_t[0]=0;
    for(i=1; i<n; i++)
    {
        sum=sum+burst_t[i-1];
        wat_t[i]=sum-arr_t[i];
        wsum=wsum+wat_t[i];
    }

    wavg=(wsum/n);



    printf("\nProcess\t Burst\t Arrival\t Waiting" );
    for(i=0; i<n; i++)
    {
        printf("\n p[%d]\t %d\t %d\t\t %d\t\t\t%",p[i],burst_t[i],arr_t[i],wat_t[i]);
    }

    printf("\n\nAverage Waiting Time  : %f",wavg);

    return 0;
}
