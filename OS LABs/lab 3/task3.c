//21L-7512 Abdullah Dar OS lab 3 BSCS 4g1


#include <stdio.h>

int main(int argc, char *argv[])
{
int inp;
printf("Enter an integer between 1 to 10 : ");
scanf("%d",&inp);

if(inp<0||inp>10)
printf("Wrong input!!");
else{
printf("Number is = %d\n",inp);
int i,check=fork();
if(check)
wait();
else{
for(i=0;i<inp;i++)
{
if(check==0)
{printf("My ID is : %d and My Parent ID is : %d\n",getpid() ,getppid());
check=fork();}
if(check>0)
wait();
}}}
return 0;
}
