#include <studio.h>

int pop(Stack * pointer);
int push(Stack * pointer, int toAdd);
int peek(Stack * pointer);

//stack implementation using a linked list (which is in this directory)
struct Stack{
	struct linkedList *stack;
}

void main(){

}

//returns if push was successful or not
int push(Stack * pointer, int toAdd){
	if (pointer==NULL){
		return -123;
	}
	linkedList *list = pointer->stack; 
	linkedList **pointToList =list;
	return linkedList.add(pointToList,toAdd);	
}

//returns the popped int 
//if stack is empty, it returns -123
int pop(Stack * pointer){
	if (pointer==NULL){
		return -123;
	}
	linkedList *list = pointer->stack;
	if (list==NULL){
		return -123;
	} else {
		linkedList *newHead = list->next;
		int toReturn=list->data;
		free(list);
		pointer->stack=newHead;
		return data;
	}

}

//returns top of stack without popping, if error then returns -123
int peek(Stack *pointer){
	if (pointer==NULL){
		return -123;
	}
	linkedList *list=pointer->stack;
	if (list==NULL){
		return -123;
	} else {
		return list->data;
	}
}





