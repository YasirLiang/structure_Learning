#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define ARRAY_SIZE 20

#define SWAP(a, b) { \
    t = (a); \
    a = (b); \
    b = (t); \
}

int insertion_sort(int sortList[], int len);
void print_array(int pArray[], int aSzie, char const * info);

int main(int argc, char *argv[]) {
    int i;
    int array[ARRAY_SIZE] = {
        10, 5, 5, 7, 8, 0, 100, 11, 1, 2,
        101, 1001, 4, 6, 89, 50, 9, 12, 56, -1
    };

    print_array(array, ARRAY_SIZE, "Original Array");
    
    insertion_sort(array, ARRAY_SIZE);

    print_array(array, ARRAY_SIZE, "Sorted Array");
    
    return 0;
}

int insertion_sort(int sortList[], int len) {
    int i, j, t;

    for (i = 0; i < len; i++) {
        j = i;

        while ((j > 0)
               && (sortList[j - 1] > sortList[j]))
        {
            SWAP(sortList[j-1], sortList[j])

            j--;
        }
    }
}

void print_array(int pArray[], int aSzie, char const * info) {
    int i;
    
    printf("%s:\t", info);

    for (i = 0; i < aSzie; i++) {
        printf("%d ", pArray[i]);
    }

    printf("\n");
}
