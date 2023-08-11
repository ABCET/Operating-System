#include <stdio.h>
int available[10], max[10][10], allocation[10][10], need[10][10], work[10], finish[10], safe[10], count = 0;

void main()
{
    int n, m, i, j, k, flag;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("\nEnter the available resources:");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);
    printf("\nEnter the max matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("process %d:", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    printf("\nEnter allocation matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("process %d:", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for (i = 0; i < m; i++)
    {
        work[i] = available[i];
        finish[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            flag = 0;
            if (finish[j] == 0)
            {
                for (k = 0; k < m; k++)
                {
                    if (need[j][k] > work[k])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safe[count++] = j;
                    for (k = 0; k < m; k++)
                        work[k] += allocation[j][k];
                    finish[j] = 1;
                }
            }
        }
    }
    if (count == n)
    {
        printf("The system is in safe state\n");
        printf("Safe sequence is: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    }
    else
        printf("The system is in unsafe state\n");
}