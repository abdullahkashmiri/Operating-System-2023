

//21l7512 abdullah dar quiz 2

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>


sem_t sem1;
sem_t sem2;
sem_t sem3;

//sem_post(&sem1);  
//sem_wait(&sem2); 

void* worker1()
{

printf("a");
sem_post(&sem1);
sem_post(&sem2);
sem_wait(&sem1); 
printf("a");
printf("a");
sem_post(&sem2);
sem_wait(&sem1);
printf("a");
printf("a");
sem_post(&sem2);
sem_wait(&sem1);
printf("a");
printf("a");
sem_post(&sem2);
sem_wait(&sem1);
printf("a");
sem_post(&sem2);
sem_post(&sem2);

return NULL;
}

void* worker2()
{
sem_wait(&sem1); 
printf("b");
sem_post(&sem3);
sem_wait(&sem2); 
printf("b");
sem_post(&sem1);
sem_wait(&sem2); 
printf("b");
sem_post(&sem3);
sem_wait(&sem2);
printf("b");
sem_post(&sem3);
sem_wait(&sem2);

printf("b");
sem_post(&sem1);
sem_wait(&sem2);

printf("b");
sem_post(&sem3);
sem_wait(&sem2);
printf("b");
sem_post(&sem1);
sem_wait(&sem2);


return NULL;
}

void* worker3()
{

sem_wait(&sem2); 
sem_wait(&sem3); 
printf("c");
printf("c");
sem_post(&sem2);
sem_wait(&sem3); 
printf("c");
sem_post(&sem1);
sem_wait(&sem3);
printf("c");
printf("c");
sem_post(&sem2);
sem_wait(&sem3); 
printf("c");
printf("c");
sem_post(&sem2);
sem_wait(&sem3); 
 
return NULL;
}

int main(int argc, char* argv[])
{

sem_init(&sem1, 0, 0);
sem_init(&sem2, 0, 0);
sem_init(&sem3, 0, 0);

pthread_t thread1;
pthread_t thread2;
pthread_t thread3;

pthread_create(&thread1, NULL, worker1, NULL);
pthread_create(&thread2, NULL, worker2, NULL);
pthread_create(&thread3, NULL, worker3, NULL);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
pthread_join(thread3, NULL);

printf("Program Terminated SuccessFuly\n");
return 0;
}

//---

