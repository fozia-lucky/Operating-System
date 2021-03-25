#include<stdio.h>
#include<conio.h>

int main()
{
    int i, n, iniavi, alloc[10], max[10], avail[10], need[10], flag[10], safe[10];

    printf("\nEnter the Number of process : ");
    scanf("%d", &n);

    /* Get Allocation & Maximum Values */
    printf("\nEnter the allocation and maximum values\n");
    for (i=0; i<n; i++)
    {
        printf("\nEnter Allocation Value P[%d] : \t", i);
        scanf("%d", &alloc[i]);

        printf("Enter Maximum Value of P%d: \t", i);
        scanf("%d", &max[i]);
    }

    printf("\nEnter Initial available : \t");
    scanf("%d", &iniavi);

    /* Need calculation */
    for(i=0;i<n;i++)
    {
        need[i] = max[i] -alloc[i];
    }

    /* Print entered Inputs */
    printf("\nAvailable\tAllocation\tMaximum\t\tNeed");
    printf("\n--------------------------------------------------------\n");
    printf("%d", iniavi);
    for(i=0; i<n; i++)
    {
        printf("\t\t%d\t\t%d\t\t%d\n", alloc[i], max[i], need[i]);
    }
    printf("\n--------------------------------------------------------\n");

    /* Safe Sequence Calculation */
    printf("\nSafe sequences\n\n");
    i=0;
    while(i<n)
    {
        if(need[i]<iniavi)

        {

            avail[i]=iniavi+alloc[i];

            iniavi=avail[i];

            safe[i+1]=i;

            flag[i]=1;

            printf("P[%d]->  ", i);

        }
        else
        {
            flag[i] = 0;
        }
        i++;
    }

    for(i=0; i<n; i++)
    {
        if(flag[i] != 1)
        {
            if(need[i]<iniavi)

            {

                avail[i]=iniavi+alloc[i];

                safe[i+1]=i;

                flag[i]=1;

                printf("P[%d]->  ", i);

            }
        }
    }

    return 0;
}
