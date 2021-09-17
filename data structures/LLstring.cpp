#include "LLstring.h"
#include "string.h"
#include "console.h"
//class LLstring{
//private: 
//	struct Node{
//		char val;
//		Node* next;
//
//	};
//	Node* head;
//	Node* fullCopy(Node* src, Node* tail);
//
//public:
//	LLstring(string other ="");
//	LLstring(const LLstring& other);
//	~LLstring();
//	string toString();
//	LLstring operator+ (LLstring& other);
//
//};

LLstring::Node* LLstring :: constructLLfromString(string other){
	if(other.length()==0){
		return NULL;
	}

	Node* cur = new Node;
	cur->val=other[0];
	cur->next = constructLLfromString(other.substr(1));
	return cur;
}

LLstring::LLstring(string other){
	head = constructLLfromString(other);  //////////////////////// ar vimaxsovrebdiiiiiiiii headshi
}
LLstring::Node* LLstring::constructLLfromLL(Node* node){
	if(node ==NULL){
		return NULL;
	}

	Node* newNode = new Node;
	newNode->val = node->val;
	newNode->next = constructLLfromLL(node->next);

	return newNode;
}

LLstring::LLstring(const LLstring& other){
	head = constructLLfromLL(other.head);
}

string LLstring::toStringInternal(Node* node){
	if(!node){
		return "";	
	}
	/*string res;
	res+=node->val;*/

	string res(1, node->val);
	//string res;
	//res = string() + node->val;

	res.append(toStringInternal(node->next));
	return res;

}

string LLstring::toString(){
	return toStringInternal(head);
}

LLstring LLstring::operator + (LLstring& other){
	string s1 = toString();
	string s2 = other.toString();
	string res = s1+ s2;
	return LLstring(res);
}

LLstring::~LLstring(){
	while(head != NULL){
		Node* temp = head;
		head = head->next;
		delete temp;
	}

}
