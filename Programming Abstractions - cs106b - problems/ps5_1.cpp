#include <iostream>
#include "ps5_1.h"

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

//void placeRandBombs(Grid<bool>& bombs, double p);
void printGrid(Grid<bool>& bombs);
void printGridInt(Grid<int>& hints);

void placeNBombs(Grid<bool>& bombs, int n);
void calculateHints(Grid<bool>& bombs,Grid<int>& hints);
void placeHints(Grid<int>& hints, int i, int j);

void countBombs(Grid<bool>& bombs,Grid<int>& countedBombs);
void countBombsInRect(Grid<bool>& bombs, Grid<int>& countedBombs, int i, int j);

int countBombsInChosenRect(Grid<bool>& bombs,int y1, int x1,int y2,int x2);

void ps5(){
	Grid<bool> bombs(5,5);
	
	//double p = getReal("Enter probability: ");
	//placeRandBombs(bombs,p);

	int n = getInteger("Enter num of boms: ");
	placeNBombs(bombs, n);

	printGrid(bombs);

	Grid<int> hints(5,5);

	calculateHints(bombs,hints);
	printGridInt(hints);
	
	Grid<int> countedBombs(5,5);
	countBombs(bombs, countedBombs);
	printGridInt(countedBombs);

	int y1 = getInteger();
	int x1= getInteger();
	int y2= getInteger();
	int x2= getInteger();

	
	int bombsAtCords = countBombsInChosenRect(bombs,y1,x1,y2,x2);
	cout<<bombsAtCords<<endl;

}
//problem 1 a)
//void placeRandBombs(Grid<bool>& bombs, double p){
//	for(int i=0; i< bombs.numRows(); i++){
//		for(int j=0; j< bombs.numCols(); j++){
//			bombs[i][j] = randomChance(p);
//		}
//	}
//	
//
//}
void printGrid(Grid<bool>& bombs){
	for(int i=0; i< bombs.numRows(); i++){
		for(int j=0; j< bombs.numCols(); j++){
			cout << bombs[i][j] <<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void printGridInt(Grid<int>& hints){
	for(int i=0; i< hints.numRows(); i++){
		for(int j=0; j< hints.numCols(); j++){
			cout << hints[i][j] <<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void placeNBombs(Grid<bool>& bombs, int n){
	while(n > 0){
		int i = randomInteger(0,bombs.numRows()-1);
		int j = randomInteger(0,bombs.numCols()-1);

		if(!bombs[i][j]){
			n--;
			bombs[i][j]=true;
		}
	}

}

void calculateHints(Grid<bool>& bombs,Grid<int>& hints){
	for(int i=0; i< bombs.numRows(); i++){
		for(int j=0; j< bombs.numCols(); j++){
			if(bombs[i][j]){
				hints[i][j]=-1;
				placeHints(hints, i, j);
			}
		}
		
	}
	
}
void placeHints(Grid<int>& hints, int i, int j){
	for(int k=-1; k<=1;k++){
		for(int f=-1; f<=1;f++){
			if(hints.inBounds(i+k,j+f) && hints[i+k][j+f] != -1 ){
				hints[i+k][j+f]++;
			}
		}
	}

}


//problem 3
void countBombs(Grid<bool>& bombs,Grid<int>& countedBombs){
	for(int i=0;i<bombs.numRows();i++){
		for(int j=0;j<bombs.numCols();j++){
			countBombsInRect(bombs,countedBombs, i, j);
		
		}

	}
	
	

}
void countBombsInRect(Grid<bool>& bombs, Grid<int>& countedBombs, int i, int j){
	if(i==0 && j==0){
		countedBombs[i][j]=bombs[i][j];
	}else if(i==0){
		 countedBombs[i][j]=countedBombs[i][j-1] + bombs[i][j];
	}else if(j==0){
		 countedBombs[i][j]=countedBombs[i-1][j] + bombs[i][j];
	}else {
		 countedBombs[i][j]=countedBombs[i][j-1]+countedBombs[i-1][j] - countedBombs[i-1][j-1] + bombs[i][j];
	}	

}


int countBombsInChosenRect(Grid<bool>& bombs,int y1, int x1,int y2,int x2){
	int result=0;

	for(int i=y1;i<=y2;i++){
		for(int j=x1;j<=x2;j++){
			if(bombs.inBounds(i,j) && bombs[i][j]){
				result++;
			}
		}
	}

	return result;
}