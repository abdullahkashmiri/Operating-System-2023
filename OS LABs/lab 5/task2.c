//21L-7512 Abdullah dar OS lab 5

#include<stdio.h>
#include<string.h>

int main(int argc,char*argv[])
{
int size = 5;
int send_arr[5] = {1,2,3,4,5}, i;
int rev_arr[5],sum = 0;


int fd1[2];
int fd2[2];
pipe(fd1);
pipe(fd2);

int id = fork();
if(id>0)
{
printf("Parent Process ID : %d\n",getpid());
printf("Sent Array : ");
for(i=0;i<size;i++)
{
printf("%d,",send_arr[i]);
}
printf("\n");
// writing to pipe
close(fd1[0]);
write(fd1[1],send_arr,size*sizeof(int));
close(fd1[1]);
// reading sum from pipe
close(fd2[1]);
read(fd2[0],&sum ,sizeof(int));
close(fd2[0]);
printf("Sum received from Child : %d\n",sum);
wait(NULL);
}
else 
{
printf("Child Process ID : %d\n",getpid());
//reading from file
close(fd1[1]);
read(fd1[0],rev_arr,size*sizeof(int));
close(fd1[0]);
printf("Received Array : ");
for(i=0;i<size;i++)
{
sum+=rev_arr[i]; // calculating sum
printf("%d,",rev_arr[i]);
}
printf("\n");
close(fd2[0]);
write(fd2[1],&sum,sizeof(int));// sending sum parent
close(fd2[1]);
}

return 0;
}
