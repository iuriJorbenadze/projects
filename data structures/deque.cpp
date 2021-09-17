#include "deque.h"
#include "error.h"

template <typename T>
deque<T>::deque(){
	head = new Node;
	tail = new Node;
	head->prev = NULL;
	head->next = tail;
	tail->next = NULL;
	tail->prev = head;
}

template <typename T>
deque<T>::~deque(){
	while(head != NULL){
		Node* temp  = head->next;
		delete head;
		head = temp;
	}

}
template <typename T>
bool deque<T>::isEmpty(){
	return head->next == tail;
}

template <typename T>
void deque<T> :: pushFront(T value){
	Node* newNode = new Node;
	newNode->value = value;

	newNode->next = head->next;
	newNode->prev = head;
	head->next->prev = newNode;
	head->next = newNode;
}

template <typename T>
void deque<T> :: pushBack(T value){
	Node* newNode = new Node;
	newNode->value = value;

	newNode->next = tail;
	newNode->prev = tail->prev;
	tail->prev->next = newNode;
	tail->prev = newNode;
}

template <typename T>
T deque<T>::popFront(){
	if(isEmpty()){
		error("no elems");
	}

	Node* res = head->next;
	res->next->prev = head;
	head->next = res->next;
	T val = res->value;

	delete res;
	return val;
}

template <typename T>
T deque<T>::popBack(){
	if(isEmpty()){
		error("no elems");
	}
	Node* res = tail->prev;

	res->prev->next = tail;
	tail->prev = res->prev;
	T val = res->value;
	delete res;

	return val;
}
template class deque<int>;
template class deque<double>;