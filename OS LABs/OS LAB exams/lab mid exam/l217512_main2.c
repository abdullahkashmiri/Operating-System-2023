#include"l217512_header.h"

int main(int argc, char*argv[])
{
char *str=argv[1];
printf("main str %s,  PID : %d  \n",str,getpid());

int id = fork();
if(id>0)
wait(NULL);
else {

char* argv1[]={"./l217512_freq",NULL};
execvp(argv1[0],argv1);
int fd1 =open("fifopipe2",O_WRONLY);
int len = strlen(str);
write(fd1,str,len);

}

return 0;
}
