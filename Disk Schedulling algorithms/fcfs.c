#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n, req[10], head, count = 0, d = 0;
    printf("Enter no of requests:");
    scanf("%d", &n);
    printf("Enter the requests:");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter head position:");
    scanf("%d", &head);
    printf("Seek Sequence :");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d-->", req[i]);
        d += abs(req[i] - head);
        head = req[i];
    }
    printf("%d", req[n - 1]);
    d += abs(req[n - 1] - head);
    printf("\nSeek Count is:%d\n", d);
}