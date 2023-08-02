#include"l217512_header.h"

void vowfreq(char *str)
{
int i,count=0;
for(i=0;str[i]!='\0';i++)
{
if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
count++;
}
return count;
}

void constfreq(char*str){
int i,count=0;
for(i=0;str[i]!='\0';i++)
{
if(str[i]!='a'||str[i]!='e'||str[i]!='i'||str[i]!='o'||str[i]!='u')
count++;
}
return count;
}

void reverse(char*str)
{

int len = strlen(str);

char str2[len];

for(int i=0;i<len ; i++)
str2[len-1-i]=str[i];

return str2;

}
int main(int argc, char*argv[])
{
char  *str;

int fd = open ("fifopipe2",O_RDWR);
int size = read(fd,str,200);
printf(" freq str %s,  PID : %d  \n",str,getpid());

int id=fork();
if(id>0)
wait(NULL);
else if(id==0)
{
int vow = vowfreq(str);
int con = constfreq(str);
char * rev = reverse(str);

printf("%d",vow);

printf("%d",con);

printf("%s",rev);
}


return 0;
}
