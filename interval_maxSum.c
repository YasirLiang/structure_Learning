#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define ARRAY_SIZE 8

int MAX_INT = ((unsigned)(-1)) >> 1;

int inefficientMaxSum(int arrayList[], int size);
int betterMaxSum(int arrayList[], int size);

int main(int argc, char *argv[]) {
    int array[ARRAY_SIZE] = {
        -7, 4, -3, 6, 3, -8, 3, 4
    };

    printf("1\\Max interval Sum = %d\n", inefficientMaxSum(array, ARRAY_SIZE));
    printf("2\\Max interval Sum = %d\n", betterMaxSum(array, ARRAY_SIZE));
    
    return 0;
}

int betterMaxSum(int arrayList[], int size) {
    int sum, maxSum = ~MAX_INT;
    int i, j;

    for (i = 0; i < size; i++) {
        sum = 0;

        for (j = i; j < size; j++) {
            sum += arrayList[j];

            maxSum = MAX(maxSum, sum);
        }
    }

    return maxSum;
}

int inefficientMaxSum(int arrayList[], int size) {
    int sum, maxSum = ~MAX_INT;
    int i, j, k;
    
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            sum = 0;
            for (k = i; k < j; k++) {
                sum += arrayList[k];
            }

           maxSum = MAX(maxSum, sum); 
        }
    }

    return maxSum;
}
