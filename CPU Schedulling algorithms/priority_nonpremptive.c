#include <stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
    int p;
} p[10], temp;

void main()
{
    int n, i, j, ct = 0, curr = -1;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time ,burst time and priority of process %d: ", i);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].p);
        p[i].pid = i;
        p[i].rt = p[i].bt;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++)
    {
        curr = -1;
        for (j = 0; j < n; j++)
        {
            if (p[j].at <= ct && p[j].rt > 0 && (curr == -1 || p[j].p < p[curr].p))
                curr = j;
        }
        printf("%d | P%d | ", ct, p[curr].pid);
        ct += p[curr].bt;
        p[curr].rt = 0;
        p[curr].tat = ct - p[curr].at;
        p[curr].wt = p[curr].tat - p[curr].bt;
    }
    printf("%d", ct);

    printf("\n+-----+--------------+------------+--------------+-----------------+\n");
    printf("| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("+-----+--------------+------------+--------------+-----------------+\n");
    for (int i = 0; i < n; i++)
        printf("| %3d | %12d | %10d | %12d | %15d |\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    printf("+-----+--------------+------------+--------------+-----------------+\n");

    for (int i = 0; i < n; i++)
    {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    avg_wt /= n;
    avg_tat /= n;
    printf("Average waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);
}