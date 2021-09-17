/****************************************************
 * File: OurHashMap.h
 *
 * A HashMap class that implements a map from strings
 * to integers.
 */
#ifndef OurHashMap_Included
#define OurHashMap_Included

#include <string>
using namespace std;

class OurHashMap {
public:
	OurHashMap();
	~OurHashMap();
	
	void put(string key, int value);
	bool containsKey(string key);
	int get(string key);
	
	int size();
	bool isEmpty();

	//removes key-value from map
	void remove(string key);

private:
	struct Cell {
		string key;
		int value;
		Cell *next;
	};
	Cell **buckets;
	int numBuckets;
	int numElems;

	Cell *findCell(string key);

	/////////
	void increaseBuckets();
};


#endif
