/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	// TODO: Fill this in!
	


}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
	

}

int VectorPriorityQueue::size() {
	// TODO: Fill this in!
	
	return data.size();
}

bool VectorPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	
	return data.size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	data.add(value);
	//data.insert(0, value);
	
	

}

string VectorPriorityQueue::peek() {
	// TODO: Fill this in!
	if(isEmpty()){
		error("Can't peek into empty pqueue.");
	}	

	string minStr = data[0];
	for(int i = 1; i < data.size(); i++){
		if(data[i] < minStr){
			minStr = data[i];
		}	
	}
	
	return minStr;
}

string VectorPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	string minStr = peek();
	
	for(int i = 0; i < data.size(); i++){
		if(minStr == data[i]){
			data.remove(i);
			break;
		}
	}

	

	return minStr;
}



