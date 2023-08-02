#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/time.h>
#include<string.h>
#include<fcntl.h>

int takeinput(char str[])//Taking input of commands.
{
	printf("\nabdullah@abdullah-virtual-machine:~/Desktop/an2 $ ");
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

int Tokenization(char* args[], int argcount, char str[])// sepearting its arguments
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
		if(i==argcount-1)// last argument
		{
			if(str[j-2] == ' ' && str[j-1] == '&')
			flag = 1;
		}
		j++;
	}
	args[argcount]=NULL;
	if(flag)
		args[argcount-1]=NULL;

	return flag;
}


int main(char argc, char*argv[])
{
	int i,argcount,concurrent = 0;
	char str[100];

	while(takeinput(str))
	{
		argcount = ArgumentsCount(str);
		char* args[argcount+1];
		concurrent = Tokenization(args,argcount,str);
		int id=fork();
		if(id>0)
		{
			if(concurrent == 0)
			{
				printf("Parent Waiting for child \n");
 				wait(NULL);
 				printf("Parent ID : %d\n",getpid());
			}
			else
			{
 				printf("Parent Working Concurrently\n");
 				printf("Parent ID : %d\n",getpid());
			}
		}
		else
		{
///////////////////////////////////////////////////////////////////////////////////////
 //sleep(3);
			//printf("Sleep removed intentionally\n");
			printf("\nChild ID : %ds\n",getpid());
			int i, l = 0, p = 0, j = 0 , k = 0;

		//	printf("ARGUMENTS ARE : ");
		//	for(i = 0; i < argcount ;i++)
		//		 printf(" %s, ", args[i]);

			for(i = 0; i < argcount ; i++)
			{
				 if(strcmp(args[i],">") == 0 || strcmp(args[i],"1>") == 0 || strcmp(args[i],"2>") == 0|| strcmp(args[i],"<") == 0)
 				  	l++;
 				if(strcmp(args[i],"|") == 0)
   					p++;
			}
                       
                 //       printf("\nfile sign 1> OR < is : %d Pipe | is %d\n",l,p);
                     
                //        printf("L+P : %d\n",l+p);
                       
                        if((l+p)==0)
                        {
                   //         	printf("IF EXECUTED\n");
                            	execvp(args[0],args);
                		printf("Command Executed SuccessFully\n");
                		exit(0);
                        }
                        else
                        {
                     //   	printf("ELSE EXECUTED\n");
                       
                        	int arr[l+p+2][2];// +2 for no use
                       
                        	char *str[l+p];
                        	int strsize = l+p+1;
           //             	printf("STR SIZE %d\n",strsize);
                         	j = 0, k = 0;
                        	for(i = 0; i < (l + p); i++)
                        	{
                          		while(strcmp(args[j],"1>") != 0 && strcmp(args[j],">") != 0 && strcmp(args[j],"|") != 0 && strcmp(args[j],"<") != 0 && strcmp(args[j],"2>") != 0  && j < argcount )
                          			j++;
                         
                          		if(strcmp(args[j],"1>") == 0 || strcmp(args[j],">") == 0)
                          			str[i]=">";
               				else if(strcmp(args[j],"|") == 0)
                        			str[i]="|";
                          		else if(strcmp(args[j],"<") == 0)
                         			str[i]="<";
                         		else if(strcmp(args[j],"2>") == 0)
                         			str[i]="2>";
                         
                         //		printf("\nK = %d \n", (j - k));
                          		j++;
                          // Loop between k and j - 2
                    //    printf("K %d\n", k);
                  //     printf("J %d\n", j - 2);
                         
                          		arr[i][0]=k;
                          		arr[i][1]=j-2;
                         
                         
                          		k = j;
                        	}
                       
                        arr[i][0]=arr[i-1][1] + 2;
                        arr[i][1]=argcount - 1;
                       
                        arr[i+1][0] = arr[0][0];
                        arr[i+1][1] = arr[0][1];
                       
       //      printf("Printing : \n");
      //        for(  i=0;i<=l+p;i++)
      //       {
        //          printf("  %d to %d %s",arr[i][0],arr[i][1], str[i]);
        //      }
             
             //----------------------------EXECUTION------------------------------------------
             
              // creating pipes
              int pipes[p][2]; // pipe formed 0 for input, 1 for output
              pid_t frk[p+l+1]; // one more process than pipe used
             
              for(i=0; i<p; i++)
              {
              if(pipe(pipes[i]) < 0)
              	{
              		perror("pipe");
              		printf("Pipe failed %d\n",i+1);
        		exit(EXIT_FAILURE);
        	}
        //	printf("Pipe created %d\n",i+1);
              }
             
             
              	int pno = -1;
                int con = (l + p + 1);
                int comands = (l+p+1);
                int f=-1;
                //-----------------------------------------------------------------------------------------------------------
                //-------------------------------------------  FOR LOOP -----------------------------------------------------
                //-----------------------------------------------------------------------------------------------------------
                for(i = 0; i < con ; i++)
                {
               //     	printf("\n----------Iteration no i : %d pno %d\n",i,pno);
               // 	printf("\nCMD NO 1 ");
                        char *args1[arr[i][1]-arr[i][0] + 2]; // ------------------ cmd 1
                        for(j = 0; j < (arr[i][1]-arr[i][0] + 1); j++)
                        {
                            	args1[j] = args[(arr[i][0] + j)] ;
               //           	printf("%s , ", args1[j]);
                        }
                        args1[j]=NULL;
                        i++;
             //           printf("\n");
             //   	printf("\nCMD NO 2 ");
                        char *args2[arr[i][1]-arr[i][0] + 2]; // -------------------------- cmd 2
                        for(j = 0; j < (arr[i][1]-arr[i][0] + 1); j++)
                        {
                            	args2[j] = args[(arr[i][0] + j)] ;
               //           	printf("%s , ", args2[j]);
                        }
                        args2[j]=NULL;
			//printf("\n");
                       	i--;
                        // i.e  man ls 1> ls.dat
                        if(i < strsize && (strcmp(str[i],">")==0 || strcmp(str[i],"<")==0 || strcmp(str[i],"2>")==0)) // ------------      FILE DESCRIPTORS
                        {
                        	f++;
                        	if(frk[f] = fork()>0)
                        	{
                        		i++;
                        		//wait(NULL);
                        	}
                        	else
                        	{
                         //printf("BEFORE Command Executed SuccessFully if if 2\n");
                     //    	 	printf(" SETTING DUP2  %s\n",str[i]);
                              // Set up output redirection
                        		if(strcmp(str[i],">")==0)
                        		{
                        //			printf("INSIDE > START\n");
                        			int fd_out;
                        			fd_out = open(args2[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
                        			if (fd_out < 0)
                        			{
                            				perror("Error opening output file");
                          				exit(0);
                        			}
                        			
                        			dup2(fd_out, STDOUT_FILENO);
                        			close(fd_out);
                        //			printf("INSIDE > END\n");
                   
                        		}
                        		else if(strcmp(str[i],"2>")==0)
                        		{
printf("KMSKM-------------");
                        			int fd_out;
                        			fd_out = open(args2[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
                        			if (fd_out < 0)
                        			{
                            				perror("Error opening output file");
                          				exit(0);
                        			}
                        			

						dup2(fd_out, STDERR_FILENO);
                        			close(fd_out);
                        		}
                        		else // sort < input.txt
                        		{
                        			int fd_in = open(args2[0], O_RDONLY);
                        			if (fd_in < 0)
                        			{
                        			    perror("Error opening input file");
                        			    exit(0);
                        			}
  						dup2(fd_in, STDIN_FILENO);
  						close(fd_in);
  					}
                        		execvp(args1[0],args1);
             	 			printf("Command Executed SuccessFully else else 1  2\n");
              			}
                        }  
                       // ---------------------------------        
                         // sort ls.dat | tee fifo1 | wc -l
                        else if(i < (strsize - 1) && (strcmp(str[i],"|") == 0 ) )// pipe
                        {
                        	pno++;
                        //	printf("\n1 PNO : %d ",pno);
                        // dup2(old,new)
			//	printf("\nMAIN/ PARENT Pipe start pno %d\n",pno);
				f++;
					
			//	if((frk[f] = fork())==0) // child process pid1 = fork()
				if(frk[f] = fork() > 0)// parent
				{
				
				}
				else
				{
				//	printf("CHILD PNO : %d & iteration here  %d\n",pno,i);
					if(pno == 0)
					{
				//		printf("CHILD Pipe NO start in if : %d if \n",pno);
						close(pipes[pno][0]);
						dup2(pipes[pno][1], STDOUT_FILENO); // simply put pipe on output
						close(pipes[pno][1]);
//dup2(STDOUT_FILENO,pipes[pno][1]);
					}
					else
					{
				//		printf("CHILD PNO : %d else \n",pno);
					
						close(pipes[pno - 1][1]);
						dup2(pipes[pno - 1][0], STDIN_FILENO); // simply put pipe input form last pipe
						close(pipes[pno -1][0]);
						
						close(pipes[pno][0]);
						dup2(pipes[pno][1], STDOUT_FILENO); // simply put pipe on output
						close(pipes[pno][1]);
						
						
					}

//------------------------------------
					execvp(args1[0],args1);
					exit(0);
        			}
       
			//	printf("\nMAIN / PARENT Pipe end pno %d \n",pno);
			}  
			
			
			// sort ls.dat | tee fifo1 | wc -l
		else if(i > 0 && strcmp(str[i-1],"|") == 0 )
		{
			pno++;
		//	printf("\n//----//----//----//2 PNO : %d ",pno);
			f++;
		//	printf("F %d\n",f);
			if(frk[f] = fork() > 0)// parent
			{
			//printf("---------------------- ----------------- FORK FORK FORK ARGS1 ELSE LAST PARENT WAIT -----------------  -------------------- \n");
			//	wait(NULL);
			}
			else // child
			{
			//	printf("---------------------- ----------------- ARGS1 ELSE LAST PARENT WAIT -----------------  -------------------- \n");
				int a = 0;
			//	while(args1[a]!=NULL)
			//	{
			//		printf("ARGS1[%d] %s,",a,args1[a]);
			//		a++;
			//	}
				
				printf("\n");
			//	printf("CHILD ELSE IF BEFORE ARGS1 working FOR PIPES pno %d \n",pno);
				
				close(pipes[pno - 1][1]);
				dup2(pipes[pno - 1][0], STDIN_FILENO); // simply put pipe input
				close(pipes[pno - 1][0]);

			//	printf("CHILD ELSE IF AFTER ARGS1 working FOR PIPES pno %d \n",pno);

			//	printf("EXECVP \n");
				execvp(args1[0],args1);
				
				exit(0);
			}
		}
                   
      		}
  	
  	//	printf("---------------------L+P+1 %d  F %d commands %d\n",l+p+1,f,comands);
  		
  		
  		// Wait for all child processes to terminaaate
    		for (i = 0; i <=f  ; i++) 
    		{
        		if (waitpid(frk[i], NULL, 0) == -1) 
        		{
            			perror("waitpid");
            			exit(1);
        		}
    		}
    	}
	printf("Command Executed SuccessFully END--\n");
                        }
    ///////////////////////////////////////////////////////////////////////////////////////
}


printf("Program terminated SuccessFully TERMINATE\n");
return 0;
}

//---- abdullah dar l217512 os an 2 q1s
//END