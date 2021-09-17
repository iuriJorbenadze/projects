#include <iostream>
#include "ps10_1.h"

#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>
#include "vector.h"
#include "strlib.h"
#include "set.h"
#include "map.h"
#include "random.h"
#include "grid.h"

using namespace std;

bool isConectedToOthers(Grid<bool>& graph, Vector<int> indices, int removedInd){
	foreach(int i in indices){
		if(!graph[i][removedInd]){
			return false;
		}
	}
	return true;
}

bool isClique(Grid<bool>& graph, Vector<int> indices) {
	if(indices.size() <= 1){
		return true;
	}
	int removedInd = indices[indices.size()-1];
	indices.remove(indices.size()-1);
	
	return isConectedToOthers(graph, indices, removedInd) && isClique(graph, indices);

}

int maxSizeCliqueWithSubset(Grid<bool>& graph, Vector<int>& chosenSet, int firstFreeIndex){
	if(firstFreeIndex == graph.nCols){
		if(isClique(graph, chosenSet)){
			return chosenSet.size();
		}else {
			return -1;
		}
	}
	
	int maxSizeWithout = maxSizeCliqueWithSubset(graph, chosenSet, firstFreeIndex + 1);

	chosenSet.add(firstFreeIndex);
	int maxSizeWith = maxSizeCliqueWithSubset(graph, chosenSet, firstFreeIndex + 1);
	chosenSet.remove(chosenSet.size() - 1);

	return max(maxSizeWithout, maxSizeWith);
}


int maxSizeClique(Grid<bool>& graph) {
	Vector<int> emptySet;
	return maxSizeCliqueWithSubset(graph, emptySet, 0 );
	
}

void ps10(){
	
}