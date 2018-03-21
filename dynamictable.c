#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){

	char*  table1 = (char *) malloc(sizeof(char));
	int size1 = 1;

	int num = 0;

	int i;
	long long int count1 = 0;

//First two methods are asymptotically the same in terms of space and time

//Per operation, takes O(n).
//Total loop takes quadratic time O(n^2)
	for(i=0; i<1100000; ++i){
		if(num == size1){
			size1++;
			table1 = (char *) realloc(table1, size1);
			count1 += size1;
		}
		num++;
		count1;
		if((i & (i-1)) == 0){
			printf("\nCount od %d is %lld", i, count1);
		}
	}

size1 = 0;
count1 = 0;
num = 0;
free(table1);
table1 = (char *) malloc(sizeof(char));

//Per operation, takes O(n)/1024
//Total loop takes quadratic time <- n+ ((n+1)/1024) * i
//Wastes more space (constant)
	for(i=0; i<1100000; ++i){
		if(num == size1){
			size1 +=  1024;
			table1 = (char *) realloc(table1, size1);
			count1 += size1;
		}
		num++;
		count1;
		if((i & (i-1)) == 0){
			printf("\nCount of %d is %lld", i, count1);
		}
	}

size1 = 1;
count1 = 0;
num = 0;
free(table1);
table1 = (char *) malloc(sizeof(char));


//These two methods 
//Load factor = num/size, and is always a constant factor of size

//Per operation O(n)
//Total loop quadratic time <- n + ((n+1)/2^i) * i
//Wastes space (1/2 the table)
for(i=0; i<1100000; ++i){
		if(num == size1){
			size1 *= 2;
			table1 = (char *) realloc(table1, size1);
			count1 += size1;
		}
		num++;
		count1;
		if((i & (i-1)) == 0){
			printf("\nCount of %d is %lld", i, count1);
		}
	}


size1 = 1;
count1 = 0;
num = 0;
free(table1);
table1 = (char *) malloc(sizeof(char));

//Per operation, takes O(n)
//Total loop quadratic time 
//Wastes less space (1/3rd of table)
for(i=0; i<1100000; ++i){
		if(num == size1){
			size1 *= (long long int) ceil((double)size1 * 1.5 );
			table1 = (char *) realloc(table1, size1);
			count1 += size1;
		}
		num++;
		count1;
		if((i & (i-1)) == 0){
			printf("\nCount of %d is %lld", i, count1);
		}
	}



}