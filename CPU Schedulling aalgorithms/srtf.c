#include <stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
} p[10], temp;

void main()
{
    int n, i, j, ct = 0, comp = 0, prev = -1, curr = -1;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d: ", i);
        scanf("%d %d", &p[i].at, &p[i].bt);
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
    while (comp < n)
    {
        curr = -1;
        for (i = 0; i < n; i++)
        {
            if (p[i].at > ct)
                break;
            if (p[i].rt > 0 && (curr == -1 || p[i].rt < p[curr].rt))
                curr = i;
        }
        if (curr != -1)
        {
            if (prev != curr)
                printf("%d | P%d | ", ct, p[curr].pid);
            ct++;
            p[curr].rt--;
            if (p[curr].rt == 0)
            {
                p[curr].tat = ct - p[curr].at;
                p[curr].wt = p[curr].tat - p[curr].bt;
                comp++;
            }
            prev = curr;
        }
        else
        {
            if (curr != prev)
            {
                printf("%d | idle |", ct);
            }
            ct++;
            prev = -1;
        }
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