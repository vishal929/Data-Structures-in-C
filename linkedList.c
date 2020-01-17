#include <studio.h>

int add(linkedList **pointer, int toAdd);
int addAtEnd(linkedList** pointer, int toDelete);
int delete(linkedList **pointer, int toDelete);
int deleteFirst(linkedList **pointer);
int deleteLast(linkedList **pointer);
void printList(linkedList **pointer);

struct linkedList{

	int data;
	struct linkedList *next;

}

void main(){

}

int add(linkedList **pointer, int toAdd){
	linkedList *newHead = malloc(sizeOf(linkedList));
	if (newHead==NULL){
		//something failed with malloc
		return 0;
	} else {
		newHead->data=toAdd;
		newHead->next=*pointer;
		*pointer=newHead;	
		return 1;
	}
		
}

int addAtEnd(linkedList **pointer, int toAdd){
	linkedList *newNode = malloc(sizeOf(linkedList));	
	if (newNode==NULL){
		return 0;
	} else {
		newNode->data=toAdd;
		linkedList *runner = *pointer;
		while(runner->next!=NULL){
			runner=runner->next;
		}
		runner->next=newNode;
	}
	
}

int delete(linkedList **pointer, int toDelete){
	linkedList *runner = *pointer;
	linkedList *prev = NULL;
	if (runner==NULL){
		//then linked list is empty->nothing to delete
		return 0;	
	}

	while(runner->data!=toDelete && runner!=NULL){
		prev=runner;
		runner=runner->next;

	}
	if (runner==NULL){
		//then no such item in the list
		return 0;
	} else {
		//then we found node to delete
		if (prev==NULL){
			//then we need to delete the head
			linkedList *newHead = *pointer->next;
			free(*pointer);
			*pointer=newHead;
			return 1;
		} else {
			//then we can go about deleting as usual
			//runner is the node to delete and prev is the node before it
			prev->next=runner->next;
			free(runner);
			return 1;
		}
	}
}

int deleteFirst(linkedList **pointer ){
	if (*pointer==NULL){
		//then this pointer points to a null pointer
		return 0;
	} else {
		linkedList * newHead = *pointer->next;
		free(*pointer);
		*pointer=newHead;
		return 1;
	}
}

int deleteLast(linkedList **pointer){
	if (*pointer==NULL){
		//list is empty
		return 0;
	} else {
		//need to check if next is empty, if so then we are just deleting the head
		if (*pointer->next==NULL){
			//then we only have a head in the list
			free(*pointer);
			return 1;
		} else {
			linkedList *runner = *pointer;
			while(runner->next!=NULL){
				runner=runner->next;
			}
			free(runner);
			return 1;
			
		}
	}
}

void printList(linkedList **pointer){
	if (*pointer==NULL){
		printf("The List is Empty!");
	} else {
		linkedList *runner = *pointer;
		while(runner!=NULL){
			printf(runner->data + "--->");
		}
	}
}



