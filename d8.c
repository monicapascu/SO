/* D8. (2 puncte) Program care tipareste pe stderr toate mesajele de eroare ce
se pot obtine cu functia "perror", precedata de valoarea corespunzatoarea varabilei
"errno". Cu ajutorul lui sa se obtina un fisier cu aceste mesaje.
*/

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc!=1) {
        fprintf(stderr, "Usage: %s <integer> \n",argv[0]);
        return -1;
    }

    freopen("errors.txt", "w", stdout);
    for (int i=0; i<sys_nerr; i++) {
        errno = i;
        printf("%d: %s\n", errno, strerror(errno));
        fprintf(stderr, "%d: %s\n", errno, strerror(errno));
    }
    return 0;
}
