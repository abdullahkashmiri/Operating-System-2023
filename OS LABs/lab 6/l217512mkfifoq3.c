//ABDULLAH DAR OS LAB 6 21L-7512
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
int x = mkfifo("pipe3",0777);
printf("pipe3 created SuccessFully");
printf("\nProgram Terminated SUccessFully\n");
return 0;
}

