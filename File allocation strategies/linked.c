#include <stdio.h>
#include <stdlib.h>
struct block
{
    int block_no;
    struct block *next;
} *temp;

struct file
{
    int length;
    struct block *start_block;
    struct block *end_block;
} f[10];

void main()
{
    int n, blocks[100], flag = 0, free, count, i, b, l, k = 0;
    char c = 'y';
    printf("Enter the number of free blocks: ");
    scanf("%d", &n);
    free = n;
    for (int i = 0; i < n; i++)
        blocks[i] = 0;
    while (c == 'y' || c == 'Y')
    {
        printf("Enter file starting block: ");
        scanf("%d", &b);
        printf("Enter file length: ");
        scanf("%d", &l);
        if (blocks[b] == 1)
        {
            printf("Starting block already allocated! Allocation not possible.\n");
        }
        else
        {
            if (l > free)
            {
                printf("File cannot be allocated!!\nInsufficient space in the disk.\n");
            }
            else
            {
                count = 1;
                f[k].length = l;
                blocks[b] = 1;
                temp = (struct block *)malloc(sizeof(struct block));
                temp->block_no = b;
                temp->next = NULL;
                f[k].start_block = temp;
                f[k].end_block = temp;
                free--;
                i = b + 1;
                while (count < l && i != b)
                {
                    if (i >= n)
                        i = 0;
                    if (blocks[i] == 0)
                    {
                        count++;
                        blocks[i] = 1;
                        temp = (struct block *)malloc(sizeof(struct block));
                        temp->block_no = i;
                        temp->next = NULL;
                        if (count == 2)
                        {
                            f[k].start_block->next = temp;
                            f[k].end_block = temp;
                        }
                        else
                        {
                            f[k].end_block->next = temp;
                            f[k].end_block = temp;
                        }
                        free--;
                    }
                    i++;
                }
                printf("File allocated to disk.\n");
                printf("Linked list of blocks allocated to this file: ");
                temp = f[k].start_block;
                while (temp->next != NULL)
                {
                    printf("%d--> ", temp->block_no);
                    temp = temp->next;
                }
                printf("%d\n", temp->block_no);
                k++;
            }
        }
        printf("\nAre there more files? (y/n): ");
        scanf(" %c", &c);
    }
    printf("\nFile\tStart\tLength\tEnd\n");
    for (int i = 0; i < k; i++)
        printf("%d\t%d\t%d\t%d\n", i + 1, f[i].start_block->block_no, f[i].length, f[i].end_block->block_no);
}