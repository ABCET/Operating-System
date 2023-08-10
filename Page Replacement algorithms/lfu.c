#include <stdio.h>
int s[20], n, frame, fault = 0, size_f = 0, size_p = 0;

struct page
{
    int pgno;
    int count;
} p[10];

struct frame
{
    struct page *p;
    int pr;  //priority when frequency is same for fifo replacement
} f[10];

int search_frame(int item)
{
    for (int i = 0; i < size_f; i++)
        if (f[i].p->pgno == item)
            return i;
    return -1;
}

int search_page(int item)
{
    for (int i = 0; i < size_p; i++)
        if (p[i].pgno == item)
            return i;
    return -1;
}

void main()
{
    int index, idx, i, j, min,c=0;
    printf("input no. of frames:");
    scanf("%d", &frame);
    printf("input reference string size:");
    scanf("%d", &n);
    printf("input reference string:");
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    for (int i = 0; i < n; i++)
    {
        index = search_frame(s[i]);
        if (index == -1)
        {
            fault++;
            idx = search_page(s[i]);
            if (idx == -1)
            {
                p[size_p].pgno = s[i];
                p[size_p].count = 0;
                size_p++;
            }
            if (size_f == frame)
            {
                min = 0;
                for (j = 1; j < frame; j++)
                    if (f[j].p->count < f[min].p->count||f[j].p->count==f[min].p->count&&f[j].pr<f[min].pr)
                        min = j;
                f[min].p = idx == -1 ? &p[size_p - 1] : &p[idx];
                f[min].p->count++;
                f[min].pr=c;
            }
            else
            {
                f[size_f].p = idx == -1 ? &p[size_p - 1] : &p[idx];
                f[size_f].p->count++;
                f[size_f].pr=c;
                size_f++;
            }
            c++;
        }
        else
            f[index].p->count++;
        printf("\nframe : ");
        for (j = 0; j < size_f; j++)
            printf("%d ", f[j].p->pgno);
    }
    printf("\nno. of page faults:%d\n", fault);
}
