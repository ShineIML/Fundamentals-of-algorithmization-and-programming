#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int max_2d(const int size, int array[][size]);
int vowels_count_2d(const int rows, const int cols, char string[][cols]);
int is_in_array_2d(const int num, const int size, int array[][size]);
int largest_line(const int size, int array[][size]);
void swap_case_2d(const int rows, const int cols, char string[][cols]);
int largest_col(const int size, int array[][size]);
int count_zeroes_2d(const int size, int array[][size]);
void swap_sign_2d(const int size, int array[][size]);


int main(void) {

	int array[2][2] = { {-1,1}, {0, -3} };
/*	printf("%d\n", max_2d(2,array));

	char strings[3][50] = {"hello WORLD!", "aHOJ", "Ahoj"};
	printf("%d\n", vowels_count_2d(3, 50, strings));

	int array1[2][2] = { {1,0}, {0, -3} };
	printf("%d %d\n", is_in_array_2d(2, 2, array1), is_in_array_2d(-3, 2, array1));

	printf("%d\n", largest_line(2, array));

	char string2[2][50] = {"hello","aHOJ"};

	swap_case_2d(2, 50, string2);

	for(int i = 0; i < 2; i++) {
		printf("%s\n", string2[i]);
	}
*/

	swap_sign_2d(2, array);
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
        	printf("%d ", array[i][j]);
		}
    }
	printf("\n");

//	printf("%d\n", count_zeroes_2d(2, array));

	return 0;
}

int max_2d(const int size, int array[][size]) {

	int max = array[0][0];

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if (max < array[i][j]) {
				max = array[i][j]; 
			}
		}
	}

	return max;

}

int min_2d(const int size, int array[][size]) {

    int min = array[0][0];

     for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
           if (min > array[i][j]) {
               min = array[i][j];
           }
       }
   }
    return min;
}



int vowels_count_2d(const int rows, const int cols, char string[][cols]) {

//	char arr[12] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

	int c = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; string[i][j] != '\0'; j++) {
			if(string[i][j] == 'A' || string[i][j] == 'E' || string[i][j] == 'I' || string[i][j] == 'O' ||
			   string[i][j] == 'U' || string[i][j] == 'a' || string[i][j] == 'e' || string[i][j] == 'i' ||
			   string[i][j] == 'o' || string[i][j] == 'u') {
				c++;
			}
		}
	}

	return c;
}

int is_in_array_2d(const int num, const int size, int array[][size]) {

	if(array == NULL) {
		return -1;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < size; j++) {
			if(array[i][j] == num) {
				return 1;
			}
		}
	}

	return 0;
}

int largest_line(const int size, int array[][size]) {

    if(array == NULL) {
        return -1;
    }

    int greater = 0;
    int tmp;
    int line = 0;

    for(int i = 0; i < 1; i++) {
        for(int j = 0; j < size; j++) {
            greater += array[i][j];
        }
    }
    printf("%d\n", greater);

    for(int i = 1; i < size; i++) {
        tmp = 0;
        for(int j = 0; j < size; j++) {
            tmp += array[i][j];
        }
        printf("%d, %d\n", greater, tmp);
        if(greater > tmp) {
            continue;
        } else {
            greater = tmp;
            line++;
        }
    }
	
	return line;
}

void swap_case_2d(const int rows, const int cols, char string[][cols]) {
/*
	if(string == NULL) {
		return;
	}
*/
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(string[i][j] > 64 && string[i][j] < 91) {
				string[i][j] += 32;
			} else if(string[i][j] > 96 && string[i][j] < 123) {
				string[i][j] -= 32;
			}
		}
	}
}


int largest_col(const int size, int array[][size]) {

	if(array == NULL) {
        return -1;
    }

    int first = 0;
    int second = 0;
	int tmp = size;
	int res = 0;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 2; j++) {
			if(tmp != 0) {
            	if(i = 0) {
					first += array[j][i];
				} else if(i = 1) {
					second += array[j][i];
				}
				tmp--;
			}
			if(first > second) {
				res = 0;
			} else {
				res = 1;
			}
        }
    }
	return res;
}

int count_zeroes_2d(const int size, int array[][size]) {

	if(array == NULL) {
        return -1;
    }

	int counter = 0;

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < size; j++) {
			if(array[i][j] == 0) {
				counter++;
			}
		}
	}

	return counter;

}

void swap_sign_2d(const int size, int array[][size]) {

	if(array == NULL) {
		return;
	}

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < size; j++) {
			array[i][j] *= -1;
		}
	}
}
