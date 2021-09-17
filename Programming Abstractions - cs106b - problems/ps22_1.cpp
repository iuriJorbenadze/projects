#include <iostream>
#include "ps22_1.h"

#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>
#include "vector.h"
#include "stack.h"
#include "strlib.h"
#include "set.h"
#include "map.h"
#include "random.h"
#include "grid.h"
#include "foreach.h"

using namespace std;

struct Node{
	int val;
	Node* next;
};


Node* reverseLLRec(Node*& list, Node*& tail){
	if(list==NULL) return NULL;

	if(list->next == NULL){
		tail = list;
		return tail;
	}
	reverseLLRec(list->next, tail)->next = list;
	return list;
}


Node* reversedLL(Node*& list){
	Node* reversed;
	reverseLLRec(list, reversed) ->next = NULL;
	return reversed;
}

Node* merge (Node*& list1, Node*& list2){
	if(list1 == NULL) return list2;
	if(list2 == NULL) return list1;

	Node* minNode;
	if(list1->val <= list2->val){
		minNode = list1;
		minNode->next = merge(list1->next, list2);
	}else{
		minNode = list2;
		minNode->next = merge(list1, list2->next);
	}
	return minNode;
}

//Node* merge (Node*& list1, Node*& list2){
//	if(list1 == NULL) return list2;
//	if(list2 == NULL) return list1;
//
//	Node* minNode;
//	
//	if(list1->val <= list2->val){
//		minNode = list1;
//		minNode->next = merge(list1->next, list2);
//	}else{
//		minNode = list2;
//		minNode->next = merge(list1, list2->next);
//	}
//
//	//while(list1 != NULL && list2 != NULL){
//	//	if(list1->val < list2->val){
//	//		minNode = list1;
//	//		list1 = list1->next;
//	//	}else{
//	//		minNode = list2;
//	//		list2 = list2->next;
//	//	}
//	//}
//
//	return minNode;
//}

void splitList(Node*& list, Node*& list2, int size){
	Node* midPtr = list;
	while(size > 1){
		size--;
		midPtr = midPtr->next;
	}
	//by this moment midPtr is standing on end of first half
	list2 = midPtr->next;
	midPtr->next = NULL;

}




void sortListOfSize(Node*& list, int size){
	//if(list->next == NULL) return;

	if(list == NULL) return;
	if(list->next == NULL) return;
	if(size == 0) return;

	Node* list2;
	splitList(list, list2, size/2);

	sortListOfSize(list, size/2);
	sortListOfSize(list2, size/2);
	
	//merge
	list = merge(list, list2);

}

int getSize(Node* list){
	int size = 0;
	while(list != NULL){
		size++;
		list = list->next;
	}
	return size;

}

void sortList(Node*& list) {
	sortListOfSize(list, getSize(list));
}











//
//Node* merge(Node*& list1, Node*& list2){
//	if(list1 == NULL) return list2;
//	if(list2 == NULL) return list1;
//
//	Node* minNode;
//	if(list1->val <= list2->val){
//		minNode = list1;
//		minNode->next = merge(list1->next, list2);
//	}else{
//		minNode = list2;
//		minNode->next = merge(list1, list2->next);
//	}
//	return minNode;
//
//}
//
//void splitList(Node*& list, Node*& list2, int size){
//	Node* midPtr = list;
//	while(size > 1){
//		size--;
//		midPtr= midPtr->next;
//	}
//	list2 = midPtr->next;
//	midPtr->next=NULL;
//
//}
//
//void sortListOfSize(Node*& list, int size){
//	if(list->next == NULL) return;
//
//	Node* list2;
//	splitList(list, list2, size/2);
//
//	sortListOfSize(list,size/2);
//	sortListOfSize(list2,size/2);
//
//	list = merge(list, list2);
//}
//
//int getSize(Node* list){
//	int res =0;
//	while(list != NULL){
//		res++;
//		list=list->next;
//	}
//	return res;
//}
//
//void sortList(Node*& list) {
//	if(list==NULL) return; 
//	int size = getSize(list);
//	sortListOfSize(list, size);
//}
//
/////////////////////////////////////////////////////////////////////////
//
//Node* reverseLLRec(Node*& list, Node*& tail){
//	//if(list==NULL) return NULL;
//	if(list->next == NULL){
//		tail = list;
//		return tail;
//		//return list;
//	}
//	Node* lastNode = reverseLLRec(list->next, tail);
//
//
//	lastNode->next = list;
//	return list;
//}
//
//
//Node* reversedLL(Node*& list){
//	Node* reversed;
//	reverseLLRec(list, reversed) ->next = NULL;
//	return reversed;
//}



void ps22(){
	Node* n1 = new Node;
	Node* n2 = new Node;
	Node* n3 = new Node;
	Node* n4 = new Node;
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;

	/*n1->next = n3;
	n3->next = n4;
	n4->next = n2;
	n2->next = NULL;*/
	
	n1->next = n3;
	n3->next = n2;
	n2->next = n4;
	n4->next = NULL;

	sortList(n1);
	cout<<n1->val<<n1->next->val<<n1->next->next->val<<n1->next->next->next->val<<endl;

	Node* reversed;
	//reverseLLRec(n1, reversed) ->next = NULL;
	reversed = reversedLL(n1);
	

	cout<<reversed->val<<endl;
	cout<<reversed->next->val<<endl;
	cout<<reversed->next->next->val<<endl;
	cout<<reversed->next->next->next->val<<endl;
	if(reversed->next->next->next->next == NULL){
		cout<<"end is null"<<endl;	
	}
}

// 1->2->3->4->5->6