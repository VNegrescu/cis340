#include	<stdio.h>
#include	<stdlib.h>

struct node{
	int val;
	struct node * next;
};

void Add(int newVal);
struct node* CreateList();
void PrintList();

struct node *End = NULL;	/* global variable ? */
struct node *Cur = NULL;
int size = 0;

int	main()
{
	End = CreateList();
	PrintList();
}

struct node* CreateList()
/*
 * create a linked list. Returns End pointer to the node.
 */
{
	struct node * End = NULL;
	Add(1);
	Add(22);
	Add(333);
	return End;
}

void Add(int newVal)
/* 
 * pleaces a new node at end of list. 
 */
{
	struct node *newNode = malloc(sizeof(struct node));	/* create a new node	*/
	newNode->val = newVal;			/* update data field inside new node */
	
	if( End == NULL ){
		Cur = End = newNode;	/* only node in the list */
	}
	else{
		End->next = newNode;	/* link the new node with the last node */
		End = End->next;	/* tail now points to the last node */
	}
	
	size++;	
}

void PrintList()
/*
 * goes through every node in list and prints the contents
 */
{
	while ( Cur != NULL ){			/* check last node */
		printf("%i\n", Cur->val);		
		Cur = Cur->next;		/* next node */
	}
}
