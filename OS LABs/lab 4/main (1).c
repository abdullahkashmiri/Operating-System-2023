#include<stdio.h>

int main(int argc, char* argv[])
{
printf("Main.c PID : %d",getpid());
char* args[]={"myinfo",NULL};
execv("./myinfo",args);
printf("Error Occurred!! Call Technical support");
return 0;
}
