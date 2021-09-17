/*******************************************
 * File: linked-lists.cpp
 *
 * A program that shows off a simple use of
 * linked lists.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
using namespace std;

/* Type: Cell
 * A cell in a linked list.
 */
struct Cell {
	string value;
	Cell* next;
};

Cell* readList();
void printList(Cell* list);
void deleteList(Cell* list);

int main9090() {///////////////////
	Cell* list = readList();
	printList(list);
	deleteList(list);

	return 0;
}

Cell* readList() {
	Cell* result = NULL;
	while(true){
		string line = getLine();
		if(line == ""){
			break;
		}
		Cell* newCell = new Cell;
		newCell->value = line;

		newCell->next = result;
		result = newCell;
	}
	return result;

}

void printList(Cell* list) {
	while(list != NULL){
		cout<<list->value<<endl;
		list = list->next;
	}

}

void deleteList(Cell* list) {
	while(list != NULL){
		Cell* temp = list;
		list = list->next;
		delete temp;
	}
}




