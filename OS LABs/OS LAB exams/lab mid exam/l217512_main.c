#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc, char*argv[])
{

char buffer[200];
int fd;
int id1;
int id2;
fd=open("input.txt",O_RDONLY);
dup2(fd,0);
int size = read(0,&buffer,200);
size--;
printf("str extracted : %s size %d PID: %d\n",buffer,size,getpid());

id1=fork();
if(id1>0)//parent
{
printf("Parent PID : %d\n", getpid());
wait(NULL);
}

else if(id1==0)//child worker no 1
{
printf("Worker 1 PID : %d\n", getpid());
char* argv1[]={"./l217512_worker1",buffer,NULL};
execvp(argv1[0],argv1);

}

int arr[7];
 fd = open("fifopipe",O_RDONLY);
read(fd , arr, 7*sizeof(int));

id2=fork();
if(id2>0)//parent
{
printf("Parent PID : %d\n", getpid());
wait(NULL);
}

else if(id2==0)//child worker no 2
{
printf("Worker 2 PID : %d\n", getpid());
char* argv1[]={"./l217512_worker2",buffer,NULL};
execvp(argv1[0],argv1);

}

int count=0;
float avg=0.0;
 fd = open("fifopipe",O_RDONLY);
read(fd , &count, sizeof(int));
read(fd , &avg , sizeof(float));

printf("PARENT COUNT WoRDS %d\n",count);

printf("PARENT AVG of  WoRDS %f\n",avg);
return 0;
}
