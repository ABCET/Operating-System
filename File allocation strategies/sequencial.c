#include <stdio.h>
struct file
{
    int start_block;
    int length;
}f[10];
void main()
{
    int n, b, l, k=0, flag, block[100];
    char c = 'y';
    printf("No of blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        block[i] = 0;
    while (c == 'y' || c == 'Y')
    {
        flag = 0;
        printf("Enter file starting block: ");
        scanf("%d", &b);
        printf("Enter file length: ");
        scanf("%d", &l);
        if (l > n)
            printf("File cannot be allocated!!\nInsufficient space in the disk.\n");
        else
        {
            for (int j = b; j < b + l; j++)
            {
                if (block[j] == 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("File allocated to blocks: ");
                for (int j = b; j < b + l; j++)
                {
                    block[j] = 1;
                    printf("%d ", j);
                }
                printf("\n");
                f[k].start_block=b;
                f[k].length=l;
                k++;
            }
            else
                printf("File cannot be allocated!!\nSome blocks are already allocated.\n");
        }
        printf("\nAre there more files? (y/n): ");
        scanf(" %c", &c);
    }
    printf("\nFile\tStart\tLength\n");
    for(int i=0;i<k;i++)
        printf("%d\t%d\t%d\n", i+1, f[i].start_block, f[i].length);
    
}