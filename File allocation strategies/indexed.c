#include <stdio.h>
#include <stdlib.h>
#define np 100
struct index_block
{
    int index;
    int block_no[np];
    struct index_block *next;
} *temp;

struct file
{
    int length;
    struct index_block *index_block;
} f[10];

void main()
{
    int n, blocks[100], free = 0, index, length, count = 0, k = 0, index_block[100];
    char c = 'y';
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    free = n;
    for (int i = 0; i < n; i++)
        blocks[i] = 0;
    while (c == 'y' || c == 'Y')
    {
        printf("Enter file index block number: ");
        scanf("%d", &index);
        if (index >= n || index < 0)
        {
            printf("Invalid index block number! Please enter a valid index.\n");
        }
        else if (blocks[index] == 1)
        {
            printf("Index block already allocated! No allocation possible.\n");
        }
        else
        {
            printf("Enter file length: ");
            scanf("%d", &length);
            if (length > free)
            {
                printf("File cannot be allocated!!\nInsufficient space in the disk.\n");
            }
            else
            {
                count = 0;
                f[k].length = length;
                temp = (struct index_block *)malloc(sizeof(struct index_block));
                temp->index = index;
                temp->next = NULL;
                f[k].index_block = temp;
                free--;
                blocks[index] = 1;
                for (int i = 0; i < n && count < length; i++)
                {
                    if (blocks[i] == 0)
                    {
                        blocks[i] = 1;
                        f[k].index_block->block_no[count] = i;
                        count++;
                    }
                    free--;
                }
                printf("File allocated to disk with index block\n");
                temp = f[k].index_block;
                for (int i = 0; i < length-1; i++)
                    printf("%d->%d\n", temp->index,temp->block_no[i]);
                printf("%d->%d\n", temp->index, temp->block_no[length - 1]);
                k++;
            }
        }
        printf("\nAre there more files? (y/n): ");
        scanf(" %c", &c);
    }
    printf("file\tindex\tlength\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, f[i].index_block->index, f[i].length);
    }
}