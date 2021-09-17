#pragma once

template <typename T>
class deque{
private:
	struct Node{
		T value;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;

public:
	
	deque();
	~deque();
	bool isEmpty();
	void pushFront(T value);
	void pushBack(T value);
	T popFront();
	T popBack();
};
