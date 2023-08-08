#include <stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
    int flag;
} p[10], temp, *q[10], *x;

int front = 0, rear = 0;

void enqueue(struct process *p)
{
    q[rear] = p;
    rear = (rear + 1) % 10;
}

struct process *dequeue()
{
    x = q[front];
    front = (front + 1) % 10;
    return x;
}

void main()
{
    int n, i, j, qt, ct = 0, et;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d: ", i);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i;
        p[i].rt = p[i].bt;
        p[i].flag = 0;
    }

    printf("Enter the quantum time: ");
    scanf("%d", &qt);

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

    enqueue(&p[0]);
    ct = p[0].at;
    p[0].flag = 1;
    printf("Gantt chart: ");
    printf("%d", ct);

    while (front != rear)
    {
        x = dequeue();
        x->flag = 0;
        for (i = 0; i < n; i++)
            if (p[i].at == x->at && p[i].pid != x->pid && p[i].flag == 0 && p[i].rt > 0)
            {
                enqueue(&p[i]);
                p[i].flag = 1;
            }
        et = x->rt<qt ?x->rt:qt;
        x->rt -= et;
        ct += et;
        printf(" | P%d | %d", x->pid, ct);
        for (i = 0; i < n; i++)
            if (p[i].at > ct - et && p[i].at<=ct  && p[i].pid != x->pid )
                {
                    enqueue(&p[i]);
                    p[i].flag = 1;
                }
        if (x->rt > 0)
        {
            enqueue(x);
            x->flag = 1;
        }
        else
        {
            x->tat = ct - x->at;
            x->wt = x->tat - x->bt;
        }
        if (front == rear)
        {
            for (i = 0; i < n; i++)
            {
                if (p[i].at > ct)
                {
                    enqueue(&p[i]);
                    p[i].flag = 1;
                    printf(" | idle | %d", ct);
                    ct = p[i].at;
                    break;
                }
            }
        }
    }

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