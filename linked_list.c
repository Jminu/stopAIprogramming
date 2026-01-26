#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct list_node {
	struct list_node *next;
	struct list_node *prev;
	int data;
};

void list_init(struct list_node *head, int data) {
	head->next = head;
	head->prev = head;
	head->data = data;
}

void list_add(struct list_node *new, struct list_node *head) {
	new->next = head->next;
	new->prev = head;

	head->next->prev = new;
	head->next  = new;
}

void list_del_init(struct list_node *entry) {
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;

	list_init(entry, entry->data);
}

void list_move(struct list_node *entry, struct list_node *dst_list) {
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;

	list_add(entry, dst_list);
}

void print_list(struct list_node *head) {
	struct list_node *phead = head;
	struct list_node *plist;

	for(plist = phead->next; plist != phead; plist = plist->next) {
		if (plist->next == phead)
			printf("[%d]\n", plist->data);
		else
			printf("[%d]-", plist->data);
	}

}

int main(void) {
	struct list_node auth_list;
	struct list_node free_list;
	struct list_node *plist;
	struct list_node *tmp;

	list_init(&auth_list, -1);
	list_init(&free_list, -1);

	for (int i = 1; i <= 4; i++) {
		struct list_node *new = malloc(sizeof(struct list_node));
		list_init(new, i);
		list_add(new, &auth_list);
	}
	print_list(&auth_list);
	printf("===== Original Auth List =====\n");

	for (plist = auth_list.next, tmp = plist->next; plist != &auth_list; 
			plist = tmp, tmp = plist->next) {
		if (plist->data % 2 == 0)
			list_move(plist, &free_list);
	}
	print_list(&free_list);
	printf("===== Free List =====\n");

	for (plist = free_list.next, tmp = plist->next; plist != &free_list; 
			plist = tmp, tmp = plist->next) {
		list_del_init(plist);
		free(plist);
	}
	print_list(&free_list);
	printf("===== Free List =====\n");

	return 0;
}
