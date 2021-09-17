#pragma once


#include <string>
using namespace std;

class LLstring{
private: 
	struct Node{
		char val;
		Node* next;

	};
	Node* head;
	Node* fullCopy(Node* src, Node* tail);

	Node* constructLLfromString(string str);
	Node* constructLLfromLL(Node* node);
	string toStringInternal(Node* node);
public:
	LLstring(string other ="");
	LLstring(const LLstring& other);
	~LLstring();
	string toString();
	LLstring operator+ (LLstring& other);

};
