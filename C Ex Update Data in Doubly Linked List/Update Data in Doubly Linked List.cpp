// C Ex Update Data in Doubly Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

//display the list
void printList() {
	struct node *ptr = head;

	printf("\n[head] <=>");
	//start from the beginning
	while (ptr != NULL) {
		printf(" %d <=>", ptr->data);
		ptr = ptr->next;
	}

	printf(" [last]\n");
}

//Create Linked List
void insert(int data) {
	// Allocate memory for new node;
	struct node *link = (struct node*) malloc(sizeof(struct node));

	link->data = data;
	link->prev = NULL;
	link->next = NULL;

	// If head is empty, create new list
	if (head == NULL) {
		head = link;
		return;
	}

	current = head;

	// move to the end of the list
	while (current->next != NULL)
		current = current->next;

	// Insert link at the end of the list
	current->next = link;
	last = link;
	link->prev = current;
}

void update_data(int old, int new_) {
	int pos = 0;

	if (head == NULL) {
		printf("Linked List not initialized");
		return;
	}

	current = head;
	while (current != NULL) {
		pos++;

		if (current->data == old) {
			current->data = new_;
			printf("\n%d found at position %d, replaced with %d\n", old, pos, new_);
			return;
		}

		if (current->next != NULL)
			current = current->next;
		else
			break;
	}
	printf("%d does not exist in the list\n", old);
}

int main() {
	insert(10);
	insert(20);
	insert(30);
	insert(1);
	insert(40);
	insert(56);

	printList();
	update_data(56, 99);
	printList();

	return 0;
}