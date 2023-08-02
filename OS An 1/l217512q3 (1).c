// ABDULLAH DAR 21L-7512 OS AN 1 Q3

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/time.h>

int main(int argc, char *argv[])
{
struct timeval tv1, tv2;
struct timezone tz1, tz2;
gettimeofday(&tv1,&tz1);
printf("Start Time micro_sec : %ld\n",tv1.tv_usec);
int id = fork();
if(id>0)
{
printf("PARENT ID : %d\n",getpid());
wait(NULL);
}
else
{
printf("CHILD ID : %d\nWorking of Command : %s\n",getpid(),argv[1]);
char *args[argc];
int i = 0;
for(i=0;i<argc-1;i++)
args[i]=argv[i+1];
args[i]=NULL;
execvp(args[0],args);
exit(0);
}
gettimeofday(&tv2,&tz2);
printf("End Time micro_sec : %ld\n",tv2.tv_usec);
printf("Elapsed Time : %ld micro_seconds\n",(tv2.tv_usec - tv1.tv_usec));

printf("Program Terminated SuccessFully\n");
return 0;
}
//END
