/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

const int kDefaultSize = 4;

HeapPriorityQueue::HeapPriorityQueue() {
	usedCap = 0;
	capacity = kDefaultSize;

	elems = new string[capacity];
	
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete [] elems;

}

int HeapPriorityQueue::size() {
	return usedCap;
}

bool HeapPriorityQueue::isEmpty() {
	
	return usedCap == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	if(usedCap == capacity){
		grow();
	}
	elems[usedCap] = value;
	usedCap++;

	bubbleUp(value);
	

}

string HeapPriorityQueue::peek() {
	if (isEmpty()) {
		error("Can't peek into emty pqueue");
	}


	return elems[0];
}

string HeapPriorityQueue::dequeueMin() {
	string stringToDeq = peek();

	//replace first and last
	string temp = elems[usedCap-1]; /////////////////////////
	elems[usedCap-1] = stringToDeq;
	elems[0] = temp;

	usedCap--;
	
	bubbleDown();

	return stringToDeq;
}


void HeapPriorityQueue::grow() {
	capacity *=2;
	string *tmp = new string[capacity];
	for (int i=0; i < usedCap; i++) { // -1 ?   /////used or  max length???
		 tmp[i] = elems[i];
	} 

	delete [] elems;
	elems = tmp;
}


void HeapPriorityQueue::bubbleUp(string value) {
	

	int curIndex = usedCap - 1;

	while(!(curIndex == 0 || elems[(curIndex+1)/2-1] <= value )){
		int potentialIndex = (curIndex+1)/2-1;
		
		elems[curIndex] = elems[potentialIndex];

		
		elems[potentialIndex] = value;
		
		curIndex =potentialIndex;
	}





}

void HeapPriorityQueue::bubbleDown() {
	int curIndex = 0;


	while(true){
		int minIndex = findMinIndex(curIndex);

		if(minIndex == 0 || elems[minIndex] > elems[curIndex]){
			break;
		}


		string temp = elems[curIndex]; 
		elems[curIndex] = elems[minIndex];
		elems[minIndex] = temp;

		curIndex = minIndex;
		
	}
	

	
}

int HeapPriorityQueue::findMinIndex(int curIndex) {
	int childsIndex1 = curIndex * 2 + 1;
	int childsIndex2 = curIndex * 2 + 2;

	if(childsIndex1 >= usedCap){
		return 0;////////////////////////
	}

	int minIndex = childsIndex1;

	if(childsIndex2 >= usedCap){
		
	}else{
		if(elems[childsIndex2] < elems[childsIndex1]){
			minIndex = childsIndex2;
		}	
	}



	return 	minIndex;
}