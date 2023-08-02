
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <errno.h>
#include <ctype.h>

int * arr, size, sum = 0, even = 0,odd = 0;

void *worker(void* n)
{
    printf("Fibonacci Thread_ID : %ld, Process_ID : %d\n",pthread_self(), getpid());
    int i,num = (int)n;
    int a1=0,a2=1,a3,count=2;
   
    size = num;
    arr = (int*) malloc(size * sizeof(int));
    a1=0;a2=1;
    arr[0]=a1;
    arr[1]=a2;
    count=2;
    while(count < num)
    {
        a3= a2;
        a2=a1+a2;
        a1=a3;
            arr[count]=a2;
            count++;
    }
    pthread_exit(0);
}


void *evenF()
{
    printf("EVEN Thread_ID : %ld, Process_ID : %d\n",pthread_self(), getpid());
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]%2==0)
        even++;
    }
    pthread_exit(0);
}

void *oddF()
{
    printf("ODD Thread_ID : %ld, Process_ID : %d\n",pthread_self(), getpid());
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]%2!=0)
        odd++;
    }
    pthread_exit(0);
}

void *sumF()
{
    printf("SUM Thread_ID : %ld, Process_ID : %d\n",pthread_self(), getpid());
    int i;
    for(i=0;i<size;i++)
    sum+=arr[i];
     FILE *out_file = fopen("sum.txt", "w");
     if (out_file == NULL)
    {  
        printf("Error! Could not open file fun\n");
        pthread_exit(0);
    }
    
     fputc("SUM is", out_file);
     fputc(sum, out_file);
    pthread_exit(0);
}

int main(int argc, char* argv[])
{
int N = argv[1];

printf("N : %d.\n",N);
pthread_t threadID[4];
pthread_create(&threadID[0], NULL, worker, (void*)N);
pthread_join(threadID[0],NULL);
pthread_create(&threadID[1],NULL,evenF,NULL);
pthread_create(&threadID[2],NULL,oddF,NULL);
pthread_create(&threadID[3],NULL,sumF,NULL);
int i;
for(i=1;i<4;i++)
pthread_join(threadID[i],NULL);

printf("Fibonacci Series : ");
for(i=0;i<size;i++)
printf(" %d,",arr[i]);
printf("\nEVEN Numbers in it are : %d\n",even);
printf("ODD Numbers in it are : %d\n",odd);
printf("SUM of Numbers are : %d\n",sum);

return 0;
}
