/*********************************************************
 * File: OurQueue.h
 *
 * A class representing a Queue that holds integers.
 */
#ifndef OurQueue_Included
#define OurQueue_Included

#include "OurStack.h"

class OurQueueStack {
public:
	void enqueue(int value);
	int dequeue();
	int peek();
	
	bool isEmpty();
	int size();

private:
		OurStack in, out;
};


#endif
