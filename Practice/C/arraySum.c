#include <stdio.h>

int main(){

	int average;
	int grades[10];

	grades[0] = 80;
	grades[1] = 85;
	grades[2] = 90;

	average = (grades[0] + grades[1] + grades[2])/3;
	printf("The average of three numbers is: %d\n", average);

	return 0;
}
