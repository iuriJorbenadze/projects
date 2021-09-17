#include <iostream>
#include "ps11_1.h"

#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>
#include "vector.h"
#include "grid.h"
#include "strlib.h"
#include "set.h"
#include "map.h"

using namespace std;


bool hasHamiltonCycleStartingFrom(Grid<bool>& graph, Vector<int>& chosen, Set<int>& chosenSet);
bool hasHamiltonCycle(Grid<bool>& graph, Vector<int>& resultCycle);


bool isHamilton(Grid<bool>& graph, Vector<int> sequence) {
for (int i = 0; i < sequence.size(); i++) {
int v1 = sequence[i];
int v2 = sequence[(i + 1) % sequence.size()];
if (!graph[v1][v2])
return false;
}
return true;
}

//bool isHamilton(Grid<bool>& graph, Vector<int>& chosen){
//	for(int i = 0; i < chosen.size() - 1; i++){
//		if(!graph[chosen[i]][chosen[i+1]]){
//			return false;
//		}
//	}
//	if(!graph[chosen[0]][chosen[chosen.size()-1]]){
//			return false;
//	}
//
//
//	return true;
//
//
//}

bool hasHamiltonCycleStartingFrom(Grid<bool>& graph, Vector<int>& chosen, Set<int>& chosenSet){
	if(chosen.size() == graph.nCols){
		return isHamilton(graph, chosen);
			
	}

	
	for(int i = 0; i < graph.nCols; i++){
		if(!chosenSet.contains(i)){
			chosenSet.add(i);
			chosen.add(i);
			if(hasHamiltonCycleStartingFrom(graph, chosen, chosenSet)){
				return true;
			}
			chosen.remove(chosen.size()-1);
			chosenSet.remove(i);

		}
	}
	return false;

}

bool hasHamiltonCycle(Grid<bool>& graph, Vector<int>& resultCycle) {
	Set<int> empty;
	resultCycle.clear();
	cout<<"moved"<<endl;
	return hasHamiltonCycleStartingFrom(graph, resultCycle, empty);
}


bool isValidColor(Grid<bool>& graph,  Vector<int>& coloringResult, int newColor){
	int newVertex = coloringResult.size();
	for(int i =0; i < newVertex; i++){
		if(graph[i][newVertex]  && coloringResult[i] == newColor){
			return false;
		}
	}
	return true;
}

bool canBeColored(Grid<bool>& graph, int colorCount, Vector<int>& coloringResult) {
	if(coloringResult.size() == graph.nCols){
		return true;
	}

	for(int colorIndex = 0; colorIndex < colorCount; colorIndex++){
		if(isValidColor(graph, coloringResult, colorIndex)){
			coloringResult.add(colorIndex);
			if(canBeColored(graph, colorCount, coloringResult)){
				return true;
			}
			coloringResult.remove(coloringResult.size()-1);

		}

	}
	return false;

}



void ps11(){	cout <<  "ha" << endl;	Grid<bool> graph(5, 5);	for(int i = 0; i < 5; i++) {		graph[i][i] = true;	}    // 0, 2, 4, 1, 3    graph[0][2] = 1;    graph[2][0] = 1;	cout <<  "kkkkkkk" << endl;        graph[2][4] = 1;    graph[4][2] = 1;        graph[4][1] = 1;    graph[1][4] = 1;        graph[1][3] = 1;    graph[3][1] = 1;        graph[3][0] = 1;    graph[0][3] = 1;        Vector<int> resultCycle;		cout<<hasHamiltonCycle(graph, resultCycle)<<endl;	if(hasHamiltonCycle(graph, resultCycle)){		cout <<  "bbbb" << endl;	}else{		cout <<  "vvvv" << endl;	}/*    cout << hasHamiltonCycle(graph, resultCycle) << endl;    cout << resultCycle << endl;*/
   	   cout <<  "aaaaaaaa" << endl;
	
	

	//problem 3 test
	
	//Grid<bool> graph(5, 5); //   for(int i = 0; i < 5; i++) { //       graph[i][i] = true; //   } //   // 0 - 2 - 4 - 1 - 3 - 0 //   graph[0][2] = true; //   graph[2][0] = true; //    //   graph[2][4] = true; //   graph[4][2] = true; //    //   graph[4][1] = true; //   graph[1][4] = true; //    //   graph[1][3] = true; //   graph[3][1] = true; //    //   graph[3][0] = true; //   graph[0][3] = true; //    //   Vector<int> coloringResult; //   cout << canBeColored(graph, 3, coloringResult) << endl; //   cout << coloringResult << endl;


}

