#include <iostream>
#include "ps9_1.h"

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


enum position {
	cross = 1,
	neither = 0,
	nought = -1
};

struct boardT{
	Grid<position> grid;
	position currentPlayer;
};

bool doesPlayerWin(boardT& board, position player){
	for(int i = 0; i < 3; i++){
		bool isRowFull = true;
		bool isColumnFull = true;
		for(int j = 0; j < 3; j++){
			if(board.grid[i][j] != player){
				isRowFull = false;
			}	
			if(board.grid[j][i] != player){
				isColumnFull = false;
			}	
		}

		if(isRowFull || isColumnFull ){
			return true;
		}
	}
	
	if (board.grid[0][0] == player && board.grid[1][1] == player && board.grid[2][2] == player){
		return true;
	}
	
	if (board.grid[0][2] == player && board.grid[1][1] == player && board.grid[2][0] == player){
		return true;
	}

	return false;
	

}

bool isGameOver(boardT& board, position& gameResult) {
	if(doesPlayerWin(board, cross)){
		gameResult = cross;
		return true;
	}
	if(doesPlayerWin(board, nought)){
		gameResult = nought;
		return true;
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board.grid[i][j] == neither){
				return false;
			}
		}
	}

	gameResult = neither;
	return true;

}

position gameFinalResult(boardT& board) {
	position gameResult;
	if(isGameOver(board,gameResult)){
		return gameResult;
	}
	position otherPlayer;
	if(board.currentPlayer == cross){
		otherPlayer = nought;
	}else {
		otherPlayer = cross;
	}
	
	gameResult = otherPlayer;
	
	for(int i =0; i< 3; i++){
		for(int j =0; j< 3; j++){
			if(board.grid[i][j] == neither){
				boardT nextBoard = board;
				nextBoard.grid[i][j] = board.currentPlayer;
				
				

				nextBoard.currentPlayer = otherPlayer;
				position curResult = gameFinalResult(nextBoard);
				
				if(board.currentPlayer == cross){
					if(curResult > gameResult){
						gameResult = curResult;
					}
				}else {
					if(curResult < gameResult){
						gameResult = curResult;
					}
				}
			}
		}	
	}
	return gameResult;

		
	
}


void ps9(){
	boardT newBoard;
	Grid<position> newGrid(3, 3);
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == 1 & j == 1){
				newGrid[i][j] = cross;
			}else if(i == 2 & j == 2){
				newGrid[i][j] = nought;
			}else{
				newGrid[i][j] = neither;
			}
		}
	}
	newBoard.grid = newGrid;
	newBoard.currentPlayer = cross;
	
	if(gameFinalResult(newBoard)==cross){
		cout<<"cross wins"<<endl;
	}else if(gameFinalResult(newBoard)==nought) {
		cout<<"nought wins"<<endl;
	}else{
		cout<<"neither wins"<<endl;
	}
	
}