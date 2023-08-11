#include <stdio.h>
int s[20], q[100], f = 0, r = -1, fault = 0, n, frame;

struct page
{
    int freq;
} p[20];

void enqueue(int x)
{
    q[++r] = x;
    fault++;
    p[x].freq++;
}

void dequeue()
{
    f++;
}

int search(int x)
{
    for (int i = f; i <= r; i++)
    {
        if (q[i] == x)
            return i;
    }
    return -1;
}

void main()
{
    int index, j;
    printf("Enter no. of frames:");
    scanf("%d", &frame);
    printf("Enter size of reference string:");
    scanf("%d", &n);
    printf("Enter reference string:");
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    for (int i = 0; i < n; i++)
    {
        index = search(s[i]);
        if (index == -1)
        {
            if (r - f + 1 == frame)
                dequeue();
            enqueue(s[i]);
        }
        else
        {
            p[s[i]].freq++;
            for (j = index; j < r; j++)
            {
                if (p[s[i]].freq >= p[q[j + 1]].freq)
                    q[j] = q[j + 1];
                else
                    break;
            }
            q[j] = s[i];
        }
        printf("\nframe : ");
        for (int j = f; j <= r; j++)
            printf("%d ", q[j]);
    }
    printf("\n\nNo. of page faults:%d\n", fault);
}
