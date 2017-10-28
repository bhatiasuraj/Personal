#include <stdio.h>

typedef struct {

	char * name;
	int age;
	int x;
	int y;

} point;

void move(point * p){

        (*p).x++;
        (*p).y++;

	p->x++;
	p->y++;

	printf("%d\n", p->x);
	printf("%d\n", p->y);

}

int main(){

	point p;

	p.name = "John";

	p.age = 23;

	p.x = 2;

	p.y = 4;

	move(&p);

	printf("%d\n", p.x);

	printf("%d\n", p.y);

	printf("%s is %d years old\n", p.name, p.age);

}

