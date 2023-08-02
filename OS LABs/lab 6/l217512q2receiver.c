//ABDULLAH DAR OS LAB 6 21L-7512
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char* argv[])
{
int x,i;
int size = 0;
x = open("pipe2",O_RDONLY);
read(x,&size,sizeof(int));
int arr[size];
printf("SIZE %d\n",size);
read(x,arr,size*sizeof(int));
printf("Receiver Process Having PID %d received the data : ",getpid());
for(i=0;i<size;i++)
printf("%d, ",arr[i]);
printf("\n");
sleep(3);
close(x);
x = open("pipe2",O_WRONLY);
int sum =0;
for(i=0;i<size;i++)
{
sum+=arr[i];
}
write(x,&sum,sizeof(int));
printf("Receiver Process Having PID %d sent the data back : %d\n",getpid(),sum);
close(x);
printf("Receiver Question no 2 terminated SuccessFully\n");
return 0;
}
