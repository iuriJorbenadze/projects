/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = new Cell;
	tail = new Cell;
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;

	curSize=0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	Cell * ptr = head;
	while(ptr != NULL){
		Cell * temp = ptr;
		ptr = ptr->next;
		delete temp;
	}


}

int DoublyLinkedListPriorityQueue::size() {
	return curSize;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {	
	return curSize == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	Cell * newC = new Cell;
	newC->value =value;

	newC->next = head->next;
	newC->prev = head;

	head->next->prev = newC;  /////////////
	head->next = newC;

	
	curSize++;
}

string DoublyLinkedListPriorityQueue::peek() {
	if(isEmpty()){
		error("Can't peek into empty pqueue.");
	}
	if(curSize == 1){
		return head->next->value;
	}

	Cell * minStr = head->next;
	
	string minVal = minStr->value;
	while(minStr != tail){
		if(minStr->value < minVal){
			minVal = minStr->value;
		}
		minStr = minStr->next;
	}

	return minVal;
	

	
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	string strToDeq = peek();

	Cell * minStr = head->next;

	while(minStr->value != strToDeq){
		minStr = minStr->next;
	}
	
	minStr->prev->next = minStr->next;
	minStr->next->prev = minStr->prev;
	delete minStr;

	curSize--;

	return strToDeq;
}

