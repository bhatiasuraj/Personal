#include <stdio.h>


int main(){

	int a = 1;

	int * pointer_to_a = &a;

	printf("Value of a = %d\n", a);

	printf("Value of a is also %d\n", *pointer_to_a);

	printf("Pointer to a is %p\n", pointer_to_a);

	(*pointer_to_a)++;

	printf("Value of a = %d\n", a);

	return 0;

}

