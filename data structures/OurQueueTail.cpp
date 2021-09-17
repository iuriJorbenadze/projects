
#include "OurQueueTail.h"
#include "error.h"

OurQueueTail::OurQueueTail() {
	logLen = 0;
	head = NULL;
	tail = NULL;
}

OurQueueTail::~OurQueueTail() {
	Cell * temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}

}

int OurQueueTail::size() {
	return logLen;
}

bool OurQueueTail::isEmpty() {
	return logLen == NULL;
}

void OurQueueTail::enqueue(int value) {
	Cell* newCell = new Cell;
	newCell->value = value;
	newCell->next = NULL;
	
	if(head = NULL){
		head = newCell;
		tail = newCell;
	}else{
		tail->next = newCell;
		tail = newCell;

	}
	logLen++;


}

int OurQueueTail::front() {
	if(isEmpty()) error("peeking from an empty queue");
	return head->value;
}

int OurQueueTail::dequeue() {
	int res = front();
	Cell* temp = head;
	head = head->next;
	delete temp;
	if(head == NULL){
		tail = NULL;
	}
	logLen--;
	return res;

}


