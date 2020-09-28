#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int a;
	struct ListNode *next;
};

void createList(struct ListNode **head, int data) {
	struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode *));
	temp->a = data;
	if(*head == NULL) {
		temp->next = NULL;
		*head = temp;
	} else {
		temp->next = *head;
		*head = temp;
	}
}

struct ListNode *mergeList(struct ListNode *list1, struct ListNode *list2){
	/*struct ListNode *sortedList = NULL;
	if(list1 == NULL) {
		return list2;
	}
	else if(list2 == NULL) {
		return list1;
	}
	if(list2->a <= list1->a) {
		sortedList = list2;
		sortedList->next = mergeList(list1, list2->next);
	} else {
		sortedList = list1;
		sortedList->next = mergeList(list1->next, list2);
	}
	return sortedList;*/
	return (list1 == NULL) ? list2 :
           (list2 == NULL) ? list1 :
             (list1->a < list2->a) ? 
               (list1->next = mergeList(list1->next, list2), list1) : 
               (list2->next = mergeList(list2->next, list1), list2);
}

void display(struct ListNode *list) {
	while(list != NULL) {
		printf("%d->", list->a);
		list = list->next;
	}
	printf("\n");
}

int main() {
	struct ListNode *head1 = NULL;
	struct ListNode *head2 = NULL;

	struct ListNode *sortedList = NULL;
	
	createList(&head1, 1);
	createList(&head1, 2);
	createList(&head1, 4);

	display(head1);

	createList(&head2, 1);
	createList(&head2, 3);
	createList(&head2, 4);

	display(head1);

	sortedList = mergeList(head1, head2);

	display(sortedList);
}