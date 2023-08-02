/*Question # 2: [Marks:10]
Write a multithreaded program that outputs prime numbers. This program should work as follows: The
user will run the program and will enter a number on the command line. The program will then create a separate thread that outputs all the prime numbers less than or equal to the number entered by the user.*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void* worker1(void* arg) {
    int num = *(int*) arg;
    printf("Received number: %d\n", num);
     if (num < 2) {
        printf("There are no prime numbers till %d.\n", num);
        pthread_exit(NULL);
    }
    printf("All prime numbers till %d:\n", num);
    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            printf("%d ,", i);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Data Not found in correct format\n");
        exit(1);
    }

    int num = atoi(argv[1]);

    pthread_t thread1;
    pthread_create(&thread1, NULL, worker1, &num);
    pthread_join(thread1,NULL);

    printf("Program Terminated SuccessFully 21L-7512 Q2\n");
    return 0;
}
//---END---
