#include <stdio.h>


int main(){

	/*

	int a = 1;

	printf("Value of &a is %p\n", &a);

	int * pointer_to_a = &a;

	int ** double_pointer;

	double_pointer = &(pointer_to_a);

	printf("Value of a = %d\n", a);

	printf("Value of a is also %d\n", *pointer_to_a);

	printf("Value of a is also %d\n", **double_pointer);

	printf("Pointer to a is %p\n", pointer_to_a);

	(*pointer_to_a)++;

	printf("Value of a = %d\n", a);

	*/

	printf("%lu\n\n", sizeof(int));

	int a[] = {10, 20, 30, 40, 50, 60};

	int * ptr = a;

	printf("Address of a[0] is %p\n", &a[0]);

	printf("Pointer to a is %p and value of pointer is %d\n" , ptr, *ptr);

	return 0;

}

