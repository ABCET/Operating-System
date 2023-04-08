#include <stdio.h>
int s[20], n, stack[100], top = -1, fault = 0;
void push(int item)
{
    stack[++top] = item;
    fault++;
}
void pop_from_bottom()
{
    for (int i = 0; i < top; i++)
        stack[i] = stack[i + 1];
    top--;
}
int search(int item)
{
    for (int i = 0; i <= top; i++)
        if (stack[i] == item)
            return i;
    return -1;
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
    push(s[0]);
    for (int i = 1; i < no; i++)
    {
        int page_no = s[i];
        int index = search(page_no);
        if (index == -1)
        {
            if (top == n-1)
                pop_from_bottom();
            push(page_no);
        }
        else
        {
            int temp = stack[index];
            for (int i = index; i < top; i++)
                stack[i] = stack[i + 1];
            stack[top] = temp;
        }
    }
    printf("no. of page faults:%d\n", fault);
}
