#include <stdio.h>
int s[20],n,q[100], f = 0, r = 0,fault=0,pg=0;
void enqueue(int item)
{
    fault++;
    q[r++] = item;
}

void dequeue()
{
    f++;
}

int search(int item)
{
    for (int i = f; i <= r; i++)
        if (q[i] == item)
            return 1;
    return 0;
}

void main()
{
    int no;
    printf("input no. of frames:");
    scanf("%d", &n);
    printf("input reference string size:");
    scanf("%d", &no);
    printf("input reference string:");
    for (int i = 0; i < no; i++)
        scanf("%d", &s[i]);
    enqueue(s[0]);
    for (int i = 1; i < no; i++)
    {
        pg = s[i];
        if (search(pg) == 0)
        {
            if (r-f == n-1)
                dequeue();
            enqueue(pg);

        }
    }
    printf("no. of page faults:%d\n", fault);
}
