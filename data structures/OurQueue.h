/*********************************************************
 * File: OurQueue.h
 *
 * A class representing a Queue that holds integers.
 */
#pragma onceclass OurQueue {public:	OurQueue();	~OurQueue();	int size();	bool isEmpty();	void enqueue(int value);	int front();	int dequeue();private:	struct Cell {		int value;		Cell* next;	};	Cell* head;	int logLen;};

