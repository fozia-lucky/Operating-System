
#include<stdio.h>

int main()
{
    int a,burst_t[10],p[20], arr_t[10],i,j,asc,temp[10],time,count=0,smallest;
    double wat_t=0,end;
    float avg_wat;
    printf("Enter total number of process:");
    scanf("%d",&a);

    printf("\nEnter Details of %d Processes\n", a);
    for(i=0;i<a;i++)
    {

        printf("\nEnter Arrival Time:\t");
            scanf("%d", &arr_t[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_t[i]);
            temp[i] = burst_t[i];
    }




      burst_t[9] = 9999;
      for(time = 0; count != a; time++)
      {
            smallest = 9;
            for(i = 0; i < a; i++)
            {
                  if(arr_t[i] <= time && burst_t[i] < burst_t[smallest] && burst_t[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_t[smallest]--;
            if(burst_t[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wat_t = wat_t +  end - arr_t[smallest] - temp[smallest];

            }
      }

     avg_wat=wat_t/a;
    printf("\n\nAverage Waiting Time:\t%lf\n",avg_wat);

    return 0;
}
