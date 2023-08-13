#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

void main()
{
    int pid;
    char buff[100];
    key_t key = ftok("shmfile", 43);
    pid = fork();
    if (pid == 0)
    {
        printf("Child process id:%d\n", getpid());
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
        printf("Shared memory id: %d\n", shmid);
        void *shm = shmat(shmid, NULL, 0);
        printf("Shared memory attached at: %p\n", shm);
        printf("Enter data to be written to shared memory: \n");
        scanf("%[^\n]", buff);
        printf("Child process is writing %s to shared memory\n", buff);
        strcpy(shm, buff);
        shmdt(shm);
    }
    if (pid > 0)
    {
        int status;
        printf("Parent process waiting for child to finish writing\n\n");
        pid = wait(&status);
        printf("\nChild process id:%d finished writing\n", pid);
        printf("\nParent process id:%d\n", getpid());
        printf("Parent process is reading from shared memory\n");
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
        void *shm = shmat(shmid, NULL, 0);
        printf("Shared memory attached at: %p\n", shm);
        printf("Data read from shared memory: %s\n", (char *)shm);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }
}
