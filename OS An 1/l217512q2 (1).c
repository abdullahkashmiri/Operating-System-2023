// ABDULLAH DAR 21L-7512 OS AN 1 Q2

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/time.h>


int main(int argc, char* argv[])
{
int num =  atoi(argv[1]);       // Extracting Number
printf("Entered Number is : %d\n",num);
printf("Series Given Below\n");
int fd[2];    // read write file descriptors 
while(num!=1)   // While number becomes 1
{
  pipe(fd);   // creating a pipe
  int id = fork();    // creating child process
  if(id > 0)      // for Parent Process
  {
  printf("PARENT ID : %d ",getpid());
  close(fd[1]);     // no need of write
  read(fd[0],&num,sizeof(int));   // reading
  close(fd[0]);     // reading complete
  wait(NULL);     // child termination wait
  }
  else if(id==0)    // child process
  {
  close(fd[0]);     // no need to read
  if(num%2==0)    // even calculations
  num/=2;
  else 
  num=(3*num)+1;    // odd calculations
  write(fd[1],&num,sizeof(int));    // writing to pipe
  close(fd[1]);     // writing complete
  printf("CHILD ID : %d ,",getpid());
  exit(0);        // child process to exit
  }
  printf(" NUM : %d. \n",num);     // Printing Number
}
return 0;
}
//END

