#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

void swap(int *pa, int *pb);
void quick_sort(int sortArray[], int lowIndex, int highIndex);
void print_list(int list[], int size, char const * fmt);

int main(int argc, char *argv[]) {
    int array[ARRAY_SIZE];
    int i;
    
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    print_list(array, ARRAY_SIZE, "排序之前的序列");

    quick_sort(array, 0, ARRAY_SIZE - 1);

    print_list(array, ARRAY_SIZE, "快速排序之后的序列");

    return 0;
}

void swap(int *pa, int *pb) {
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void quick_sort(int sortArray[], int lowIndex, int highIndex) {
    int modIndex;
    int key;
    int i, j;

    if (lowIndex < highIndex) {
        modIndex = (lowIndex + highIndex) / 2;
        swap(&sortArray[lowIndex], &sortArray[modIndex]);

        key = sortArray[lowIndex];

        i = lowIndex + 1;
        j = highIndex;

        while (i <= j) {
            /* looking bigger than key from beginning of list */
            while ((i <= highIndex)
                   && (sortArray[i] <= key))
            {
                i++;
            }

            /* looking smaller than key from end of list */
            while ((j >= lowIndex)
                   && (sortArray[j] > key))
            {
                j--;
            }

            /* swap bigger and smaller value */
            if (i < j) {
                swap(&sortArray[i], &sortArray[j]);
            }
        }

        /* swap key and smaller */
        swap(&sortArray[lowIndex], &sortArray[j]);
        
        quick_sort(sortArray, lowIndex, j - 1);
        quick_sort(sortArray, j + 1, highIndex);
    }
}

void print_list(int list[], int size, char const * fmt) {
    int i;

    printf("%s:\t", fmt);
    
    for (i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
}
