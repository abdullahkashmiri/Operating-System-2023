#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc, char* argv[])
{
    int check = fork();
    
	if(!check)	
	{	
	    printf("child is replacing itself now \n");
	    char* args[] = {"fib", argv[1], NULL};
	    execv("./fib.exe", args);
	}
	else
		wait(NULL);

return 0;
}