#include <stdio.h>
#include <stdlib.h>


int main(){


	char vowels[] = {'a', 'e', 'i', 'o', 'u'};

	char *pvowels = &vowels;


	// Print addresses

	for (int i = 0; i < 5; i++) {
    		printf("&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
	}

	// Print the values

	for (int i = 0; i < 5; i++) {
		printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
	}

	return 0;

}
