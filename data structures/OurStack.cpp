#include "OurStack.h"
#include "error.h"

/* Constant controlling the default size of our stack. */
const int kDefaultSize = 4;

/* Constructor initializes the fields of the stack to
 * appropriate defaults.
 */
OurStack::OurStack() {
	logicalLength = 0;
	allocatedLength = kDefaultSize;
	elems = new int[allocatedLength];
}

/* Destructor cleans up memory allocated by the stack. */
OurStack::~OurStack() {
	delete[] elems;
}

int OurStack::size() {
	return logicalLength;
}

bool OurStack::isEmpty() {
	return size() == 0;
}

void OurStack::grow() {
	allocatedLength *= 2;
	int* newArray = new int[allocatedLength];
	for (int i = 0; i < logicalLength; i++) {
		newArray[i] = elems[i];
	}
	delete[] elems;
	elems = newArray;
}
void OurStack::push(int value) {
	if (allocatedLength == logicalLength) {
		grow();
	}
	elems[logicalLength] = value;
	logicalLength++;
}

int OurStack::peek() {
	if (isEmpty()) {
		error("What is the sound of one hand clapping?");
	}

	return elems[logicalLength - 1];
}

int OurStack::pop() {
	/* This line both does bounds checking and obtains the
	 * return value.
	 */
	int result = peek();
	
	logicalLength--;
	return result;
}






//#include "OurStack.h"
//#include "error.h"
//
///* Constant controlling the default size of our stack. */
//const int kDefaultSize = 4;
//
///* Constructor initializes the fields of the stack to
// * appropriate defaults.
// */
//OurStack::OurStack() {
//	logicalLength = 0;
//	allocatedLength = kDefaultSize;
//	elems = new int[allocatedLength];
//
//}
//
///* Destructor cleans up memory allocated by the stack. */
//OurStack::~OurStack() {
//	delete [] elems;
//}
//
//int OurStack::size() {
//	return logicalLength;
//}
//
//bool OurStack::isEmpty() {
//	return logicalLength == 0; 
//}
//
//void OurStack::grow() {
//	allocatedLength = allocatedLength * 2;
//	int * newArr = new int[allocatedLength];
//	for(int i = 0; i < logicalLength; i++){
//		newArr[i] = elems[i];
//	}
//	delete [] elems;
//	elems = newArr;
//
//}
//void OurStack::push(int value) {
//	if(logicalLength = allocatedLength){
//		grow();
//	}
//	elems[logicalLength] = value;
//
//	logicalLength++;
//}
//
//int OurStack::peek() {
//	if(isEmpty()){
//		error("peeking from an emprt stack");	
//	}
//	return elems[logicalLength - 1];
//}
//
//int OurStack::pop() {
//	/* This line both does bounds checking and obtains the
//	 * return value.
//	 */
//	int res = peek();
//
//	logicalLength--;
//
//	return res;
//}
//
//
//
