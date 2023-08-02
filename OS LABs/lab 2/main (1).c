#include"header.h"


int main(int argc,char *argv[])
{
int array[argc-3];
int i;
for( i=0;i< (argc-3);i++)
{
array[i]=atoi(argv[i+1]);
}

print(array,argc-3);
sort(array,atoi(argv[argc-2]),argc-3);
print(array,argc-3);
findHighest(array,atoi(argv[argc-1]),argc-3);
return 0;
}

