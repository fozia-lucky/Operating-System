
#include<stdio.h>

int main()
{
    int a,burst_t[10],p[20],x,total=0, arr_t[10],i,j,asc,temp[10],time,count=0,smallest,t_quan;
    double wat_t=0,end;
    float avg_wat;
    printf("Enter total number of process:");
    scanf("%d",&a);
    x=a;
    printf("\nEnter Details of %d Processes\n", a);
    for(i=0;i<a;i++)
    {

        printf("\nEnter Arrival Time:\t");
            scanf("%d", &arr_t[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_t[i]);
            temp[i] = burst_t[i];
    }

    printf("\nEnter Time Quantum:\t");
    scanf("%d", &t_quan);
    printf("\nProcess\t\tBrust Time\tArraival Time\tWating Time");
    for(total = 0, i = 0; x!= 0;)
      {
            if(temp[i] <= t_quan && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  count = 1;
            }



      else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - t_quan;
                  total = total + t_quan;
            }

            if(temp[i] == 0 && count == 1)
            {
                  x--;
                  printf("\n%d\t\t%d\t\t%d\t\t %d", i + 1, burst_t[i], arr_t[i],  total - arr_t[i] - burst_t[i]);
                  wat_t = wat_t + total - arr_t[i] - burst_t[i];
                  count = 0;
            }
            if(i == a - 1)
            {
                  i = 0;
            }
            else if(arr_t[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }

     avg_wat=wat_t*1.0/a;
    printf("\n\nAverage Waiting Time:\t%lf\n",avg_wat);

    return 0;
}

