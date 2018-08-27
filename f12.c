/*F12. (1.5 puncte) Scrieti un program care inverseaza ordinea caracterelor
 intr-un fisier al carui specificator este dat ca argument in linia de
 comanda. Nu se vor folosi fisiere auxiliare.
*/

#include <stdio.h>
#include <linux/limits.h>

long count_characters(FILE *f){
    fseek(f, -1, 2);
    long last_pos = ftell(f);
    last_pos++;
    return last_pos;
}

int main(int argc, char * argv[]){

    if(argc != 2){
		fprintf(stderr, "Usage: %s <integer> \n", argv[0]);
		return -1;
	}

    int i=0, cnt;
    char chars[PATH_MAX];
    FILE *fp1;

    if ((fp1 = fopen(argv[1], "r"))) {
        cnt = count_characters(fp1);
        fseek(fp1, -1, 2); // pointer pe ultima pozitie

        int temp_cnt = cnt;
        while (temp_cnt) {
            chars[i++] = fgetc(fp1);
            fseek(fp1, -2, 1); // merg in spate cu un caracter
            temp_cnt--;
        }
    } else {
        return 0;
    }
    fp1 = fopen(argv[1], "w");
    for (int i=0; i<cnt; i++)
        putc(chars[i], fp1);

    fclose(fp1);
    return 0;
}
