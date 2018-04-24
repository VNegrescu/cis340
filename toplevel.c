/* toplevel.c - implements all methods except ScanList() and File I/O.
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
int size = 0;	

struct node *CreateList();	/* Function prototype */
void Add(int newVal);
struct node *ScanList(struct node *End);
struct node *RemoveCurrent(struct node *Current);		
void PrintList();

/*
 *		MAIN Section
 */
int main(){
	End = CreateList();
	Cur = End->next;
	for(int i = 0; i < 7; i++){
		PrintList();
		printf("\n");
		sleep(1);
		Cur->val -= 1;
		if( Cur-> val == 0){
			RemoveCurrent(Cur);
		}
		Cur = Cur->next;
	}
	/*
	PrintList();
	printf("\n");
	
	Head = Cur = End->next;
	RemoveCurrent(Cur);
	PrintList();
	printf("\n");

	Cur = Cur->next;
	RemoveCurrent(Cur);
	PrintList();
	*/
}
/*
 *
 */

struct node *CreateList()
/*
 * creates a linked list. returns the End Ptr.
 */
{
	Add(3);		/* add node at end of list */
	Add(1);
	Add(2);
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
		Head = End = newNode;	/* only one node in list */
	}
	else{
		End->next = newNode;	/* connect node to first node */
		End = End->next;	/* update end ptr to end of list */
		End->next = Head;	/* circular linked list */
	}
	size++;
}

struct node *ScanList(struct node *End)
/*
 *
 */
{
	struct node *thisNode = End->next;
	if( thisNode->val == 0 )
		RemoveCurrent(thisNode);	
}

struct node *RemoveCurrent(struct node *Current)
/*
 *   
 */
{
	if(size == 0) return NULL;	/* empty list */
	else{
		struct node *previous = Current;
	
		for(int i = 1; i < size; i++){
			previous = previous->next;	/* locate previous */
		}

		Current = previous->next;		
		previous->next = Current->next;		/* remove current */
		size--;
		return Current;
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
