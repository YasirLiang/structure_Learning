#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define SIZE 1000

int main(int argc, char *argv[]) {
    int array[SIZE];
    int n, i, fib;

    array[0] = 3;
    array[1] = 5;
    
    while (scanf("%d", &n)) {
        for (i = 2; i < n; i++) {
            array[i] = array[i - 1] + array[i - 2];
        }

        i = n - 1;
        printf("fib(%d) = %d\n", n, array[i]);
    }
    
    return 0;
}
