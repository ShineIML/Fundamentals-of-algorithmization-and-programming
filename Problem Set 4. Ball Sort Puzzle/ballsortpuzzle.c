/*
    All documentation for tasks and functions is in the document:
    Problem Set 4. Ball Sort Puzzle.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ballsortpuzzle.h"

void generator(const int rows, const int columns, char field[rows][columns]) {

    int first_empty = rand() % columns;
    int second_empty = rand() % columns;

    while (first_empty == second_empty) {
        second_empty = rand() % columns;
    }

    char symb_arr[4] = {'*', '@', '+', '^'};

    int star_c = rows;
    int dog_c = rows;
    int plus_c = rows;
    int arrow_c = rows;

    int r;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j != first_empty && j != second_empty) {
                r = rand() % 4;
                if (r == 0 && star_c != 0) {
                    star_c -= 1;
                    field[i][j] = symb_arr[r];
                } else if (r == 1 && dog_c != 0) {
                    dog_c -= 1;
                    field[i][j] = symb_arr[r];
                } else if (r == 2 && plus_c != 0) {
                    plus_c -= 1;
                    field[i][j] = symb_arr[r];
                } else if (r == 3 && arrow_c != 0) {
                    arrow_c -= 1;
                    field[i][j] = symb_arr[r];
                } else {
                    field[i][j] = ' ';
                    j--;
                }
            } else {
                field[i][j] = ' ';
            }
        }
    }

    return;
}

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y) {

    if (x == y) {
        return;
    }

    char c = ' ';
    int first_column_idx = x - 1;
    int second_column_idx = y - 1;
    int row_idx = rows - 1;
    int tmp = 0;

    for (int j = 0; j < rows; j++) {
        if (field[j][first_column_idx] != ' ') {
            c = field[j][first_column_idx];
            tmp = j;
            break;
        }
    }

    for (int j = row_idx; j >= 0; j--) {
        if ( (field[j][second_column_idx] == ' ') && (j == row_idx) ) {
            field[j][second_column_idx] = c;
            field[tmp][first_column_idx] = ' ';
            break;
        } else if ( (field[j][second_column_idx] == ' ') && (j < row_idx) ) {
            if (field[j+1][second_column_idx] != c) {
                break;
            } else {
                field[j][second_column_idx] = c;
                field[tmp][first_column_idx] = ' ';
                break;
            }
        } else if (j == 0) {
            break;
        }
    }

    return;
}

bool check(const int rows, const int columns, char field[rows][columns]) {

    int counter;
    int full_counter = 0;

    for (int i = 0; i < columns; i++) {
        counter = 0;
        for (int j = 0; j < rows; j++) {
            if (field[j][i] == field[j+1][i]) {
                counter++;
            }
        }
        if(counter == rows - 1) {
            full_counter++;
        }
    }

    if (full_counter == columns) {
        return true;
    }

    return false;
}

void game_field(const int rows, const int columns, char field[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("|%c|", field[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void ball_sort_puzzle() {

    time_t t1;
    srand ( (unsigned) time (&t1) );

    char field[4][6];

    generator(4, 6, field);

    game_field(4, 6, field);

    if (check(4, 6, field) == true) {
        return;
    };

    int from, where;
    do {
        printf("Enter from: ");
        scanf("%d", &from);
        printf("Enter where: ");
        scanf("%d", &where);
        printf("\n");

        down_possible(4, 6, field, from, where);

        game_field(4, 6, field);

    } while(check(4, 6, field) != true);

    return;
}

