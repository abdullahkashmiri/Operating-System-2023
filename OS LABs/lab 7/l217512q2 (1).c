// 21l7512 abdullah dar os lab 7 q2
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
char buffer[100];
printf("output file : %s\n",argv[3]);

int outfile_desc = open(argv[3], O_WRONLY);

if(outfile_desc < 0 )
{
printf("Error Opening File\n");
}
else 
{
dup2(outfile_desc,1);
int id = fork();
if(id>0)
wait(NULL);
else 
execlp(argv[1],argv[1], argv[2],NULL);
}

close(outfile_desc);
return 0;
}
