#include <stdio.h>

int main(){

	int average;
	int grades[10];
	int *ptr;

	grades[0] = 80;
	grades[1] = 85;
	grades[2] = 90;

	ptr = grades;

	printf("Pointer to array is %p and first value is %d\n", ptr, ptr[0]);

	// average = (grades[0] + grades[1] + grades[2])/3;

	average = (ptr[0] + ptr[1] + ptr[2])/3;

	printf("The average of three numbers is: %d\n", average);

	return 0;
}
