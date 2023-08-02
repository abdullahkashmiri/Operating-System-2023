//ABDULLAH DAR OS LAB 6 21L-7512s
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char* argv[])
{
int x,i,a,b;
char c;
x = open("pipe3",O_RDONLY);
read(x,&a,sizeof(int));
read(x,&b,sizeof(int));
read(x,&c,sizeof(char));

printf("Receiver Process Having PID %d received the data : %d %c %d\n",getpid(),a,c,b);
close(x);
sleep(3);
x = open("pipe3",O_WRONLY);
int ans =0;
if(c=='+')
ans = a+b;
else if(c=='-')
ans = a-b;
else if(c=='*')
ans = a*b;
else if(c=='/')
ans = a/b;

write(x,&ans,sizeof(int));
printf("Receiver Process Having PID %d sent the data back : %d\n",getpid(),ans);
close(x);
printf("Receiver Question no 3 terminated SuccessFully\n");
return 0;
}
