#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 16
#define MAX_INDEX ( MAX_COUNT - 1 )

void main()
{
	int A[] = { 15, 14, 13, 12,
							11, 10,  9,  8,
							 7,  6,  5,  4,
							 3,  2,  1,  0};
	int B[] = {  0,  1,  0,  0,
					  	 1,  0,  1,  0,
							 1,  0,  1,  1,
							 1,  1,  0,  0 } ;
	
	int n = 0;
	int result_decimal = 0;
	int hex_value = 0x4ABC;

	for( ; n < MAX_INDEX; n++)
		result_decimal += ( 1 << A[n] ) * B[n];

	printf("hex 2 dec \n");
	printf("hex[%04X] dec[%6d] \n", hex_value, result_decimal);

}

