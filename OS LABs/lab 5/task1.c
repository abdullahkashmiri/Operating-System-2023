//21L-7512 Abdullah dar OS lab 5

#include<stdio.h>
#include<string.h>

int main(int argc,char*argv[])
{

char * send_buff = "Hello There.";
int size = strlen(send_buff),i;
char rev_buff[size];

int fd[2];
pipe(fd);
int id = fork();
if(id>0)
{
printf("Parent Process ID : %d\n",getpid());
printf("Original String : ");
for(i=0;i<size;i++)
{
printf("%c",send_buff[i]);
}
printf("\n");
//writing to pipe
close(fd[0]);
write(fd[1],send_buff,size);
close(fd[1]);
wait(NULL);
}
else 
{
printf("Child Process ID : %d\n",getpid());
//reading from file
close(fd[1]);
read(fd[0],rev_buff,size);
close(fd[0]);

printf("Modified String : ");
for(i=0;i<size;i++)
{
if(rev_buff[i]>'A' && rev_buff[i]<'Z')
rev_buff[i]+=32;
else if(rev_buff[i]>'a'&&rev_buff[i]<'z')
rev_buff[i]-=32;

printf("%c",rev_buff[i]);
}
}
printf("\n");
return 0;
}
