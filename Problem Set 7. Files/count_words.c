#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char to_lowerstring(char c);

int main(int argc, char *argv[]) {

    if (argv[1] == NULL || argc < 2 || argc > 2 ) {
        return 0;
    }

    char tmp;
    int c = 0;
    int final_count = 0;
    char word_to_find[] = {'a','n','a','n','a','s'};

    FILE *fp = fopen(argv[1], "r");
    FILE *temp = fopen("tmp.txt", "w+");

    while (1) {
        tmp = fgetc(fp);
        if (tmp == EOF) {
            break;
        }
        tmp = to_lowerstring(tmp);
        fputc(tmp, temp);
    }
    fclose(fp);
    fclose(temp);

    FILE *fixed = fopen("tmp.txt", "r");
    FILE *fpp = fopen(argv[1], "w+");

    do {
        c = 0;
        tmp = fgetc(fixed);
        if (tmp == 'a') {
            c++;
            for (int i = 1; i < 6; i++) {
                tmp = fgetc(fixed);
                if (tmp == word_to_find[i]) {
                    c++;
                } else {
                    break;
                }
            }
            if (c == 6) {
                final_count++;
            }       
        }
    } while (tmp != EOF);
    fclose(fixed);

    //fprintf(fpp, "%d", final_count);


    if (final_count < 10) {
        fputc (final_count+48, fpp);
    }

    int t = 1;

    for (int i = 10; i < 25; i++) {
        t++;
        if (final_count < 20 && final_count == i) {
            fputc(49, fpp);
            fputc(48+t, fpp);
        }
    }

    fclose(fpp);

    return 0;
}

char to_lowerstring(char c) {
    if (c >= 'A' && c <= 'Z'){
        c += 32;
    }
    return c;
}