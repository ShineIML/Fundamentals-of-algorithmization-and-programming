#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int is_white(const char c);
void change_whites(char string[]);
int guess_eval(const int guess, const int my_number);
int binary_num(const int num);
int div_by_3(const int num);
int same_case(const char a, const char b);

int leap_year(const int year);
int count_positives(const int size, const int array[]);
int count_whites(const char string[]);
int direction_correction(const int degree);
int all_positives(const int size, const int array[]);
int last_positive(const int size, const int array[]);
void swap_sign(const int size, int array[]);
int find_first_A(const char string[]);
void string_to_upper(char string[]);


int main() {
/*
	printf("%d %d\n", is_white('#'), is_white(' '));

	char str[] = "Hello world!";
	change_whites(str);
	printf("%s\n", str);

	printf("%d %d %d\n", guess_eval(34, 22), guess_eval(22, 34), guess_eval(34, 34));

	printf("%d %d %d\n\n", binary_num(-1001), binary_num(3), binary_num(1));
*/
	printf("%d %d %d\n", leap_year(4000), leap_year(3000), leap_year(3004));
/*
	int array1[] = {1,2,0,3,-4,0};
	const int array2[] = {1,2,6,3,4,7};
	const int array3[] = {-1,-2,0,-3,0,-2};
	printf("%d %d %d\n", count_positives(6, array1), count_positives(6, array2), count_positives(6, array3));

	const char string[] = "Hello, how are you?";
	printf("%d\n\n", count_whites(string));
*/
//	printf("%d %d %d\n\n", direction_correction(1080), direction_correction(540), direction_correction(180));
/*
	printf("%d %d %d\n\n", all_positives(6, array1), all_positives(6, array2), all_positives(6, array3));

	printf("%d %d %d\n\n", last_positive(6, array1), last_positive(6, array2), last_positive(6, array3));

	swap_sign(6, array1);
	for(int i = 0; i < 6; i++) {
		printf("%d ", array1[i]);
	}
	printf("\n\n");

	printf("%d %d %d\n\n", div_by_3(-3), div_by_3(6), div_by_3(8));

	printf("%d %d %d\n\n", same_case('a', 'f'), same_case('L', 'g'), same_case('#', 'P'));
*/
/*
	printf("%d \n", find_first_A("Tomorrow afternoon"));

	char str[] = "ToMoRrow afternoo#";
	string_to_upper(str);

	printf("%s \n", str);
*/
	return 0;
}

int is_white(const char c) {

	if(c == ' ' || c == '\t' || c == '\n') {
		return 1;
	} else {
		return 0;
	}
}

void change_whites(char string[]) {

	for(int i = 0; i < strlen(string); i++) {
		if(string[i] == ' ' || string[i] == '\n') {
			string[i] = '.';
		}
	}

}

int guess_eval(const int guess, const int my_number) {

	if(guess == my_number) {
		return 1;
	} else if(my_number > guess) {
		return 2;
	} else {
		return 0;
	}

}

int binary_num(const int num) {

	int min = -1000;
	int max = 1000;

	if(num < min || num > max) {
		return -1;
	} else if(num == 0 || num == 1) {
		return 1;
	} else {
		return 0;
	}

}

int div_by_3(const int num) {
	int tmp = num;

	if(tmp % 3 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int same_case(const char a, const char b) {

	if(a > 64 && a < 91) {
		if(b > 64 && b < 91) {
			return 1;
		} else if(b > 96 && b < 123) {
			return 0;
		} else {
			return -1;
		}
	} else if(a > 96 && a < 123) {
		if(b > 96 && b < 123) {
			return 1;
		} else if(b > 64 && a < 91) {
			return 0;
		} else {
			return -1;
		}
	}

	return -1;
}

int leap_year(const int year) {

	if(year > 4443) {
		return -1;
	}

	int r = year;

	if( ( (r%4 == 0) && (r%100 !=0) ) || (r%400 == 0)) {
		return 1;
	}

	return 0;
/*
	if((p % 400 == 0) && (p % 4 == 0) && (p % 100 == 0)) {
		p = 1;
	} else if((p % 400 == 0) && (p % 4 == 0) && (p % 100 != 0)) {
		p = 1;
	} else if((p % 400 == 0) && (p % 4 != 0) && (p % 100 == 0)) {
		p = 1;
	} else if((p % 400 == 0) && (p % 4 != 0) && (p % 100 != 0)) {
		p = 1;
	} else if((p % 400 != 0) && (p % 4 == 0) && (p % 100 != 0)) {
		p = 1;
	} else {
		p = 0;
	}
	return p;
*/
}


int count_positives(const int size, const int array[]) {

	int counter = 0;

	for(int i = 0; i < size; i++) {
		if(array[i] > 0) {
			counter++;
		}
	}

	return counter;
}

int count_whites(const char string[]) {

	int counter = 0;

	for(int i = 0; i < strlen(string); i++) {
		if(string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
			counter++;
		}
	}

	return counter;
}


int direction_correction(const int degree) {

	if(degree < 0) {
		return -1;
	}

	return degree % 360;

/*
	int arr[4] = {0, 90, 180, 270};

	if(degree == arr[0] || degree == arr[1] || degree == arr[2] || degree == arr[3]) {
		return degree;
	}

	if(degree < 0) {
		return -1;
	}

	if(degree == 360) {
		return arr[0];
	} else if(degree == 450) {
		return arr[1];
	} else if(degree == 540) {
		return arr[2];
	} else if(degree == 630) {
		return arr[3];
	} else if(degree == 720) {
		return arr[0];
	} else if(degree == 810) {
		return arr[1];
	} else if(degree == 900) {
		return arr[2];
	} else if(degree == 990) {
		return arr[3];
	} else if(degree == 1080) {
		return arr[0];
	}
*/
}

int all_positives(const int size, const int array[]) {

	if(array == NULL || size == 0) {
		return -1;
	}

	int counter = 0;

	for(int i = 0; i < size; i++) {
		if(array[i] > 0) {
			counter++;
		}
	}

	if(counter == size) {
		return 1;
	} else {
		return 0;
	}
}

int last_positive(const int size, const int array[]) {

	if(array == NULL || size == 0) {
		return -1;
	}

	int last = -1;

	for(int i = 0; i < size; i++) {
		if(array[i] > 0) {
			last = array[i];
		}
	}

	return last;
}

void swap_sign(const int size, int array[]) {

	for(int i = 0; i < size; i++) {
		array[i] *= -1;
	}
}

int find_first_A(const char string[]) {

	if(string == NULL) {
		return -1;
	}

	for(int i; i < strlen(string); i++) {
		if(string[i] == 'A' || string[i] == 'a') {
			return i;
		}
	}

	return -1;
}

void string_to_upper(char string[]) {

	for(int i = 0; i < strlen(string); i++) {
		if(string[i] > 96 && string[i] < 123) {
			string[i] -= 32;
		}
	}

}

int is_prime(int num) {

	bool flag = false;

	for(int i = 2; i <= num / 2; i++) {
		if(num % i == 0) {
			flag = true;
			break;
		}
	}

	if(flag == false) {
		return 1;
	} else {
		return 0;
	}
}
