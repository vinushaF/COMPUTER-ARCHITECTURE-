#include <stdio.h>
 
int main() {
	int variable = 42;
	int *pointer = &variable;
 
    printf("Original value at memory location: %d\n", *pointer);
 
    // Modify the value at the memory location directly
	*pointer = 99;
 
    printf("Modified value at memory location: %d\n", *pointer);
 
    return 0;
}
