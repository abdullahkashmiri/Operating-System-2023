//ABDULLAH DAR OS LAB 6 21L-7512
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char* argv[])
{
int x,i;
char str[100];
x = open("pipe1",O_RDWR);
read(x,str,100);
printf("Receiver Process Having PID %d received the data : %s\n",getpid(),str);
int size = strlen(str);
for(i=0;i<size;i++)
{
if(str[i]>='A' && str[i]<='Z')
  str[i]+=32;
  else if(str[i]>='a' && str[i]<='z')
  str[i]-=32;
}
write(x,str,size*sizeof(char));
printf("Receiver Process Having PID %d sent the data back : %s\n",getpid(),str);
close(x);
printf("Receiver Question no 1 terminated SuccessFully\n");
return 0;
}
