#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hangman.h"
#include <time.h>

int main() {

    char secret_word[20];
    get_word(secret_word);

    printf("%d\n", is_word_guessed("secret", "aeiou"));

    printf("%d\n", is_word_guessed("hello", "aeihoul"));

    char result[30];
    get_guessed_word("container", "arpstxgoieyu", result);
    for(int i = 0; i < strlen(result); i++) {
        printf("%c" , result[i]);
    }
    printf("\n");

    get_available_letters("arpstxgoieyu", result);
    for(int i = 0; i < strlen(result); i++) {
        printf("%c" , result[i]);
    }
    printf("\n");

    return 0;
}