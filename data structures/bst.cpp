#include <cstdlib>
#include "bst.h"
#include <iostream>
#include <string>
#include <fstream>
#include "vector.h"
#include "simpio.h"
#include "console.h"

//class bst{
//private:
//	struct Node{
//		int val;
//		Node* left;
//		Node* right;
//	};
//	Node* root;
//	void deleteSubtree(Node* subtree);
//	Node*& findValue(Node*& subtree, int val);
//
//public:
//	bst();
//	~bst();
//	bool contains(int val);
//	void insert(int val);
//};


bst::bst(){
	root = NULL;
}

void bst::deleteSubtree(Node* subtree){
	if(subtree == NULL) return;

	deleteSubtree(subtree->left);
	deleteSubtree(subtree->right);
	delete subtree;
}

bst::~bst(){
	deleteSubtree(root);
}

bst::Node*& bst::findValue(Node*& subtree, int val){
	if(subtree == NULL || subtree->val == val){
		return subtree;
	}
	if(val < subtree->val){
		return findValue(subtree->left, val);
	}else{
		return findValue(subtree->right, val);
	}

}

bool bst::contains(int val){
	return findValue(root, val) != NULL;
}	

void bst::insert(int val){
	Node*& node = findValue(root, val);
	if(node == NULL){
		node = new Node;
		node->val = val;
		node->left = NULL;
		node->right = NULL;
	}

}

void bst::printSubtree(Node* subtree){
	if(subtree == NULL){
		return;
	}
	printSubtree(subtree->left);
	cout<<subtree->val<<endl;
	printSubtree(subtree->right);
}

void bst::printTree(){
	printSubtree(root);

}



bst:: Node* bst::mirrorSubtree(Node* subtree){
	if(subtree == NULL) return NULL;

	//if(subtree->left == NULL || subtree->right == NULL){
	//	Node* temp = subtree->left;
	//	subtree->left = subtree->right;
	//	subtree->right = temp;
	//	return subtree;
	//} wrong

	Node* temp = mirrorSubtree(subtree->left); //null
	subtree->left = mirrorSubtree(subtree->right); //  
	subtree->right = temp;
	
	return subtree;

	//subtree->left = mirrorSubtree(subtree->left);
	//subtree->right = mirrorSubtree(subtree->right);

}

//mirrors tree, old tree is replaced with new mirrored one
bst::Node* bst::mirrorTree(){
	return mirrorSubtree(root);
}

int bst::depthOfSubtree(Node* subtree){
	if(subtree==NULL) return 0;
	
	int leftDepth = depthOfSubtree(subtree->left);
	int rightDepth = depthOfSubtree(subtree->right);
	
	return 1 + max(leftDepth, rightDepth);

}

int bst::depth(){
	return depthOfSubtree(root);
}


void bst::printCurrentLevel(Vector<int>& vec, int level, Node* subtree){
	if(subtree != NULL){
		//if vec does not have that level (dont need this cause i know depth)
		vec[level]++;
		printCurrentLevel(vec, level+1, subtree->left);
		printCurrentLevel(vec, level+1, subtree->right);
	}
	return;

}

Vector<int> bst::printLevels(){
	Vector<int> res;
	for(int i=0; i< depth();i++){
		res.add(0);
	}

	printCurrentLevel(res, 0, root);
	return res;
}

//int bst::countNodesInLevel(Node* subtree, Vector<int>& res){
//	if(subtree == NULL) return 0;
//	
//	countNodesInLevel(subtree->left,res);
//	 
//
//
//}
//
//Vector<int> bst::printLevels2(){
//	Vector<int> res;
//	countNodesInLevel(root,res);
//	return res;
//
//}

bst::Node* bst::buildTree(Vector<Node*>& nodes, int start, int end){
	if(start > end){
		return NULL;
	}

	int mid = (start + end)/2;
	
	Node* midNode = nodes[mid];


	midNode->left = buildTree(nodes, start, mid - 1); //// aq startis magivrad 0 mewera da 2 saatia debugings vuketeb amis ddshvc
	midNode->right = buildTree(nodes, mid + 1, end);  //here instead of start I've had written 0 and I was debbuging for 2 hours,  


	return midNode;
}

void bst::storeNodes(Node* subtree, Vector<Node*>& nodes){
	if(subtree==NULL){
		return;	
	}

	storeNodes(subtree->left, nodes);
	nodes.add(subtree);
	storeNodes(subtree->right,nodes);

}

bst::Node* bst::balanceTree(){
	Vector<Node*> nodes;
	storeNodes(root, nodes);
		
	
	Node* res= buildTree(nodes, 0, nodes.size()-1);
	
	

	return res;
}