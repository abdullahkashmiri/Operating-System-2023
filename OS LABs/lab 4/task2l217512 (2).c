#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char*argv[])
{
	int check=fork();

	if(!check)
	{
		printf("Creating Directory\n");
		int dir=execlp("mkdir","mkdir","demo_folder",NULL);
	}
	else
		wait(NULL);

	check = fork();

	if(!check)
	{
		printf("Creating FIles\n");
		char* args[]={"touch","demo_folder/file1.txt","demo_folder/file2.txt",NULL};
		execvp("touch",args);
	}
	else 
		wait(NULL);

	check = fork();
	
	if(!check)
	{
		printf("Displaying files");
		char *args1[]={"ls","demo_folder",NULL};
		execvp("ls",args1);
	}
	else 
		wait(NULL);

	check = fork();

	if(!check)
	{
		sleep(4);
		printf("Directory  deleting");
		char* args2[]={"rm","-rf","demo_folder",NULL};
		execvp("rm",args2);
	}
	
return 0;
}
