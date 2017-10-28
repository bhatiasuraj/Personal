#include <stdio.h>


void addone(int * n){

	(*n)++;

}



int main(){


	int n = 1;

	printf("%d\n", n);
	addone(&n);
	printf("%d\n", n);

	return 0;

}
