#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid_p2, pid_p3, pid_p4;
    int status;

    printf("P1 - PID: %d\n", getpid());

    pid_p2 = fork();
    if (pid_p2 == 0)
    {
        printf("P2 - PID: %d, Parent PID: %d\n", getpid(), getppid());
        pid_p4 = fork();
        if (pid_p4 == 0)
        {
            printf("P4 - PID: %d, Parent PID: %d\n", getpid(), getppid());
        }
        else
        {
            wait(&status);  
            pid_p3 = fork();
            if (pid_p3 == 0)
            {
                printf("P5 - PID: %d, Parent PID: %d\n", getpid(), getppid());
            }
        }
    }
    else
    {
        wait(&status);  
        pid_p3 = fork();
        if (pid_p3 == 0)
        {
            printf("P3 - PID: %d, Parent PID: %d\n", getpid(), getppid());
            pid_p4 = fork();
            if (pid_p4 == 0)
            {
                printf("P6 - PID: %d, Parent PID: %d\n", getpid(), getppid());
            }
        }
        else
        {
            wait(&status);  
            wait(&status);  
        }
    }

    return 0;
}
