
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main (int argc , char* argv[]) {
    if (argc!=2) {
        fprintf(stderr, "Usage: %s <integer> \n",argv[0]);
        exit(EXIT_FAILURE);
    }

    char* nr = argv[1];
    int length = strlen(nr);

    char* end;
    errno = 0;
    long int n = strtol(nr,&end,10);
    if(errno){
      perror(NULL);
      exit(EXIT_FAILURE);
    }

    if(*end ! = '\0'){
      fprintf(stderr, " %s not a number\n", argv[1]);
      fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    if(length == 0){
      fprintf(stderr, "Sir vid\n");
      exit(EXIT_FAILURE);
    }

    if (n<2){
        fprintf(stderr, "Number must be higher than 1 \n");
        exit(EXIT_FAILURE);
    }

    int p, d = 2;
    fprintf(stdout, "%ld = ", n);
    while(n>1){
          p=0;
          while(n%d==0){
                p=p+1;
                n=n/d;
          }
          if(p == 1) fprintf(stdout, "%d", d);
            else
            if(p) fprintf(stdout,"%d^%d", d, p);
          d=d+1;

          if(n>1 && p)
            putc('*',stdout);
    }

      putc('\n', stdout);

    return 0;

  }
