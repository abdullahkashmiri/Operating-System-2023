#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char*argv[])
{

char *wbuffer=argv[1];

int i;
printf("%s",wbuffer);
int stoparr[7];
for(i=0;i<7;i++)
stoparr[i]=0;
char *token = strtok(wbuffer," ");

char *str[7]={"a","the","an","of","to","in","and"};

while(token)
{
printf("token : %s\n",token);

// calculating frequencies of stop words
if(strcmp(token,"a")==0)
stoparr[0]++;
else if(strcmp(token ,"the")==0)
stoparr[1]++;
else if(strcmp(token , "an")==0)
stoparr[2]++;
else if(strcmp(token ,"of")==0)
stoparr[3]++;
else if(strcmp(token , "to")==0)
stoparr[4]++;
else if(strcmp(token ,"in")==0)
stoparr[5]++;
else if(strcmp(token,"and")==0)
stoparr[6]++;

token = strtok(NULL," ");
}
printf("PID %d Frequencies of stop words\n",getpid());
for(i=0;i<7;i++)
printf("%s : %d\n",str[i],stoparr[i]);


int fd = open ("fifopipe",O_WRONLY);
dup2(fd,1);
write(1,stoparr,7*sizeof(int));

return 0;
}
