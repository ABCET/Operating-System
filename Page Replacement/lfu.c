#include <stdio.h>
int s[20], size=0, fault = 0, n;

struct pages_in_memory
{
    int page_no;
    int count;
}pages[20],page;

void remove_page() 
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (pages[j].count > pages[j + 1].count)
            {
                page = pages[j];
                pages[j] = pages[j + 1];
                pages[j + 1] = page;
            }
        }
    }
    for (int i = 0; i < size - 1; i++)
        pages[i] = pages[i + 1];
    size--;
}

void add_page(int item)
{
    fault++;
    page.page_no = item;
    page.count = 1;
    if (size == n)
        remove_page();
    pages[size] = page;
    size++;
}

int search(int item)
{
    for (int i = 0; i < size; i++)
        if (pages[i].page_no == item)
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
    add_page(s[0]);
    for (int i = 1; i < no; i++)
    {
        int pno = s[i];
        if (search(pno) == 0)
            add_page(pno);
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (pages[i].page_no == pno)
                {
                    pages[i].count++;
                    break;
                }
            }
        }
    }
    printf("no. of page faults:%d\n", fault);
}
