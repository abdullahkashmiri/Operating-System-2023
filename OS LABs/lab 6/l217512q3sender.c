//ABDULLAH DAR OS LAB 6 21L-7512
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char* argv[])
{
int a,b;
a = atoi(argv[2]);
b = atoi(argv[3]);
char *c = argv[1];
printf("The Input is : %d %s %d \n",a,c,b);
int x = open("pipe3",O_WRONLY);
write(x,&a,sizeof(int));
write(x,&b,sizeof(int));
write(x,c,sizeof(char*));

printf("Sender Process Having PID %d sent the data to Receiver ",getpid());
close(x);
sleep(3);
x = open("pipe3",O_RDONLY);
int ans = 0;
read(x,&ans,sizeof(int));
printf("Sender Process Having PID %d received the data back [ANS] : %d\n",getpid(),ans);
close(x);
printf("Sender Question no 3 terminated SuccessFully\n");
return 0;
}
