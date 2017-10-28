#include <stdio.h>

typedef struct{

	char * name;
	int age;
} person;


void birthday(person * john){

        printf("%s is %d years old\n", john->name, john->age);

        john->age++;

        printf("%s is %d years old\n", john->name, john->age);

}

int main(){


	person john;

	john.name = "John";

	john.age = 24;

	// printf("%s is %d years old\n", john.name, john.age);

	birthday(&john);

	// printf("After a year, %s is %d years old\n", john.name, john.age);

	return 0;

}
