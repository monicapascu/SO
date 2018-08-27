#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char** argv){

   char* var = (char*)malloc(PATH_MAX);
   if (var == NULL){
     fprintf(stderr, "Failed to allocate memory \n");
     exit(EXIT_FAILURE);
   }
   errno = 0;
   char* cwd = getcwd(NULL,PATH_MAX);
   if (errno) {
       perror(NULL);
       exit(EXIT_FAILURE);
   }
   printf("Valoare returnata de getcwd:%s:\n",cwd);
   printf("PWD=%s\n", getenv("PWD"));
   printf("Valoarea cu care se inlocuieste PWD: ");
   fgets(var,PATH_MAX,stdin);
   errno = 0;
   setenv("PWD",var,1);
   if (errno) {
       perror(NULL);
       exit(EXIT_FAILURE);
   }
   errno = 0;
   char* nwd = getcwd(NULL,PATH_MAX);
   if (errno) {
       perror(NULL);
       exit(EXIT_FAILURE);
   }
   printf("Valoare getcwd dupa modificarea PWD: %s\n", nwd);
   if(strcmp(nwd, cwd) == 0) printf("Valoarea returnata nu se modifica\n");
   else printf("Valoarea returnata se modifica\n");
   free(cwd);
   free(nwd);
   free(var);

  return 0;
}
