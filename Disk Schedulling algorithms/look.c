#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n, max, req[10], head, count = 0, d = 0, t, l;
    printf("Enter no of requests:");
    scanf("%d", &n);
    printf("Enter the requests:");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter max track no:");
    scanf("%d", &max);
    printf("Enter head position:");
    scanf("%d", &head);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (req[j] > req[j + 1])
            {
                t = req[j];
                req[j] = req[j + 1];
                req[j + 1] = t;
            }
        }
    }
    l = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (req[i] >= head)
        {
            l = i;
            break;
        }
    }
    d = req[n-1] - head + req[n-1] - req[0];
    printf("Seek Sequence :");
    for (int i = l; i < n; i++)
        printf("%d-->", req[i]);
    for (int i = l - 1; i >= 1; i--)
        printf("%d-->", req[i]);
    printf("%d", req[0]);
    printf("\nSeek Count is:%d\n", d);
}