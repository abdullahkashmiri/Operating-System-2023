#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char*argv[])
{
int fd = mkfifo("fifopipe2",0777);

return 0;
}
