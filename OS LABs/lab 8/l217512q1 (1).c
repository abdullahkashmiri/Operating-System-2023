#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *worker()
{
printf("Thread_ID : %ld, Process_ID : %d\n",pthread_self(), getpid());
 
pthread_exit(0);
}

int main(int argc, char* argv[])
{

int N = atoi(argv[1]);
printf("Creating N : %d of threads.\n",N);
int i;
pthread_t threadID[N];
for(i=0;i<N;i++)
{

pthread_create(&threadID[i],NULL,worker,NULL);


}

for(i=0;i<N;i++)
pthread_join(threadID[i],NULL);

return 0;
}
