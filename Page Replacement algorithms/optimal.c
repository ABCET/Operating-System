#include <stdio.h>
int s[20], n, frame, fault = 0, size = 0;

struct frame
{
    int pgno;
    int p;
} f[10];

int search(int item)
{
    for (int i = 0; i < size; i++)
        if (f[i].pgno == item)
            return i;
    return -1;
}
void main()
{
    int index, i, j, max;
    printf("input no. of frames:");
    scanf("%d", &frame);
    printf("input reference string size:");
    scanf("%d", &n);
    printf("input reference string:");
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    for (i = 0; i < n; i++)
    {
        index = search(s[i]);
        if (index == -1)
        {
            fault++;
            if (size == frame)
            {
                for (j = 0; j < frame; j++)
                {
                    f[j].p = 9999999;
                    for (int k = i + 1; k < n; k++)
                        if (f[j].pgno == s[k])
                        {
                            f[j].p = k;
                            break;
                        }
                }
                max = 0;
                for (j = 1; j < frame; j++)
                    if (f[j].p > f[max].p)
                        max = j;
                f[max].pgno = s[i];
            }
            else
            {
                f[size].pgno = s[i];
                size++;
            }
        }
        printf("\nframe : ");
        for (j = 0; j < size; j++)
            printf("%d ", f[j].pgno);
    }
    printf("\nno. of page faults:%d\n", fault);
}
