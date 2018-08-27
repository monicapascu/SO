/*F13. (0.5 puncte) Scrieti un program care numara aparitiile unui caracter
 intr-un fisier dat. Caracterul si specificatorul fisierului sunt dati ca
 argumente in linia de comanda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){

  if(argc != 3){
    
     fprintf(stderr, "Usage: %s <integer> \n", argv[0]);
     return -1;
	
   }

  char car; 
  char str;
  FILE *f;
  f = fopen(argv[2], "r");
  if(!f)
  {
     perror(argv[2]);
     return -1;
  }
  
  car = argv[1][0];
  
  int counter = 0;

  do
  {
     str = (char)fgetc(f);
     if(str == car)
        counter++;
  }while(str != EOF);

  fclose(f);           
  printf("Numarul aparitii al lui %c %d \n", car, counter);

  return 0;
}
