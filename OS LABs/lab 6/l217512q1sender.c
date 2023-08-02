//ABDULLAH DAR OS LAB 6 21L-7512
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char* argv[])
{
char *str = "Hello There";
int size = strlen(str), x;
printf("The String is : %s having size : %d\n",str,size);
x = open("pipe1",O_RDWR);
write(x,str,size*sizeof(char*));
printf("Sender Process Having PID %d sent the data : %s\n",getpid(),str);
sleep(3);
char strr[20];
read(x,strr,size);
printf("Sender Process Having PID %d received the data back : %s\n",getpid(),strr);
close(x);
printf("Sender Question no 1 terminated SuccessFully\n");
return 0;
}
