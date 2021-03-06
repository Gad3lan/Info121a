#include "header.hpp"

list *new_list() {
	list *l = (list*) malloc (sizeof(list));
	l -> head = NULL;
	l -> nb = 0;
	return l;
}

void show_list(list *l) {
	node *n = l -> head;
	while (n != NULL) {
		cout << n -> data << " ";
		n = n -> next;
	}
	cout << endl;
}

void add_head(list *l, int val) {
	node *n = (node*) malloc (sizeof(node));
	n -> data = val;
	n -> next = l -> head;
	l -> head = n;
	l -> nb++;
}

void add_end(list *l, int val) {
	node *n = l -> head;
	node *newn = (node*) malloc (sizeof(node));
	newn -> next = NULL;
	newn -> data = val;
	while (n -> next != NULL) {
		n = n -> next;
	}
	n -> next = newn;
}

void delete_val(list *l, int val) {
	node * current = l -> head;
	if (current -> data == val) {
		l -> head = current -> next;
		free(current);
		return;
	}
	node *previous = (node*) malloc (sizeof(node));
	while (current != NULL) {
		previous = current;
		current = current -> next;
		if (current -> data == val) {
			previous -> next = current -> next;
			free(current);
			break;
		}
	}
}

int search_max(list *l) {
	node *n = l -> head;
	int max = -2147483648;
	while(n != NULL) {
		if (n -> data > max)
			max = n -> data;
		n = n -> next;
	}
	return max;
}

void free_list(list *l) {
	node *previous = l->head;
	node *current = previous -> next;
	while (current != NULL) {
		free(previous);
		previous = current;
		current = current -> next;
	}
}