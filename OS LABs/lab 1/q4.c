//21L-7512 Abdullah Dar OS lab 1 BSCS 4g1

#include <stdio.h>
#include <stdlib.h>

void removeNonAlphabets(char *inputfilename,char * outputfilename)
{
 FILE *in_file  = fopen(inputfilename, "r");
     FILE *out_file = fopen(outputfilename, "w");
     
  if (in_file == NULL || out_file == NULL)
            {  
              printf("Error! Could not open file fun\n");
              exit(-1);
            }
char ch;
 while ((ch = fgetc(in_file)) != EOF)
 {
if(ch>='0'&&ch<='9')
    fputc(ch, out_file);}

fclose(in_file);
fclose(out_file);

}
int main(int argc,char* argv[])
{

FILE *in_file  = fopen(argv[1], "r");
     FILE *out_file = fopen(argv[2], "w");
     
          if (in_file == NULL || out_file == NULL)
            {  
              printf("Error! Could not open file\n");
              exit(-1);
            }
fclose(in_file);
fclose(out_file);

removeNonAlphabets(argv[1],argv[2]);

printf("\nContents copied to %s", argv[2]);

return 0;
}
