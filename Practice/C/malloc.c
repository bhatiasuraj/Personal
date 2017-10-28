#include <stdio.h>
#include <stdlib.h>

typedef struct{


	int age;
	char * name;
}person;


int main(){


	person * p;

	p = malloc(sizeof(person));

	p->name = "Suraj";
	p->age = 24;

	// p.name = "Suraj";
	// p.age = 24;

	printf("%s is %d years old\n", p->name, p->age);


	return 0;

}
