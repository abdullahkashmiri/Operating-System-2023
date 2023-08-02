//21L-7512 Abdullah Dar OS lab 1 BSCS 4g1

#include <stdio.h>

int main(int argc, char *argv[])
{
int sum = 0, i;
for( i=1;i<argc;i++)
{
sum +=atoi(argv[i]);
    }
    float avg = sum / (argc - 1);
printf("Sum of numbers is: %d\n",sum);
printf("Average of numbers is: %lf\n",avg);
return 0;
}
