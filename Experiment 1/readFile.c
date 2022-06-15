#include <stdio.h>
#include <stdlib.h>

int main () {
FILE *fp;
int c;

fp = fopen("file.txt","r");
while(1) {
      c = fgetc(fp);
      if(feof(fp) ) { // End of file
            break ;
      }
      printf("%c", c);
   }
fclose(fp);
return(0);
}
