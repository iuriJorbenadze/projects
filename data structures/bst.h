#pragma once
#include "vector.h"


class bst{
public:
	struct Node{
		int val;
		Node* left;
		Node* right;
	};
	Node* root;
	void deleteSubtree(Node* subtree);
	Node*& findValue(Node*& subtree, int val);
	void printSubtree(Node* subtree);

	Node* mirrorSubtree(Node* subtree);
	int depthOfSubtree(Node* subtree);
	void printCurrentLevel(Vector<int>& vec, int level, Node* subtree);

	//int countNodesInLevel(Node* subtree, Vector<int>& res);
	
	void storeNodes(Node* subtree, Vector<Node*>& nodes);
	Node* buildTree(Vector<Node*>& nodes, int start, int end);


	bst();
	~bst();
	bool contains(int val);
	void insert(int val);
	void printTree();
	Node* mirrorTree();
	int depth();
	Vector<int> printLevels();

	//Vector<int> printLevels2();

	Node* balanceTree();
	
	

};
