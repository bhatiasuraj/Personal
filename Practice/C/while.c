#include <stdio.h>

int main(){

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int i = 0;

	while (i < 10) {

		if (array[i] < 5){
			i++;
			continue;
		}

		else if (array[i] > 10){
			break;
		}

		printf("%d\n", array[i]);

		i += 1;
	}
	return 0;

}
