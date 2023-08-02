//21L7512 Abdullah dar OS LAB 10

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<signal.h>

int laptime = 0;
int laps = 0;

void totaltime()
{
    int elapsed_time = laptime*laps;
    printf("Total Time in seconds is : %d\n",elapsed_time);
}
void handler(int sig)
{
    if(sig == SIGCHLD)
    {
        printf("\nReceived SIGCHLD\n");
        totaltime();
    }
    exit(0);
}
 
int main(int argc, char * argv[])
{

printf("Enter Lap Time in seconds : ");
scanf("%d",&laptime);

printf("Enter Number of Lap in seconds : ");
scanf("%d",&laps);

if(laps<=0)
	{
		printf("INVALID LAPS\n");
		exit(1);
		}
if(laptime<0)
	{
		printf("INVALID LAP TIME\n");
		exit(1);
	}
printf("\nLap Time is : %d seconds. and Total Laps are : %d\n",laptime,laps);

int check = fork();

if(check==0)// child
{
    int i;
    for(i=0;i<laps;i++)
    {
        sleep(laptime);
        printf("\nLap Number : %d completed. Child PID : %d",i+1,getpid());
    }
    exit(0);
}
else
{
    if(signal(SIGCHLD,handler) == SIG_ERR)
    {
        printf("Could not Catch SIGINT\n");
    }
    while(1);
}

printf("\n\nProgram Terminated SuccessFully\n");
return 0;
}