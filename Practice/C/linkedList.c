#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node * next ;
} node_t;

void print_list(node_t * head);


void push_last(node_t * head, int val){

	node_t * current = head;

	while(current->next != NULL) {

                current = current->next;
        }

	current->next = malloc(sizeof(node_t));

	current->next->val = val;

        current->next->next = NULL;

	print_list(head);
}

void push_first() {


}


void print_list(node_t * head) {

	node_t * current = head;

	while(current != NULL) {

                printf("%d\n", current->val);
                current = current->next;
        }

}

int main(){

	node_t * head = NULL;

	head = malloc(sizeof(node_t));

	if(head == NULL) {

		return 1;
	}


	head->val = 1;

	head->next = malloc(sizeof(node_t));

	head->next->val = 2;

	head->next->next = NULL;

	push_last(head, 6);

	push_last(head, 8);

	push_first(head, 24);

	return 0;

}
