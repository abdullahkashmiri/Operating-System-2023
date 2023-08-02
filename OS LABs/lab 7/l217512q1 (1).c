// 21l7512 abdullah dar os lab 7 q1
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
char buffer[100];
printf("input file : %s\n",argv[1]);
printf("output file : %s\n",argv[2]);

int infile_desc = open(argv[1], O_RDONLY);
int outfile_desc = open(argv[2], O_WRONLY);

if(outfile_desc < 0 || infile_desc < 0)
{
printf("Error Opening File\n");
}


dup2(infile_desc,0);
dup2(outfile_desc,1);

read(0, buffer, 100);
printf("%s", buffer);

close(infile_desc);
close(outfile_desc);

return 0;
}
