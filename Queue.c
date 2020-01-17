#include <studio.h>

int isEmpty(CircularLinkedListNode **pointer);
int addEnd(CircularLinkedListNode **pointer, int toAdd);
int removeStart(CircularLinkedListNode **pointer);

//underlying data structure for Queue is the circular linked list 
struct CircularLinkedListNode{
	int data;
	struct CircularLinkedListNode *next;
}


int isEmpty(CircularLinkedListNode **pointer){
	if (*pointer==NULL){
		return 1;
	} else {
		return 0;
	}	
}

//adds to end of list retrns 1 if successful, 0 if unsuccessful
int addEnd(CircularLinkedListNode **pointer,int toAdd){
	if (*pointer==NULL){
		*pointer=malloc(sizeOf(CircularLinkedListNode));
		if (*pointer==NULL){
			//malloc failed for some reason
			return 0;
		} else {
			*pointer->data=toAdd;
			return 1;
		}
		
	} else {
		CircularLinkedListNode *nextNode = malloc(sizeOf(CircularLinkedListNode));	
		if (nextNode==NULL){
			return 0;
		} else {
			nextNode->next=*pointer->next;	
			nextNode->data=toAdd;
			*pointer->next=nextNode;
			*pointer=nextNode;
			return 1;

		}
		
	}
}

//removes the start of the list and returns it, or -123 if there is an error
int removeStart(CircularLinkedListNode **pointer){
	if (*pointer==NULL){
		return -123;
	} else {
		if (*pointer->next==NULL){
			free(*pointer);
		} else {
			CircularLinkedListNode *nextNode = *pointer->next;
			int toReturn = nextNode->data;
			*pointer->next=nextNode->next;
			free(nextNode);
			return toReturn;
		}
	}		
}



