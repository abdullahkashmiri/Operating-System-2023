//21L-7512 Abdullah dar OS lab 5

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc,char*argv[])
{

FILE *in_file  = fopen(argv[1], "r");// file handleing
FILE *out_file = fopen(argv[2], "w");
     
if (in_file == NULL || out_file == NULL)
{  
	printf("Error! Could not open file\n");
	exit(-1);
}

char ch,send_buff[100];// copying to buffer
int i=0;
while ((ch = fgetc(in_file)) != EOF)
 {
	send_buff[i]=ch;
	i++;
}

int size = strlen(send_buff); // calculating length
char rev_buff[size];

int fd[2];
pipe(fd);
int id = fork();
if(id>0)
{
printf("Parent Process ID : %d\n",getpid());
printf("Size of Content to send : %d\n",size);
printf("Content to send : ");
for(i=0;i<size;i++)// printing buffer
{
printf("%c",send_buff[i]);
}
printf("\n");
//writing to pipe
close(fd[0]);
write(fd[1],&size,sizeof(int));
write(fd[1],send_buff,size);
close(fd[1]);
wait(NULL);
}
else 
{
printf("Child Process ID : %d\n",getpid());
//reading from file
close(fd[1]);
int size1=0;
read(fd[0],&size1,sizeof(int));
printf("Size of Content to received : %d\n",size1);// printing buffer size
read(fd[0],rev_buff,size1);
close(fd[0]);

printf("Content Received : ");// printing buffer
for(i=0;i<size1;i++)
{
printf("%c",rev_buff[i]);
fputc(rev_buff[i], out_file);}
}
printf("\n");
return 0;
}
