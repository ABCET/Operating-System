#include <stdio.h>

int s[20], q[100], f = 0, r = -1, fault = 0, n, frame;

void enqueue(int x)
{
    q[++r] = x;
    fault++;
}

void dequeue()
{
    f++;
}

int search(int x)
{
    for (int i = f; i < r; i++)
    {
        if (q[i] == x)
            return 1;
    }
    return 0;
}

void main()
{
    printf("Enter no. of frames:");
    scanf("%d", &frame);
    printf("Enter size of reference string:");
    scanf("%d", &n);
    printf("Enter reference string:");
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    for (int i = 0; i < n; i++)
    {
        if (search(s[i]) == 0)
        {
            if (r - f + 1 == frame)
                dequeue();
            enqueue(s[i]);
        }

        printf("\nframe : ");
        for (int j = f; j <= r; j++)
            printf("%d ", q[j]);
    }
    printf("\n\nNo. of page faults:%d\n", fault);
}
