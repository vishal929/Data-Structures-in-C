//my implementation of a hash table in c


#include <studio.h>
#include <math.h>


int insert(HashTable *pointer, int value, char *key);
int removeByKey(HashTable *pointer, char *key);
int removeByValue(HashTable *pointer, int value);
int rehash(HashTable *pointer);

//implementing HashTable using buckets (linked lists at each node)

struct Node{
	int value;
	//the hashValue is the result of the hashFunction before taking the modulus operator
	//this is so we do not have to apply the hashFunction to the string again
	int hashValue;	
	char *key;
	//next for collisions
	Node *next;
}


struct HashTable{
	//we start with 20 slots and we will double every time we need to rehash
	struct Node bucket[20];	
	int items;
	int size=20;	
	double threshold;
}

//insert into hashtable, will call rehash if insertion would mean going over the threshold
int insert(HashTable *pointer, int value, char *key){
	if ((pointer->items+1)/size >threshold){
		//need to rehash, then add
		if (rehash(pointer)==1){
			
		} else {
			//then rehash was unsuccessful 
			return 0;
		}
	} else {
		//then we add normally

		//invoking hash function
		//we are using s[0]+s[1]p+s[2]p^2...
		unsigned long sum=0;
		int count=0;
		char *runner=key
		while(runner!=NULL){
			sum+=runner*pow(51,count);
			count++;
			runner=runner+1;
		}
		int position = sum % (pointer->size);
		//creating node and adding it to the list
	}

}


int rehash(HashTable *pointer){
	struct Node newBucket[2*pointer->size]=malloc(sizeof(Node)*2*pointer->size);			
	if (newBucket==NULL){
		//something went wrong with malloc
		return 0;
	} else {
		//then we can start wih rehashing
		int counter;
		for (counter=0;counter<size;counter++){
			Node bucket = pointer->bucket[counter];
			//setting bucket to point to nothing, so I can reuse the nodes and save space in rehashing
			pointer->bucket[counter]=NULL;
			while(bucket!=null){
				int position=(bucket->hashValue)%(2*size);	
				bucket->next=newBucket[position];
				newBucket[position]=bucket;
				bucket=bucket->next;
			}
		}
		size=2*size;
		free(pointer->bucket);
		pointer->bucket=newBucket;
		return 1;
	}
}
