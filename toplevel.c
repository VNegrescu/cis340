/* toplevel.c - introduces the basic logic of creating and linking nodes in a list.
 *
 */
#include	<stdio.h>
#include	<stdlib.h>

struct node{
	int val;
	struct node * next;
};

int main()
{
	struct node *head = NULL;	/* declare head & tail */
	struct node *tail = NULL;
	struct node *current = NULL;

	head = malloc(sizeof(struct node));	/* create first node & append to list */
	head->val = 1;
	tail = head;

	tail->next = malloc(sizeof(struct node));	/*link 1st node with new node */
	tail = tail->next;				/* update position of tail */
	tail->val = 22;

	tail->next = malloc(sizeof(struct node));
	tail = tail->next;
	tail->val = 3;
	tail->next = NULL;				/* end of list	*/

	current = head;
	while( current != NULL)
	{
		printf("%i\n", current->val);
		current = current->next;
	}
}
