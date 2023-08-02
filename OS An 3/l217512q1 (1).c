/*Question # 1: [Marks:10]
Write a multithreaded program that calculates variousstatistical values for a list of numbers. This program will be passed a series of numbers on the command line and will then create three separate worker threads. One thread will determine the average of the numbers, the second will determine the maximum value, and the third will determine the mini-mum value.
For example, suppose your program is passed the integers
90 81 78 95 79 72 85
The program will report
The average value is 82
The minimum value is 72
The maximum value is 95
The variables representing the average, minimum, and maximum values will be stored globally. The
worker threads will set these values, and the parent thread will output the values once the workers have exited.*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>

int average;
int max_val;
int min_val;
int size;

void* worker1(void* arg) // for average
{
	int* array = (int*) arg;
	int sum = 0,i;
	for(i=0;i<size;i++)
	sum+=array[i];
	average = sum/size;
	printf("Worker no 1 executed\n");
	pthread_exit(NULL);
}

void* worker2(void* arg) // for max val
{
	int* array = (int*) arg;
	int max = array[0],i;
	for(i=0;i<size;i++)
	if(max<array[i])
	max=array[i];
	max_val = max;
	printf("Worker no 2 executed\n");
	pthread_exit(NULL);
}

void* worker3(void* arg) // for min val
{
	int* array = (int*) arg;
	int min = array[0],i;
	for(i=0;i<size;i++)
	if(min>array[i])
	min=array[i];
	min_val = min;
	printf("Worker no 3 executed\n");
	pthread_exit(NULL);
}


int main(int argc, char* argv[])
{
if(argc == 1)
{
printf("Data Not found\n");
exit(1);
}
int i;
size = argc-1;
printf("Data Entered is : ");
int array[argc-1];
for(i = 0; i < size ; i++)
{
printf("%d, ",atoi(argv[i+1]));
array[i]=atoi(argv[i+1]);
}
printf("\n");
    
pthread_t thread1, thread2, thread3;

pthread_create(&thread1, NULL, worker1, (void*) array);
pthread_create(&thread2, NULL, worker2, (void*) array);
pthread_create(&thread3, NULL, worker3, (void*) array);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
pthread_join(thread3,NULL);

printf("Average value of DATA is : %d\n",average);
printf("Minumum value of DATA is : %d\n",min_val);
printf("Maximum value of DATA is : %d\n",max_val);

printf("Program Terminated SuccessFully 21L-7512 Q1\n");
return 0;
}
// ---END---