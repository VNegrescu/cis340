/* toplevel.c - implements CreateList(), Add(), and PrintList()
 *
 */
#include	<stdio.h>
#include	<stdlib.h>


struct node{
	int 		val;
	struct node 	*next;
};


struct node *Head = NULL;	/* Global End ptr */
struct node *Cur = NULL;
struct node *End = NULL;	

struct node *CreateList();	/* Function prototype */
void Add(int newVal);		
void PrintList();

/*
 *		MAIN Section
 */
int main(){
	End = CreateList();
	PrintList();
}
/*
 *
 */

struct node *CreateList()
/*
 * creates a linked list. returns the End Ptr.
 */
{
	Add(3);
	Add(1);
	Add(2);
	Add(122);
	return End;	
}
void Add(int newVal)
/*
 * place a new process at end of list
 */
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->val = newVal;

	if( End == NULL ){
		Head = End = newNode;
	}
	else{
		End->next = newNode;
		End = End->next;
		End->next = Head;
	}
}

void PrintList()
/*
 * goes through every node in the list and prints data
 */
{
	struct node *index = Head;
	do{
		printf("%i\n", index->val);
		index = index->next;
	}
	while( index != Head);
}
