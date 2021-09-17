/*********************************************************
 * File: OurStack.h
 *
 * A class representing a stack that holds integers.
 */
#ifndef OurStack_Included
#define OurStack_Included

class OurStack {
public:
	/* Constructor initializes the fields to reasonable values. */
	OurStack();
	
	/* Destructor cleans up all allocated memory. */
	~OurStack();

	void push(int value);
	int pop();
	int peek();
	
	bool isEmpty();
	int size();

private:
	int  allocatedLength; // How much space is allocated in our array.
	int  logicalLength;   // How many elements are logically in the array.
	int* elems;           // The actual array of elements.
	
	void grow();
};


#endif
