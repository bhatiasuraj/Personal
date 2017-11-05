#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {

	int val;
        struct node_t * next;
        struct node_t * prev;

} node_t;

node_t * head;

struct node_t * CreateNewNode (int data) {

	node_t * new_node;

	new_node = malloc(sizeof(node_t));

	new_node->val = data;

	new_node->prev = NULL;

	new_node->next = NULL;

	return new_node;

};

void InsertAtHead (int data) {

	node_t * new_node = CreateNewNode(data);

	if (head == NULL) {

		head = new_node;

		return;

	}

	head->prev = new_node;

	new_node->next = head;

	head = new_node;

}

void InsertAtTail (int data) {

	node_t * temp = head;

	node_t * new_node = CreateNewNode(data);

	if (head == NULL) {

		head = new_node;

		return;

	}

	while (temp->next != NULL) { temp = temp->next; }

	temp->next = new_node;

	new_node->prev = temp;

}

void printList() {

	node_t * temp = head;

	printf("Forward: ");

	while(temp != NULL) {

		printf("%p <=> %d <=> %p", temp->prev, temp->val, temp->next);

		temp = temp->next;

	}

	printf("\n");

}

void printReverseList() {


	node_t * temp = head;

	printf("Reverse: ");

	while(temp->next != NULL) {

		temp = temp->next;

	}

	while (temp != NULL) {

		printf("%d ", temp->val);

		temp = temp->prev;

	}
}

int main() {

	InsertAtHead(4); printList();

	InsertAtHead(2); printList();

	InsertAtTail(24); printList();

	InsertAtHead(55); printList();

	return 0;

}
