#include <stdio.h>

int factorial(int x){

	if (x > 1){

		return x * factorial(x-1);
	}

	else if (x == 1){

		return x;
	}
}

int main(){

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int factorial_val = 1;
	int i;

	for (i=0; i<10; i++){

		factorial_val *= array[i];
	}

	printf("10! is %d.\n", factorial_val);

	printf("1! = %i\n", factorial(1));
	printf("3! = %i\n", factorial(3));
	printf("5! = %i\n", factorial(5));

	return 0;

}
