/*
    All documentation for tasks and functions is in the document:
    Problem Set 2. Numbers, Arrays.pdf
*/

#include <stdio.h>
#include <math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int collatz(const int number);
int opposite_number(const int n, const int number);
void counter(const int input_array[], const int array_size, int result_array[2]);
unsigned long sum_squared(const int line);
int array_min(const int input_array[], const int array_size);
int array_max(const int input_array[], const int array_size);
unsigned long special_counter(const int input_array[], const int array_size);
int special_numbers(const int input[], const int array_size, int result[]);

int main() {
    //Task_1
    printf("%.4f\n",lift_a_car(2,80,1400));

    //Task_2
    printf("%.4f\n",unit_price(4.79,16,150)); 
    
    //Task_3
    printf("%d\n", collatz(20));
    
    //Task_4
    printf("%d\n",opposite_number(10,2));
    
    //Task_5
    int input_array1[] = {1,2,3,4,5};
    int result_array[2];
    counter(input_array1, 5, result_array);
    printf("%d %d\n", result_array[0], result_array[1]);
    
    //Task_6
    printf("%lu\n", sum_squared(4));
    
    //Task_7
    int input_array2[]={1,2,3,4,5};
    printf("%d\n",array_min(input_array2,5));
    printf("%d\n",array_max(input_array2,5));
    
    //Task_8
    int input_array3[]={11,12,13,14,15};
    printf("%lu\n",special_counter(input_array3,5));
    
    //Task_9
    int input[] = {16,17,4,3,5,2};
    int result[6];
    int count = special_numbers(input, 6, result);
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");


    return 0;
}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight) {      
    float x, rounded_x;
    float p = 2.0;

    x = stick_length * human_weight / (human_weight + car_weight);
    rounded_x = round(x * pow(10, p)) / pow(10, p);

    return rounded_x;
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count) {
    float roll, x, rounded_x;
    float p = 2.0;

    roll = pack_price / rolls_count;
    x = (roll/pieces_count) * 100;
    rounded_x = round(x * pow(10,p)) / pow(10,p);

    return rounded_x;
}

int collatz(const int number) {
    int num = number;
    int amount = 1;
    int count = 1;

    while (num > count) {
        amount++;
        if (num % 2 == 0) {
            num /= 2;
        }
        else if (num % 2 == 1) {
            num = 3 * num + 1;
        }
    }

    return amount;
}

int opposite_number(const int n, const int number) {    
    int r;

    r = number - n / 2;
    if (r < 0) {
        r += n;
    }

    return r;
}

void counter(const int input_array[], const int array_size, int result_array[2]) {
    int i, first,second;
    first = 0;
    second = 0;

    for (i = 0; i < array_size; i++) {
        if (i % 2 == 0 || i == 0) {
            first += input_array[i];
        }
        else if (i % 2 == 1 || i == 1) {
            second += input_array[i];
        }
    }
    result_array[0] = first;
    result_array[1] = second;
}


unsigned long sum_squared(const int line) {
    long long int n = line;
    long long int k = 0;
    long long int sum = 1;
    long long int sqr = 0;
    unsigned long prev_elem = 1;

    for (k = 1; k <= n; k++) {
        unsigned long triangle_cell = prev_elem * (n + 1 - k) / k; 
        sqr = triangle_cell * triangle_cell;
        sum +=  sqr;
        prev_elem = triangle_cell;
    }

    return sum;
}

int array_min(const int input_array[], const int array_size) {
    int i,min;
    min = input_array[0];

    for (i = 1; i < array_size; i++) {
        if (input_array[i] < min) {
            min = input_array[i];
        }
    }

    return min;
}

int array_max(const int input_array[], const int array_size) {
    int i,max;
    max = input_array[0];

    for (i = 1; i < array_size; i++) {
        if (input_array[i] > max) {
            max = input_array[i];
        }
    }

    return max;
}

unsigned long special_counter(const int input_array[], const int array_size) {
    int i, first,second,result;
    int result_array[2];
    first = 0;
    second = 0;

    for (i = 0; i < array_size; i++) {
        if (i % 2 == 0 || i == 0) {
            first += input_array[i];
        }
        else if (i % 2 == 1 || i == 1) {
            second += input_array[i] * input_array[i];
        }
    }
    result_array[0] = first;
    result_array[1] = second;
    result = result_array[0] + result_array[1];

    return result;
}


int special_numbers(const int input[], const int array_size, int result[]) {
    int counter = 0;     
    int dig;

    for (int i = 0; i < array_size; i++) {
        dig = 0;
        for (int j = i + 1; j < array_size; j++) { 
            dig += input[j];
        }
        if (dig < input[i]) {
            result[counter] = input[i];
            counter++;
        }                                                             
    }

    return counter;
}
