#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define SIZE 10

void bubble_sort( int a[], int size );
void show_array( int size, int a[] );

int main( int argc, char *argv[] )
{
	int array[SIZE] = { 0, 99, 55, 66, 12, 6, 45, 20, 65,10 };
	int i = 0;

#if 0
	for( i = 0; i < SIZE; i++ )
	{
		array[i] = rand();
	}
#endif

	printf( "Array Before Sort:\t" );
	show_array( SIZE, array );

	bubble_sort( array, SIZE );

	printf( "Array Sorted:\t" );
	show_array( SIZE, array );

	return 0;
}

void bubble_sort( int a[], int size )
{
	int i = 0, j = 0;
	int flag = 1;
	int temp;

	for( i = 0; i < size - 1 ; i++ )
	{
		flag = 1;
		for( j = 0; j < size - 1 - i; j++ )
		{
			if( a[j] > a[j+1] )
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 0;
			}
		}

		if( flag )// already sorted
			break;
	}
}

void show_array( int size, int a[] )
{
	int i = 0;

	for( i = 0; i < size; i++ )
		printf( " %d", a[i] );

	printf( "\n" );
}


