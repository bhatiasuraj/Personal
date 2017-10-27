#include <stdio.h>


int sum(int a, int b){

	int sum = 0;

	sum = a + b;

	return sum;
}

void sum2(int a, int b){

	int sum;

	printf("Sum is %d\n", (a+b));

}


void print_big(int x){

	if (x > 10){
		printf("%d is big\n", x);
	}
}

int main(){

	printf("Sum is %d\n", sum(3, 4));

	sum2(4,5);

	print_big(12);

	print_big(2);

	return 0;

}
