#include "OurLexicon.h"
#include "strlib.h"
#include "error.h"
#include <cctype>        // for isalpha
using namespace std;

OurLexicon::OurLexicon() {
	root = NULL;
}

/* Recursively frees all memory used by the trie. */
void OurLexicon::recDeleteTrie(Node* node) {
	if(node == NULL) return;
	for(int i = 0 ; i < 26; i++){
		recDeleteTrie(node->children[i]);
	}
	delete node;

}

OurLexicon::~OurLexicon() {
	recDeleteTrie(root);
}

/* The lexicon is empty if the tree root is NULL. */
bool OurLexicon::isEmpty() {
	return root == NULL;
}

/* Counts how many words are in the trie. */
int OurLexicon::recCountWords(Node* node) {
	if(node == NULL) return 0;
	int res = 0;
	for(int i = 0; i < 26; i++){
		res += recCountWords(node->children[i]);
	}
	if(node->isWord){
		res++;
	}

	return res;
}

int OurLexicon::size() {
	return recCountWords(root);
}


OurLexicon :: Node* OurLexicon :: recFindNode(Node* node, string word){
	if(word == "") return node;
	if(node == NULL) return NULL;
	
	int childIndex = word[0] - 'a';
	return recFindNode(node->children[childIndex], word.substr(1));
}

/* Determines whether a word is valid by seeing if it contains only
 * letters.
 */
void OurLexicon::checkWordIsValid(string word) {
	for (int i = 0; i < word.length(); i++) {
		if (!isalpha(word[i])) {
			error("Letters only, please!");
		}
	}
}


bool OurLexicon :: containsPrefix(string prefix){
	prefix = toLowerCase(prefix);
	checkWordIsValid(prefix);

	Node* node = recFindNode(root, prefix);
	return node != NULL;
}

bool OurLexicon :: containsWord(string word){
	word = toLowerCase(word);
	checkWordIsValid(word);

	Node* node = recFindNode(root, word);
	return node != NULL && node->isWord;
}

void OurLexicon :: recAddWord(Node*& node, string word){
	if(node == NULL) {
		node = new Node;
		node->isWord = false;
		for(int i = 0; i < 26; i++){
			node->children[i] = NULL;
		}
	}

	if(word == ""){
		node->isWord = true;
	}else{
		int childIndex = word[0] - 'a';
		recAddWord(node->children[childIndex], word.substr(1));
	}
}

void OurLexicon :: addWord(string word){
	word = toLowerCase(word);
	checkWordIsValid(word);

	recAddWord(root, word); /////////////// if not contains 
}

void OurLexicon :: recRemoveWord(Node *& node, string word){
	if(node == NULL) return;

	if(word == "") {
		node->isWord = false;
		return;
	}else{
		int childIndex = word[0] - 'a';
		recRemoveWord(node->children[childIndex], word.substr(1));
	}


	
	for(int i = 0; i < 26; i++){
		if(node->children[i] != NULL){
			return;
		}

	}

	if(node->isWord) return;

	delete node;
	node = NULL;
}

void OurLexicon :: removeWord(string word){
	recRemoveWord(root, word);
}



//
//
//
///* Determines whether a word is valid by seeing if it contains only
// * letters.
// */
//void OurLexicon::checkWordIsValid(string word) {
//
//}
//
///* Recursively searches the trie for a node. */
//OurLexicon::Node* OurLexicon::recFindNode(Node* node, string word) {
//	return NULL;
//}
//
///* We contain a prefix if we can find some node for that prefix. */
//bool OurLexicon::containsPrefix(string prefix) {
//	return false;
//}
//
///* We contain a word if the node for that word exists and is marked
// * as a word.
// */
//bool OurLexicon::containsWord(string word) {
//	return false;
//}
//
///* Recursively adds a word into the trie. */
//void OurLexicon::recAddWord(Node*& node, string word) {
//
//}
//
//void OurLexicon::addWord(string word) {
//
//}
//
///* Recursively removes the given word from the trie. */
//void OurLexicon::recRemoveWord(Node*& node, string word) {
//
//}
//
//void OurLexicon::removeWord(string word) {
//
//}
//
//
