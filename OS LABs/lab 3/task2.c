//21L-7512 Abdullah Dar OS lab 3 BSCS 4g1


#include <stdio.h>

int main(int argc, char *argv[])
{

int size = argc - 1;
int i,j,temp;
int array[size];

for(i=0;i<size;i++)
array[i]=atoi(argv[i+1]);

int check = fork();
int check2;
if(check)
wait();
if(!check)
{
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
   
printf("Child 1 Asscending sort\n");

for(i=0;i<size;i++)
printf(" %d",array[i]);

printf("Parent ID is : %d Child 1 ID is : %d\n",getppid() ,getpid());
}

if(check)
{
check2=fork();
if(check2)
wait();
if(!check2)
{
for( i=0;i<size;i++)
{
for ( j=0;j<size-1; j++)
{
if(array[j]<array[j+1])
{
temp=array[j];
array[j]=array[j+1];
array[j+1]=temp;
}
}
}

   
printf("Child 2 Descending sort \n");

for(i=0;i<size;i++)
printf(" %d",array[i]);

printf("Parent ID is : %d Child 2 ID is : %d\n",getppid() ,getpid());

}
}
if(check>0 && check2>0)
{
printf("Parent ID is : %d and its Grand Parent ID is : %d\n",getpid() ,getppid());
}

return 0;
}
