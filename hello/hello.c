#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Hello C World\n");

	char hex = 'A';
	int res = 0;

	res = strtol(hex, NULL, 16);

	printf("%s => %d\n",hex, res);
	return 0;
}
	
