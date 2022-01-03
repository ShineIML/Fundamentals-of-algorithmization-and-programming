/*
    All documentation for tasks and functions is in the document:
    Problem Set 3. Hangman.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if (fp == NULL) {
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if (result != EOF)
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]) {
    //variable counter to check if guessed word is equal to secret word
    int counter = 0;

    //loop that check equal letters in two arrays, if equal = 5 && seclen = 5 => return 1; else => return 0;
    for (int i = 0; i < strlen(letters_guessed); i++) {
        for (int j = 0; j < strlen(secret); j++) {
            if (letters_guessed[i] == secret[j]) {
                counter++;
            }
        }
    }
    
    return (counter == strlen(secret)) ? 1 : 0;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]) {
	char filler = '_';

    //Filling the result array with the symbol '_' depending on the length of the secret word
	for (int i = 0; i < strlen(secret); i++) {
		guessed_word[i] = filler;
	}

    //We check whether our word matches the secret one and fill in the array with the letters that were guessed
	for (int i = 0; i < strlen(letters_guessed); i++) {
		for (int j = 0; j < strlen(secret); j++) {
			if (letters_guessed[i] == secret[j]) {
				guessed_word[j] = letters_guessed[i];
			}
		}
	}
	guessed_word[strlen(secret)] = '\0';
}

void get_available_letters(const char letters_guessed[], char available_letters[]) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int cur_output_idx = 0;
    
    for (int i = 0; i < strlen(alphabet); i++) {
        int is_letter_found = 0;
        for (int j = 0; j < strlen(letters_guessed); j++) {
            if (alphabet[i] == letters_guessed[j]) {
                is_letter_found = 1;
                break;
            }
        }                                         
        if (!is_letter_found) {
            available_letters[cur_output_idx] = alphabet[i];
            cur_output_idx++;
        }
    }
    available_letters[cur_output_idx] = '\0';
}