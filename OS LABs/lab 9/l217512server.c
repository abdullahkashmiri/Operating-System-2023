// Abdullah Dar 21L-7512 OS LAB 9 BSCS 4G1

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>

#define size 1024

int main()
{
    int shmid;  
    key_t key;  
    char *shm;  
    int data;  
    int sum = 0;  
    float avg = 0.0;  
    int count = 0;  

    key = ftok("server.c", 'R'); 
    shmid = shmget(key, size, 0644 | IPC_CREAT); 
    shm = shmat(shmid, (void *)0, 0); 
    int len = strlen(shm), i;
    for(i=len-1;i>-1;i--)
    { 
        data = (int)shm[i];  
        data -= 48;  
        if(data>=0 && data<= 9)  
        {
            sum += data;  
            count++;  
        }
    }
    if (count) 
    {
        avg = (float)sum / count; 
    }

    printf("SUM : %d, AVERAGE : %f\n", sum, avg); 
    shmdt(shm); 

    shmctl(shmid, IPC_RMID, NULL); 
    
    printf("Server Terminated SuccessFully\n");
    return 0;
}
