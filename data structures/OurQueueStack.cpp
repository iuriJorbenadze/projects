#include "OurQueueStack.h"

//class OurQueue {
//public:
//	void enqueue(int value);
//	int dequeue();
//	int peek();
//	
//	bool isEmpty();
//	int size();
//
//private:
//		OurStack in, out;
//};

bool OurQueueStack::isEmpty() {
	return in.isEmpty() && out.isEmpty();
}

int OurQueueStack::size() {
	return in.size() + out.size();
}

void OurQueueStack::enqueue(int value) {
	in.push(value);

}

int OurQueueStack::peek() {
	if(out.isEmpty()){
		while(!in.isEmpty()){
			out.push(in.pop());			
		}
	}
	return out.peek();
}

int OurQueueStack::dequeue() {
	int res = peek();
	out.pop();
	return res;
}
