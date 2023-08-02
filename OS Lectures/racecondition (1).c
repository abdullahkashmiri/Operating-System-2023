#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *func1();
void *func2();
int shared=1;  //shared variable
int main()
{
 pthread_t thread1,thread2;
 pthread_create(&thread1,NULL,func1,NULL);
 pthread_create(&thread2,NULL,func2,NULL);
 // adding threads to Thread Pool 
 pthread_join(thread1,NULL);
 pthread_join(thread2,NULL);
 //prints the value of shared variable
 printf("Final value of shared variable is %d\n ",shared);
}

void *func1()
{
 int x;
 x=shared;
 printf("Thread1 read shared variable value %d\n",x);
 x++;
 printf("Local Updation by Thread1 %d\n",x);
 sleep(1);
 shared=x;
 printf("Thread1: Shared Variable value Updated: %d\n",shared);
 }
 
 
void *func2()
{
 int y;
 y=shared;
 printf("Thread2 read shared variable value %d\n",y);
 y--;
 printf("Local Updation by Thread2 %d\n",y);
 sleep(1);
 shared=y;
 printf("Thread2: Shared Variable value Updated: %d\n",shared);
 }
 
 

 


