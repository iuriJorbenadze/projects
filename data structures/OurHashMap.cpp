#include "OurHashMap.h"
#include "error.h"
#include <iostream>
using namespace std;

/* * * * * Helper Functions * * * * */

/* 
 * Function hashCode
 * Usage: int code = hashCode(key)
 * ---------------------------------------------------------
 * An hash function for strings. Adapted from code online at
 * http://www.daniweb.com/software-development/cpp/threads/231987/string-hash-function
 * This function is called a SAX hash function (Shift-Add-XOR) and is
 * great at distributing strings evenly.
 */

//class OurHashMap {
//public:
//	OurHashMap();
//	~OurHashMap();
//	
//	void put(string key, int value);
//	bool containsKey(string key);
//	int get(string key);
//	
//	int size();
//	bool isEmpty();
//
//private:
//	struct Cell {
//		string key;
//		int value;
//		Cell *next;
//	};
//	Cell **buckets;
//	int numBuckets;
//	int numElems;
//
//	Cell *findCell(string key);
//};

const int kHashMask = 0x7FFFFFFF;
int hashCode(string key) {
    int hashVal = 0;
    for (int x = 0; x < key.length(); ++x) {
        hashVal ^= (hashVal << 5) +
                   (hashVal >> 2) +
                   key[x];
    }
    return hashVal & kHashMask;
}

/* * * * * Implementation of OurHashMap. * * * * */

const int kNumBuckets = 7;

OurHashMap::OurHashMap() {
	numBuckets = kNumBuckets;
	numElems = 0;
	buckets = new Cell* [numBuckets];
	for(int i = 0; i < numBuckets; i++){
		buckets[i] = NULL;
	}

}

OurHashMap::~OurHashMap() {
	for(int i = 0; i < numBuckets; i++){
		Cell* curHead = buckets[i];
		while(curHead != NULL){
			Cell* temp = curHead;
			curHead = curHead->next;
			delete temp;
		}
	}
	delete [] buckets;

}


OurHashMap::Cell * OurHashMap::findCell(string key) {
	int index = hashCode(key) % numBuckets;
	Cell* head = buckets[index];
	while(head != NULL){
		if(head->key == key){
			return head;
		}
		head = head->next;
	}
	return NULL;  ///return head_ic imushavebda wesit imitom rom bolos nullamd mividodi
	
}

int OurHashMap::get(string key) {
	Cell* curCell = findCell(key);
	if(curCell == NULL) error("Key is not in map");
	return curCell->value;
}

bool OurHashMap::containsKey(string key) {
	return findCell(key) != NULL;
}

void OurHashMap::put(string key, int value) {	

	////////////////////////////////////////////////////////////// 
	if(numElems/numBuckets > 2){
		cout<<"increased buckets"<<endl;
		increaseBuckets();
	}
	

	if(containsKey(key)){
		Cell* cur = findCell(key);
		cur->value = value;
	}else{
		int index = hashCode(key) % numBuckets;
		//Cell* head = buckets[index];         ////// aq mgoni copy reba xdeba amitom me

		cout<<index<<" "<<key<<endl;

		Cell* newCell = new Cell;
		newCell->key = key;
		newCell->value = value;

		newCell->next = buckets[index];
		buckets[index] = newCell;             /// ai aq unda shevinaxo masivshi es axali elementi, misamartit rogor unda arvici

		numElems++;
	}

	

}

int OurHashMap::size() {
	return numElems;
}

bool OurHashMap::isEmpty() {
	return numElems == 0;
}


void OurHashMap::increaseBuckets() {
	int newNum = numBuckets * 2;
	Cell** newArr = new Cell* [newNum];
	for(int i = 0; i < newNum; i++){
		newArr[i] = NULL;
	}

	for(int i = 0; i < numBuckets; i++){
		Cell* head = buckets[i];

		while(head != NULL){
			int index = hashCode(head->key) % newNum;
			
			Cell* temp = head->next;

			head->next = newArr[index];
			newArr[index] = head;

			head = temp;

		}

	}
	delete [] buckets;
	buckets = newArr;
	numBuckets = newNum;
		
}

void OurHashMap :: remove(string key){
	if(!containsKey(key)){
		error("there is no such key in map");
	}
	int index = hashCode(key) % numBuckets;
	Cell* head = buckets[index];
	
	if(head->key == key){
		buckets[index] = head->next;
		delete head;
	}else{//we will stop on cell which is previous to our key cell
		while(head->next->key != key){
			head = head->next;
		}
		Cell* cellToDelete = head->next;
		head->next = cellToDelete->next;  // or findCell(key)->next
		delete cellToDelete;
	}

	
}