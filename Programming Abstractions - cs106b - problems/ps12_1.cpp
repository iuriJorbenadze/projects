#include <iostream>
#include "ps12_1.h"

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

////void prob12();
//////int maxValueFromItems(Vector<itemT>& items, int maxWeight, Vector<itemT>& selectedItems) ;
////int minValueTravel(Grid<int>& costs, Vector<int>& cities, Set<int>& visited) ;
////
////struct itemT{
////	int weigth;
////	int value;
////
////};
////
////
//////
//////int maxValueFromItems(Vector<itemT>& items, int maxWeight, Vector<itemT>& selectedItems) {//////    //////	if(items.isEmpty()){//////		return 0;//////	}////////////	itemT temp = items.get(items.size()-1);//////	//////	int without = maxValueFromItems(items.remove(items.size()-1),maxWeight,selectedItems);//////	temp.add(temp);////////////   //////	int with = maxValueFromItems(items,maxWeight,selectedItems);//////
//////	if(without < with){
//////		selectedItems.add(temp);
//////		
//////	}else{
//////		
//////	}
//////}
////
////int minValueTravel(Grid<int>& costs, Vector<int>& cities, Set<int>& visited) {////    ////	for(int i=0; i < cities.size();i++){////		int curCity = cities[i];////		cities.remove(i);////		////////////		 ////		////	}////////////    return 0;////}
////
//
//struct itemT {
//	int weight;
//	int value;
//}; 
//
//
//int maxValueFromItems(Vector<itemT>& items, int maxWeight, Vector<itemT>& selectedItems) {
//	if(items.isEmpty()){
//		selectedItems.clear();
//		return 0;
//	}
//	itemT curItem = items[items.size()-1];
//	items.remove(items.size()-1);
//
//	Vector<itemT> without;
//	int maxValWithout = maxValueFromItems(items, maxWeight, without);
//
//	Vector<itemT> with;
//	int maxValWith = maxValueFromItems(items, maxWeight - curItem.weight, with);
//
//	maxValWith += curItem.value;
//	selectedItems.add(curItem);
//
//	items.add(curItem);
//
//	if(maxWeight < curItem.weight || maxValWithout > maxValWith  ){
//		selectedItems = without;
//		return maxValWithout;
//	}else{
//		selectedItems = with;
//		return maxValWith;
//	}
//
//
//
//	
//}

int minValueTravel(Grid<int>& costs, Vector<int>& cities, Set<int>& visited) {
	if(cities.size() == costs.nCols){
		int cost = 0;
		for(int i = 0; i < cities.size()-1;i++){
			cost += costs[cities[i]][cities[i+1]];
		}
		cost += costs[cities[cities.size()-1]][cities[0]];

		return cost;
	}

	int minCost = INT_MAX;
	for(int i = 0; i < costs.nCols; i++){
		if(! visited.contains(i)){
			visited.add(i);
			cities.add(i);
			int curCost = minValueTravel(costs, cities, visited);
			
			if(curCost<minCost){
				minCost = curCost;
			}

			cities.remove(cities.size()-1);
			visited.remove(i);

		}
	}
	return minCost;
	

}


void ps12(){
	 cout<<"hi"<<endl;
	
}