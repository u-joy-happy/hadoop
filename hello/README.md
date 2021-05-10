# Decimal to Hexadecimal

```
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
        // 4ABC
        int B[] = {  0,  1,  0,  0,
                     1,  0,  1,  0,
                     1,  0,  1,  1,
                     1,  1,  0,  0 } ;
        
        int n = 0;
        int result_decimal = 0;
        int hex_value = 0x4ABC;

        for( ; n < MAX_INDEX; n++)
                result_decimal += ( 1 << A[n] ) * B[n];
                // left shift 
                // (0000 0000 0000 0001 << 14) * 1 = 16,384
                // (0000 0000 0000 0001 << 11) * 1 = 2,048
                // (0000 0000 0000 0001 <<  9) * 1 = 512
                // (0000 0000 0000 0001 <<  7) * 1 = 128
                // (0000 0000 0000 0001 <<  5) * 1 = 32
                // (0000 0000 0000 0001 <<  4) * 1 = 16
                // (0000 0000 0000 0001 <<  3) * 1 = 8
                // (0000 0000 0000 0001 <<  2) * 1 = 4
                // 16,384 + 2,048 + 512 + 128 + 32 + 16 + 8 + 4 = 19,132
                       
        printf("hex 2 dec \n");
        printf("hex[%04X] dec[%6d] \n", hex_value, result_decimal);

}
```
