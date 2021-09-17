/*********************************************************
 * File: OurQueue.hh
 *
 * A class representing a queue that holds integers.
 */

#pragma once

class OurQueueTail {
public:
	OurQueueTail();
	~OurQueueTail();

	int size();
	bool isEmpty();
	
	void enqueue(int value);
	int front();
	int dequeue();

private:
	struct Cell {
		int value;
		Cell* next;
	};
	
	int logLen;
	Cell* head;
	Cell* tail;
};



