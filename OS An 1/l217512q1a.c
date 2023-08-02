//Abdullah Dar 21L-7512 OS AN 1 Q1 A

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/time.h>

int takeinput(char str[])//Taking input of commands
{
printf("\nabdullah@abdullah-VirtualBox:-/Desktop/OS AN 1$ ");
fgets(str,100,stdin);
printf("Command is : %s",str);
if(str[0]=='e'&&str[1]=='x'&&str[2]=='i'&&str[3]=='t')
return 0;
else
return 1;
}

int ArgumentsCount(char str[])// counting its arguments
{
	int might = 0,count =0,i=0;
	if(str[0]!='\0' && str [0] !=' ')
	count++;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		might = 1;
		else if( might && (str[i] != ' ' && str[i]!= '\0'))
		{
			might = 0;
			count += 1;
		}
	}
	printf("Arguments : %d\n",count);
	return count;
}

void Tokenization(char* args[], int argcount, char str[])// sepearting its arguments
{
int flag = 0;
int j=0,k=0,i=0;
for(i=0;i<argcount;i++)
{
	char*arg = malloc(20*sizeof(char));
	k=0;
	while(str[j]!= ' '&& str[j+1]!='\0')
	{
		arg[k]=str[j];
		k++;
		j++;
	}
	arg[k]='\0';
	args[i]=arg;
	j++;
}
args[argcount]=NULL;	
}


int main(char argc, char*argv[])
{
	int i,argcount;
	char str[100];
	
	while(takeinput(str))
	{
		argcount = ArgumentsCount(str);
		char* args[argcount+1];
		Tokenization(args,argcount,str);
		int id=fork();
		if(id>0)
		{
			wait(NULL);
			printf("Parent ID : %d\n",getpid());
		}
		else
		{
			printf("Child ID : %d\n Working of Command : %s\n ",getpid(),args[0]);
			execvp(args[0],args);
			printf("Command Executed SuccessFully\n");
			exit(0);
		}
	}
	printf("Program terminated SuccessFully\n");
	return 0;
}
//END









