#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main() {

    int n, rows, cols;
    scanf("%d %d %d", &n, &rows, &cols);
    int q = n;

    int array[rows-1][cols+1];

    for (int i = 0; i < rows-1; i++) {
        for (int j = 0; j < cols+1; j++) {
            array[i][j] = pow(n, j);
        }
        n++;
    }

    int c = 0;
    for(int x = 0; x < rows-1; x++) {
        printf("%d: ", q+c);
        for(int y = 0; y < cols+1; y++) {
            printf("%d ", array[x][y]);
        }
        c++;
        printf("\n");
    }

    return 0;
}

    return 0;
}