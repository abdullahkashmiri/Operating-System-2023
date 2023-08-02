// Abdullah Dar 21L-7512 OS LAB 9 BSCS 4G1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define size 1024 //size for shared memory segment

int main(int argc, char *argv[])
{
int fd;
int shmid;
key_t key;
char* shm;
char buff[100];
int num;

if(argc!=2)
{
printf("Errors in Command Entered!!\n");
exit(1);
}
fd = open(argv[1], O_RDONLY);
if(fd == -1)
{
printf("Error Opening File\n");
exit(1);
}

key = ftok("server.c",'R'); //key for shared memory file

shmid = shmget(key, size, 0644 | IPC_CREAT);

if(shmid == -1)
{
perror("Error while creating shared Memory EXITED!!\n");
exit(1);
}

    shm = shmat(shmid, (void *)0, 0);
if (shm == (char *)(-1)) 
{
    perror("Error attaching shared memory");
    exit(1);
}

while((num = read(fd, buff, sizeof(buff)))>0)
{
strncpy(shm, buff, num);
shm+=num;
}
*shm = '\0';
shmdt(shm);

printf("Client Terminated SuccessFully\n");
return 0;
}
