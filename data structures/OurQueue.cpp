#include "OurQueue.h"
#include "error.h"


OurQueue::OurQueue() {
	head = NULL;
	logLen = 0;
}

OurQueue::~OurQueue() {
	while(head != NULL){
		Cell* temp = head->next;
		delete head;
		head = temp;
	}
	
}

int OurQueue::size() {
	return logLen;
}

bool OurQueue::isEmpty() {
	
	return logLen == 0;
}

void OurQueue::enqueue(int value) {
	Cell* newCell = new Cell;
	newCell->value = value;
	newCell->next = NULL;

	Cell* cur = head;
	if(head == NULL){
		head = newCell;
		logLen++;
		
	}else{
		while(cur ->next  != NULL){
			cur= cur->next;
		}
		cur->next = newCell;
		logLen++;
	}
	

}

int OurQueue::front() {
	if(isEmpty()){
		error("peeking empty queue");
	}
	return head->value;
}

int OurQueue::dequeue() {
	if(isEmpty()){
		error("dequeing from an empty queue");
	}
	Cell* cur = head;
	head = head->next;
	int val = cur->value;
	delete cur;
	logLen--;
	return val;
}




//#include "OurQueue.h"
//#include "error.h"
//
//OurQueue::OurQueue() {//	head = NULL;//	logLen = 0;//}////OurQueue::~OurQueue() {//	Cell* tmp;//	while(head != NULL) {//		tmp = head;//		head = head -> next;//		delete tmp;//	}//}////int OurQueue::size() {//	return logLen;//}////bool OurQueue::isEmpty() {//	return size() == 0;//}////void OurQueue::enqueue(int value) {//	Cell* newCell = new Cell;//	newCell -> value = value;//	newCell -> next = NULL;////	if (head == NULL) {//		head = newCell;//	}else {//		Cell* tmp = head;//		while (tmp -> next != NULL) {//			tmp = tmp -> next;//		}//		tmp -> next = newCell;//	}//	//	logLen++;//}////int OurQueue::front() {//	if (isEmpty()) {//		error("No element");//	}//	return head -> value;//}////int OurQueue::dequeue() {//	if (isEmpty()) {//		error("No element");//	}//	int result = 0;//	Cell* tmp = head;//	head = head -> next;//	result = tmp -> value;//	delete tmp;//	logLen--;//	return result;//}
