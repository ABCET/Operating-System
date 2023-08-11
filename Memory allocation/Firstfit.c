#include <stdio.h>
int process_size[10];
int block_size[10];
int block_allocated[10];
int process_alloc[10];
void main()
{
    int m, n;
    printf("input the no. of blocks:");
    scanf("%d", &m);
    printf("input the no. of processes:");
    scanf("%d", &n);
    printf("input block sizes:\n");
    for (int i = 0; i < m; i++)
    {
        printf("block %d:", i);
        scanf("%d", &block_size[i]);
    }
    printf("input process sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("process %d:", i);
        scanf("%d", &process_size[i]);
    }
    for (int i = 0; i < m; i++)
        block_allocated[i] = 0;
    for (int i = 0; i < n; i++)
        process_alloc[i] = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (block_allocated[j] == 0)
            {
                if (block_size[j] >= process_size[i])
                {
                    block_allocated[j] = 1;
                    process_alloc[i] = j;
                    break;
                }
            }
        }
    }
    printf("+-------------+--------------+-----------------+---------------------+------------------------+\n");
    printf("| Processs No | Process size | Allocated block | Allocated blocksize | Internal fragmentation |\n");
    printf("+-------------+--------------+-----------------+---------------------+------------------------+\n");
    for (int i = 0; i < n; i++)
    {
        int j = process_alloc[i];
        if (process_alloc[i] != -1)
            printf("| %11d | %12d | %15d | %19d | %22d |\n", i, process_size[i], process_alloc[i], block_size[j], block_size[j] - process_size[i]);
        else
            printf("| %11d | %12d | %15s | %19s | %22s|\n", i, process_size[i], "--", "--", "--");
    }
    printf("+-------------+--------------+-----------------+---------------------+------------------------+\n");
}