//21L7512 Abdullah dar OS Quiz 1

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char * argv[])
{

int laptime=atoi(argv[1]), laps=atoi(argv[2]);
printf("\nlap Time is : %d seconds. and Total Laps are : %d.",laptime,laps);

clock_t starttime = clock();

int check = fork();

if(check)
{
wait();
}
else 
{
int i;
for(i=0;i<laps;i++)
{
sleep(laptime);
printf("\nLap Number :%d completed.Child PID : %d\n",i+1,getpid());
}
exit(0);
}

double time_taken = ((double)starttime)/CLOCKS_PER_SEC;
double sec=time_taken;
double min=sec/60;
double hr=min/60;

printf("Total Time in seconds %f",time_taken);
printf("\nTotal time taken : [hr/min/sec] : [%f/%f/%f], Parent PID :%d",hr,min,sec,getpid());


int c1=fork();
if(c1)
wait();

if(!c1)
{
printf("name Abdullah PID%d" ,getpid());
exit(0);
}
else
{
int c2=fork();
if(!c2)
{
printf("roll no 21l7512 PID%d" ,getpid());
exit(0);
}
else 
{
int c3=fork();
if(!c3)
{
printf("PID %d" ,getpid());
exit(0);
}
}
}

printf("\n\nProgram Terminated SuccessFully\n");
return 0;
}
