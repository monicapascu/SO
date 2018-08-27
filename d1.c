/*D1. (4 puncte) Program care primeste ca argument in linia de comanda un
 director si afisaza arborescenta de directoare si fisiere cu originea
 in el (similar comenzii tree /f din DOS). */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

void indent_level (int isize) {
    putchar('\n');
    while (isize) {
        printf("|   ");
        isize--;
    }
}

char* g_rdirname = NULL;

int paint_tree (char* dirname) {
    static int ilevel = -1;

    errno = 0;
    DIR* dir = opendir(dirname);
    if (errno) {
        printf(" %s", strerror(errno));
        return -1;
    }

    ilevel++;

    chdir(dirname);
    printf("%s", getcwd(NULL, 0));

    struct dirent* ent;
    while ((ent = readdir(dir)) != NULL) {
        char* ename = ent->d_name;
        if (strcmp(ename, "..") != 0 && strcmp(ename, ".") != 0) {
            indent_level(ilevel);

            printf("|-- %s", ename);
            if (ent->d_type == DT_DIR) {
                paint_tree(ent->d_name);
            }
        }
    }

    chdir("..");
    ilevel--;
    closedir(dir);
    return 0;
}

int main (int nargs, char* vargs[]) {
  if (nargs != 2) {
      fprintf(stderr, "Usage: %s <directory>\n", vargs[0]);
      return -1;
  }

  g_rdirname = vargs[1];
  errno = 0;
  DIR* dir = opendir(g_rdirname);
  if (errno) {
      perror(g_rdirname);
      return -1;
  }

  closedir(dir);

  paint_tree(g_rdirname);
  putchar('\n');

   return 0;
}
