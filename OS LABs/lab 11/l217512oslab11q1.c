// ABDULLAH DAR 21L-7512 OS LAB 11 

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

void *worker1();
void *worker2();

int W = 10;
int X = 20;
int Y = 30;
int Z = 40;

sem_t sem1;
sem_t sem2;

int main(int argc, char* argv[]) {

sem_init(&sem1, 0, 0);
sem_init(&sem2, 0, 0);

    printf("Enter the value of X: ");
    scanf("%d", &X);
    printf("Enter the value of Y: ");
    scanf("%d", &Y);
    printf("Enter the value of Z: ");
    scanf("%d", &Z);
    printf("Enter the value of W: ");
    scanf("%d", &W);

pthread_t thread1, thread2;

pthread_create(&thread1, NULL, worker1, NULL);
pthread_create(&thread2, NULL, worker2, NULL);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);


return 0;
}
// ----------- worker no 1
void* worker1() {

int w1 = 0, x1 = 0, y1 = 0, z1 = 0;

z1 = Z;
x1 = z1 + 2;
X = x1;

sem_post(&sem1);  
sem_wait(&sem2); 

z1 = Z;
y1 = z1 * 5;
Y = y1;

sem_post(&sem1);  
sem_wait(&sem2); 

x1 = X;
y1 = Y;
int s1 = x1 + y1;

printf("X = %d\n",s1);
}
// --------- worker no 2 
void* worker2() {

int w1 = 0, x1 = 0, y1 = 0, z1 = 0;

sem_wait(&sem1);  

x1 = X;
z1 = x1 * 2;
Z = z1;

sem_post(&sem2);  
sem_wait(&sem1);

y1 = Y;
w1 = y1 + 5;
W = w1;

sem_post(&sem2);  

z1 = Z;
w1 = W;
int s2 = z1 + w1;

printf("X = %d\n",s2);
}
//---- END 

