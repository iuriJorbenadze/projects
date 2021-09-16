/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	// TODO: Fill this in!
	head = new Cell();
	head ->next = NULL;
	//head ->value = 0;

	curSize = 0;

}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	// TODO: Fill this in!
	
	Cell * pointer = head;
	while(pointer != NULL){
		Cell * temp = pointer;
		
		pointer = pointer->next;

		delete temp;
	}
}

int LinkedListPriorityQueue::size() {
	return curSize;
}

bool LinkedListPriorityQueue::isEmpty() {
	return curSize == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	Cell * newC = new Cell();
	newC->value = value;

	if(isEmpty()){
		newC->next = NULL;
		head->next = newC;
		curSize++;
		return;
	}
	
	Cell * ptr = head;


	if(ptr ->  next != NULL){
		while(ptr ->next -> value < value){
		
			if( ptr ->  next->next == NULL){
				
				newC->next = NULL;
				ptr->next->next = newC;

				curSize++;
				
				return;
			}

			ptr = ptr ->  next;

		}
	}

	newC->next = ptr->next;
	ptr->next = newC;

	curSize++;

}

string LinkedListPriorityQueue::peek() {
	

	if(isEmpty()){
		error("Can't peek into empty pqueue.");
	}
	
	return head->next->value;
}

string LinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	
	string res = peek();

	Cell* temp = head->next;
	head->next = temp->next;
	delete temp;

	curSize--;

	return res;
}

