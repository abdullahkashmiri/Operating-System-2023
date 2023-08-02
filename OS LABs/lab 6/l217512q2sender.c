//ABDULLAH DAR OS LAB 6 21L-7512
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char* argv[])
{
int arr[5] = {1,2,3,4,5};
int size = 5,x,i;
printf("The Array is : %d,%d,%d,%d,%d having size : %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],size);
x = open("pipe2",O_WRONLY);
write(x,&size,sizeof(int));
printf("size  %d\n",size);
write(x,arr,size*sizeof(int));
printf("Sender Process Having PID %d sent the data : ",getpid());
for(i=0;i<size;i++)
printf("%d, ",arr[i]);
printf("\n");
close(x);
sleep(3);
x = open("pipe2",O_RDONLY);
int sum = 0;
read(x,&sum,sizeof(int));
printf("Sender Process Having PID %d received the data back [SUM] : %d\n",getpid(),sum);
close(x);
printf("Sender Question no 2 terminated SuccessFully\n");
return 0;
}
