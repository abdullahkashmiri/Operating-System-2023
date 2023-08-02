
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <errno.h>
#include <ctype.h>

void *worker(void* n)
{
printf("Thread_ID : %ld, Process_ID : %d\n",pthread_self(), getpid());
int i,sum=0;
for(i=1;i<=(int)n;i++)
sum+=i;
printf("SUM is : %d\n",sum);
pthread_exit(0);
}

int main(int argc, char* argv[])
{

int N = atoi(argv[1]);
 
printf("Number for summation is  N : %d.\n",N);

pthread_t threadID;
pthread_create(&threadID, NULL, worker, (void*)N);
pthread_join(threadID,NULL);

return 0;
}
