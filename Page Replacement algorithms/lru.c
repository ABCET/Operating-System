#include <stdio.h>
int s[20], n, frame, fault = 0,size = 0;

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
    int index, i, j, min,c=0;
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
                min = 0;
                for (j = 1; j < frame; j++)
                    if (f[j].p < f[min].p)
                        min = j;
                f[min].pgno = s[i];
                f[min].p = c;
            }
            else
            {
                f[size].pgno = s[i];
                f[size].p = c;
                size++;
            }
        }
        else
        {
            f[index].p = c;
        }
        c++;
        printf("\nframe : ");
        for (j = 0; j < size; j++)
            printf("%d ", f[j].pgno);
    }
    printf("\nno. of page faults:%d\n", fault);
}
