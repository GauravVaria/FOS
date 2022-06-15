#include <stdio.h>
#include <stdlib.h>

int main () 
{
   FILE * fp;
fp = fopen ("file.txt", "w+");
fprintf(fp, "We are in 2022");
fclose(fp);
return(0);
}
