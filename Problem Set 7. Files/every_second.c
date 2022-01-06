#include <stdio.h>

int main(int argc, char *argv[]) {
    
    char words_inside[10000];
    char character_in_file;
    for ( int i = 0; i<10000; i++ ) {
        words_inside[i] = '\0';
    }

    if ( argc < 3 || argc > 3 ) {
        printf("Error. Wrong number of command line arguments!");
        return 0;
    }

    if ( argv[1] == NULL ) {
        printf("Nothing to open.");
        return 0;
    }

    FILE*input = fopen(argv[1], "r");
    FILE*output = fopen(argv[2], "w");
    
    // Loop for make START in file

    int p = 0;
    while (p !=1 && character_in_file != EOF ) {
        if (character_in_file == 'S') {
            character_in_file = fgetc(input);
            if (character_in_file == 'T') {
                character_in_file = fgetc(input);
                if (character_in_file == 'A') {
                    character_in_file = fgetc(input);
                    if (character_in_file == 'R') {
                        character_in_file = fgetc(input);
                        if (character_in_file == 'T') {
                            p=1;
                        }
                    }
                }
            }
        }
        character_in_file = fgetc(input);
        if (character_in_file == ' ') {
            character_in_file = fgetc(input);
        }
    }
    p=0;
    while (p!=1 && character_in_file != EOF) {

        //If STOP word appears == exit.

        if (character_in_file == 'S') {
            character_in_file = fgetc(input);
            if (character_in_file == 'T') {
                character_in_file = fgetc(input);
                if (character_in_file == 'O') {
                    character_in_file = fgetc(input);
                    if (character_in_file == 'P') {
                        p=1;
                    }
                }
            }
        }
        character_in_file = fgetc(input);

        //Put all words in file(and STOP) to temporary array.

        for (int i = 0; character_in_file != EOF; i++) {
            character_in_file = fgetc(input);
            words_inside[i] = character_in_file;
        }
    
        //Delete STOP from temporary array.

        for (int i = 0; words_inside[i] != EOF; i++) {
            if (words_inside[i] == 'S' && words_inside[i+1] == 'T' && words_inside[i+2] == 'O' && words_inside[i+3] == 'P') {
                if (i != 0) {
                    words_inside[i-1] = '\0';
                }
            }
        }

        //Write all words from temporary array w/o START and STOP
    
        int a = 0;
        int p = 0;
        while (words_inside[a] != '\0') {
            for (int i=0; i<2; i++) {
                if (words_inside[a] != '\0') {
                    if (p != 0 && i % 2 != 0) {
                        fputc(' ', output);
                    }
                }
                while (words_inside[a] != ' ' && words_inside[a] != '\0') {
                    if (i % 2 != 0) {
                        fputc(words_inside[a], output);
                    }
                    a++;
                }
                if (words_inside[a] != '\0') {
                    a++;
                }
            }
            p++;
        }
    }
    
    fclose(input);
    fclose(output);

    return 0;
}
