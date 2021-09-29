/* You can allocate and release memory when required. 
Four functions: 
	malloc() -memory allocation, 
	clloc() -contiguous allocation, 
	free() -deallocate,
	realloc() -re-allocate.
	*/
#include <stdio.h>
#include <stdlib.h> //has all the memory alloc functions.

int main() {
	
	int *ptr;
	int num, sum=0;
	
	num=8;
	printf("We have %d elements to allocate memory to \n", num);
	
	//we're going to dynamically allocate the memory
	//syntax: ptr = (cast-type*) malloc(total-byte-size)
	//syntax: ptr = (cast-type*) calloc(byte-size, elem-size)
	//syntax: ptr = realloc(ptr, newsize)
	
	ptr = (int*) malloc( num*sizeof(int) );
	//ptr = (int*) calloc( num, sizeof(int) );
	
	if(ptr == NULL){
		printf("Memory allocation failed");
		exit(0);
	}
	else {
		printf("Memory allocation is successful\n");
	}
	
	for(int i=0; i<num; i++){
		ptr[i] = i+1;
	}
	
	printf("inserted %d elements in the block are as follows:\n", num);
	for(int i=0; i<num; i++){
		printf("%d, ", ptr[i]);
	}
	printf("\n");
	
	num = 16;
	ptr = realloc(ptr, num*sizeof(int));
	printf("Memory has been reallocated\nThere are the values in the pointer right now.");
	for(int i=0; i<num; i++){
			printf("%d, ", ptr[i]);
	}
	printf("\n");
	
	
	
	free(ptr); 
	printf("Memory has been de-allocated\n");
	if(ptr == NULL){
		printf("Ptr is null after de-allocation\n");
		exit(0);
	}
	else{
		printf("Ptr is not null after de-allocation. Let's see the values in it.\n");
		for(int i=0; i<num; i++){
			printf("%d, ", ptr[i]);
		}
		printf("\n");
	}
}
