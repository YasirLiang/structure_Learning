#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define ARRAY_SIZE (101)

int maxSum[ARRAY_SIZE][ARRAY_SIZE];

int recursive_calSum(int array[][ARRAY_SIZE], int raw, int column, int size);

int main(int argc, char *argv[]) {
    int array[ARRAY_SIZE][ARRAY_SIZE];
    int i, j;
    int size, *pMaxSum;

    scanf("%d", &size);
    
    for (i = 1; i <= size; i++) {
        for (j = 1; j <= i; j++) {
            array[i][j] = rand() % 100;
            maxSum[i][j] = -1;
        }
    }

    printf("Recursive Cal: Max cal Sum = %d\n", recursive_calSum(array, 1, 1, size));

    pMaxSum = array[size];

    for (i = size - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            pMaxSum[j] = MAX(pMaxSum[j], pMaxSum[j + 1]) + array[i][j];
        }
    }
    
    printf("Dynamic Cal: Max cal Sum = %d\n", pMaxSum[1]);
    
    return 0;
}

int recursive_calSum(int array[][ARRAY_SIZE], int raw, int column, int size) {
    if (maxSum[raw][column] != -1) {
        return maxSum[raw][column];
    }

    if (raw == size) {
        maxSum[raw][column] = array[raw][column];
    }
    else {
        int x = recursive_calSum(array, raw + 1, column, size);
        int y = recursive_calSum(array, raw + 1, column + 1, size);
        
        maxSum[raw][column] = MAX(x, y) + array[raw][column];
    }
    
    return maxSum[raw][column];
}

