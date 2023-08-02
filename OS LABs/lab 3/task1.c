//21L-7512 Abdullah Dar OS lab 3 BSCS 4g1

#include <stdio.h>

int main(int argc, char *argv[])
{
int check = fork();

if(!check)
{
int size = argc - 1;
int i,j,temp;
int array[size];

for(i=0;i<size;i++)
array[i]=atoi(argv[i+1]);

for( i=0;i<size;i++)
{
for ( j=0;j<size-1; j++)
{
if(array[j]>array[j+1])
{
temp=array[j];
array[j]=array[j+1];
array[j+1]=temp;
}
}
}
   
printf("Array Sorted of size %d\n",size);

for(i=0;i<size;i++)
printf(" %d",array[i]);

printf("Program terminating parent ID is : %d child ID is : %d",getppid() ,getpid());
}
return 0;
}
