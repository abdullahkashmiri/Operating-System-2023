#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char*argv[])
{

char *wbuffer=argv[1];

int i;
printf(" worker no 2   buff %s  \n",wbuffer);

char *token = strtok(wbuffer," ");
int count=0;
int length=0;
while(token)
{
printf("token : %s\n",token);

// calculating words of stop words
count++;
length += strlen(token);
printf("len += %d  \n",length);
token = strtok(NULL," ");
}

printf("Num of words : %d\n", count);
printf("Total length of words : %d\n", length);
float avg = ((float)length)/((float)count);
printf("Average word length: %f\n", avg);

int fd = open ("fifopipe",O_WRONLY);
dup2(fd,1);

write(1,&count,sizeof(int));
write(1,&avg,sizeof(float));

printf("Worker 2 completed\n");

return 0;
}
