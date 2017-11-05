#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {

	int val;

	struct node_t * next;


} node_t;

void printList();
void InsertAtHead(int data);

node_t * head;

struct node_t * CreateNewNode(int data) {

	node_t * newNode;

	newNode = malloc(sizeof(node_t));

	newNode->val = data;

	newNode->next = NULL;

	return newNode;

}

struct node_t * mergeLists(node_t * headA, node_t * headB) {

	if(headA==NULL && headB==NULL)  { return NULL; }

	if(headA!=NULL && headB==NULL) { return headA; }
    
	if(headA == NULL && headB!=NULL) { return headB; }
    
	if(headA->val < headB->val) {
        
        	headA->next = mergeLists(headA->next, headB);
        
    	}

    	else if(headA->val > headB->val)
	{

		node_t * temp = headB;

		headB = headB->next;

		temp->next = headA;

		headA = temp;

		headA->next = mergeLists(headA->next, headB);
    }

    return headA;

}

void InsertAtHead(int data) {


	node_t * new_Node = CreateNewNode(data);

	new_Node->next = head;

	head = new_Node;

}

void InsertAtTail(int data) {

	node_t * newNode = CreateNewNode(data);

	node_t * current = head;

	while(current->next != NULL) {

		current = current->next;

	}

	current->next = newNode;

}

void InsertAtPosition(int data, int pos) {

	node_t * newNode = CreateNewNode(data);

	node_t * current = head;

	node_t * temp;

	int position = 0;

	if(pos == 0) { InsertAtHead(data) ; }

	while(position != pos-1) {

		current = current->next;

		position++;
	}

	temp = current->next;

	current->next = newNode;

	newNode->next = temp;

}

void reverseList() {

	node_t * prev = NULL;

	node_t * current = head;

	node_t * next;

	if (head == NULL) { return; }

	while(current != NULL) {


		next = current->next;

		current->next = prev;

		prev = current;

		current = next;
	}

	head = prev;

}

void deleteNodeByValue(int data) {

	node_t * current = head;

	node_t * temp;

	temp = malloc(sizeof(node_t));

	while(current->next != NULL) {

		if (current->next->val == data) {

			temp = current->next;

			current->next = temp->next;

			free(temp);

			return;
		}

	current = current->next;

	}

	printf("Node not found!\n");	

}

void deleteNodeByPosition(int pos) {

	node_t * current = head;

	int position = 0;

	node_t * temp;

	temp = malloc(sizeof(node_t));

	// Delete first node

	if(pos == 0) {

		temp = current;

		head = temp->next;

		free(temp);

		return;

	}

	while(current->next != NULL) {

		if(position == pos-1) {

			temp = current->next;

			current->next = temp->next;

			free(temp);

			return;

		}

		position++;

		current = current->next;
	}


	printf("No element at position %d\n", pos);

}

void removeHead() {

	node_t * temp;

	temp = head->next;

	free(head);

	head = temp;

}

void deleteLastNode() {

	node_t * current = head;	

	while(current->next->next != NULL) {

		current = current->next;

	}

	free(current->next);

	current->next = NULL;

}

void swap(node_t * xp, node_t * yp) {

	int temp = xp->val;

	xp->val = yp->val;

	yp->val = temp;

}

void bubbleSort() {

	int swapped;

	node_t * ptr1;

	node_t * lptr = NULL;

	// if(ptr1 == NULL) { return; }

	do
	{
		swapped = 0;

		ptr1 = head;

		while(ptr1->next != lptr) {

			if(ptr1->val > ptr1->next->val) {

				swap(ptr1, ptr1->next);

				swapped = 1;
			}
			
			ptr1 = ptr1->next;
		}

		lptr = ptr1;
		
	}
	while(swapped);

}

void getNodeHead(int pos) {

	node_t * current = head;

	int position = 0;

	while(current != NULL) {

		if(position == pos) {

			printf("Value at position %d from head: %d\n", pos, current->val);

			return;

		}

		position++;

		current = current->next;

	}

	printf("No node at position %d\n", pos);


}

void getNodeTail(int pos) {

	reverseList(head);

	node_t * current = head;

	int position = 0;

	while(current != NULL) {

		if(pos == position) {

			printf("Value at position %d from tail: %d\n", pos, current->val);

			return;

		}

		position++;

		current = current->next;

	}

	printf("No node at position %d\n", pos);


}

void printList() {


	node_t * current = head;

	while(current != NULL) {


		printf("%d ", current->val);

		current = current->next;

	}

	printf("\n");	

}

int main() {

	InsertAtHead(6);

	InsertAtTail(3);

	InsertAtHead(4);

	printList();

	reverseList();

	printList();

	deleteNodeByValue(4);

	InsertAtHead(2);

	InsertAtHead(5);

	removeHead();

	InsertAtPosition(2, 3);

	deleteNodeByPosition(0);

	deleteLastNode();

	InsertAtHead(6);

	InsertAtTail(0);

	InsertAtHead(4);

	printf("Unsorted list: ");

	printList();	

	bubbleSort();

	printf("Sorted list: ");

	printList();

	reverseList();

	printf("Reversed list: ");

	printList();

	getNodeHead(4);

	getNodeTail(1);

	return 0;

}
