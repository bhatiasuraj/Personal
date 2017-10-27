#include <stdio.h>
#include <string.h>

int main(){
	char * name2 = "Suraj Bhatia";

	char name[20] = "BYE";
	int age = 24;

	printf("%s is %d years old.\n", name, age);

	printf("Length of string is %ld\n",strlen(name2));

	if (strncmp(name2, "Suraj", 5) == 0){
		printf("Hi, Suraj!\n");
	}
	else {
		printf("BYE\n");
	}

	strncat(name,"HI",4);

	printf("%s\n", name);

	return 0;
}
