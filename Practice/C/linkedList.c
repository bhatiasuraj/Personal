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

	// print_list(head);
}

void push_first(node_t ** head, int val) {

	node_t * new_node;

	new_node = malloc(sizeof(node_t));

	new_node->val = val;

	new_node->next = *head;

	*head = new_node;

	// print_list(*head);

}

int remove_first_item(node_t * head) {

	node_t * temp;

	temp = malloc(sizeof(node_t));

	if (&head == NULL) {

		return -1;
	}

	temp->val = head->next->val;

	temp->next = head->next->next;

	free(head->next);

	head->next = temp->next;

	head->val = temp->val;

	return 1;
}

int remove_last_item(node_t * head) {

	node_t * temp = head;

	while(temp->next->next != NULL) {

		temp = temp->next;
	}

	free(temp->next);

	temp->next = NULL;

}

int remove_item(node_t * head, int n) {

	node_t * current = head;

	node_t * temp = NULL;

	if (n == 0) {

		remove_first_item(head);
	}

	for (int i = 0; i < n - 1; i++) {

		if(current->next == NULL) {

			return -1;
		}

		current = current->next;

	}

	temp = current->next;

	current->next = temp->next;

	free(temp);

}

void print_list(node_t * head) {

	node_t * current = head;

	while(current != NULL) {

                printf("%d \t %p\n", current->val, current->next);
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

	push_first(&head, 24);

	print_list(head);

        printf("Added 4 items\n\n");

	remove_first_item(head);

	print_list(head);

        printf("Removed first item\n\n");

	remove_last_item(head);

	print_list(head);

        printf("Removed last item\n\n");

	remove_item(head, 2);

	print_list(head);

        printf("Removed 2nd item\n\n");

	remove_item(head, 1);

        print_list(head);

        printf("Removed 1st item\n\n");

	return 0;

}

