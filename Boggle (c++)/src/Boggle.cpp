/*
 * File: Boggle.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;

const string STANDARD_CUBES[16]  = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const string BIG_BOGGLE_CUBES[25]  = {
    "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
    "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
    "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
    "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
    "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

//displayed grid
Grid<char> board(4, 4);
//highlighted grid
Grid<char> highlited(4, 4);

/* Function prototypes */

void welcome();
void giveInstructions();
void askForConfig();
void setNewConfig();
void defaultConfig();
Grid<char> fillBoard(Vector<string>& cubes);
string stringValidation();
Set<string> enterWord();
bool isValidWord(string word, Lexicon& engWords, Set<string>& enteredWords);
bool foundOnBoard(string word);

bool searchOnBoard(string word, Grid<bool> empty, int i, int j );
void fillHighlightedGrid(Grid<bool> empty);
void highLightGrid();
void displayComputerWords(Set<string> onlyCimputerWords);
bool endMsg();

//computer
Set<string> generatePosibWords();
Set<string> generateWordsRec(Set<string>& res, Lexicon& engWords, int i, int j, string curWord, Grid<bool> empty );


/* Main program */

int main() {
	while(true){
		GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
		initGBoggle(gw);
		welcome();
		giveInstructions();

		/////////////
		drawBoard(4, 4);
		askForConfig();
		
		Set<string> playersWords = enterWord();

		Set<string> allPosibWords = generatePosibWords();

		displayComputerWords(allPosibWords - playersWords);

		if(!endMsg()){
			break;
		}
		gw.clear();
		

	}
    return 0;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
    cout << "Welcome!  You're about to play an intense game ";
    cout << "of mind-numbing Boggle.  The good news is that ";
    cout << "you might improve your vocabulary a bit.  The ";
    cout << "bad news is that you're probably going to lose ";
    cout << "miserably to this little dictionary-toting hunk ";
    cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
    cout << endl;
    cout << "The boggle board is a grid onto which I ";
    cout << "I will randomly distribute cubes. These ";
    cout << "6-sided cubes have letters rather than ";
    cout << "numbers on the faces, creating a grid of ";
    cout << "letters on which you try to form words. ";
    cout << "You go first, entering all the words you can ";
    cout << "find that are formed by tracing adjoining ";
    cout << "letters. Two letters adjoin if they are next ";
    cout << "to each other horizontally, vertically, or ";
    cout << "diagonally. A letter can only be used once ";
    cout << "in each word. Words must be at least four ";
    cout << "letters long and can be counted only once. ";
    cout << "You score points based on word length: a ";
    cout << "4-letter word is worth 1 point, 5-letters ";
    cout << "earn 2 points, and so on. After your puny ";
    cout << "brain is exhausted, I, the supercomputer, ";
    cout << "will find all the remaining words and double ";
    cout << "or triple your paltry score." << endl << endl;
    cout << "Hit return when you're ready...";
    getLine();
}

// [TODO: Fill in the rest of the code]



void askForConfig(){
	cout<<"I'll give you a chance to set up the board to your specification, which makes it easier to confirm your boogle program is working."<<endl;
	
	string answer = toUpperCase(getLine("Do you want to force the board configuration? " ));
	
	while(true){	
		if(answer == "YES" || answer == "NO"){
			break;
		}
		cout << "Please answer yes or no."  << endl;
		answer = toUpperCase(getLine("Do you want to force the board configuration? " ));
	}



	if (answer == "YES"){
		setNewConfig();
	}else{
		defaultConfig();
	}
	
}

//ALSO HAS EXSTENSION: if no words can be generated, asks player to enter configuration string again	
//sets new configuration by entering string which will be displayed
void setNewConfig(){
	cout<<"Enter a 16-character string to identify which letter you want on the cubes. The first 4 letters are the cubes on the top row from left to right, the next 4 letters are the second row, and so on."<<endl;
	while(true){
		string stringToDisplay = stringValidation();

		Vector<string> cubes;
		for(int i=0; i < 16; i++){
			
			string empt;
			empt  += stringToDisplay[i];
			cubes.add(empt);
			
		}	
		
		board = fillBoard(cubes );
		
		if(!generatePosibWords().isEmpty()){
			break;
		}
		cout<<"Wrong input! try again."<<endl;
	
	}
	
}




// returns only first 16 or 25 of string , if less than that asks to enter again
string stringValidation(){

	string stringToDisplay = toUpperCase(getLine("Enter the string: "));
	while(true){
		if(stringToDisplay.size() >= 16){
			return stringToDisplay.substr(0, 16);
			break;
		}
		cout<<"string must include 16 charactes! Please try again." <<endl;
		stringToDisplay = toUpperCase(getLine("Enter the string "));
		
	}
	
}





//using standard cubes
void defaultConfig(){
	
	Vector<string> cubes;
	for(int i=0; i < 16; i++){
		cubes.add(STANDARD_CUBES[i]);
	}	
	

	
	for (int i = 0; i < cubes.size(); i++) {
		int x = randomInteger(i, cubes.size() - 1);
		string temp = cubes[i];
		cubes[i] = cubes[x];
		cubes[x] = temp;

		
		
	}
	board = fillBoard(cubes );

}

Grid<char> fillBoard(Vector<string>& cubes){
	Grid<char> displayedChars(4, 4);

	int index =0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			string curCube = cubes[index];
			int randChIndex = randomInteger(0, curCube.size() - 1); //////////
			char randCh = curCube[randChIndex];
			displayedChars[i][j] = randCh;
			labelCube(i, j, randCh);
			index++;
		}
	}

	return displayedChars;

}

Set<string> enterWord(){
	Set<string> enteredWords;

	Lexicon engWords("EnglishWords.dat");

	while(true){
		string word = toUpperCase(getLine("Enter a word: "));
		if(isValidWord(word, engWords, enteredWords)){
			
			recordWordForPlayer(word, HUMAN);

			highLightGrid();

			enteredWords.add(word);

			
		}else if(word == ""){
			return enteredWords;
			break;
		}else{
			cout<<"Try again! Wrong input."<<endl;
		}
	}

	
	

	
}

bool isValidWord(string word, Lexicon& engWords, Set<string>& enteredWords){
	if(word.size() < 4 || !engWords.contains(word) || enteredWords.contains(word)){
		return false;
	}
		//check if word can be found on board
	if(!foundOnBoard(word)){
		return false;
	}






	return true;
}

//check if this word be found on board
bool foundOnBoard(string word){
	for(int i=0; i < board.nRows; i++){
		for(int j=0; j < board.nCols; j++){
			if(board[i][j] == word[0]){
				Grid<bool> empty(4, 4);
				
				if( searchOnBoard(word.substr(1), empty, i, j)){
					return true;
				}
			}
		}
	}
	

	return false;
}

//recursive function to find word on board
bool searchOnBoard(string word, Grid<bool> empty, int i, int j ){
	empty[i][j] = 1;

	if(word == ""){
		//highlited = empty;
		fillHighlightedGrid(empty);

		return true;
	}

	for(int r = -1; r <= 1; r++){
		for(int c = -1; c <= 1; c++){
			if(empty.inBounds(i + r, j + c)){
				if(board[i + r][j + c] == word[0] && empty[i+ r][j + c] == 0){
					
					if( searchOnBoard(word.substr(1), empty, i + r, j + c)){
						return true;
					}
				}
			}
		}		
	}
	//////////////////////////////////////////////////////////TODO empty with &, and make it emprty before return false
	return false;
	
}

void fillHighlightedGrid(Grid<bool> empty){
	for(int i = 0; i < empty.nRows; i++){
		for(int j = 0; j < empty.nCols; j++){
			highlited[i][j] = empty[i][j];			
		}
	}
}

void highLightGrid(){
	for(int i = 0; i < highlited.nRows; i++){
		for(int j = 0; j < highlited.nCols; j++){
			if(highlited[i][j] == 1){
				highlightCube(i, j, 1);
				
			}
		}
	}
	pause(300);
	// will remove highlight
	for(int i = 0; i < highlited.nRows; i++){
		for(int j = 0; j < highlited.nCols; j++){
			if(highlited[i][j] == 1){
				highlightCube(i, j, 0);
				
			}
		}
	}

}



Set<string> generatePosibWords(){
	Set<string> res;
	Lexicon engWords("EnglishWords.dat");

	for(int i = 0; i < board.nRows; i++){
		for(int j = 0; j < board.nCols; j++){

			Grid<bool> empty(4, 4);
			res += generateWordsRec(res, engWords, i, j, "", empty );  
		}
	}
	
	return res;
}

Set<string> generateWordsRec(Set<string>& res, Lexicon& engWords, int i, int j, string curWord, Grid<bool> alreadyUsed ){
	alreadyUsed[i][j] = 1;

	curWord += board[i][j];
	
	Set<string> curWords;
	if(!engWords.containsPrefix(curWord)){
		return curWords;
	}
	if(curWord.size() >= board.nCols && engWords.contains(curWord)  ){
		curWords.add(curWord);
	}

	for(int r = -1; r <= 1; r++){
		for(int c = -1; c <= 1; c++){
			if(alreadyUsed.inBounds(i + r, j + c)){
				if( alreadyUsed[i+ r][j + c] == 0){
					
					curWords += generateWordsRec(res, engWords,  i + r, j + c, curWord, alreadyUsed);
					
				}
			}
		}		
	}


	return curWords;
}

void displayComputerWords(Set<string> onlyCimputerWords){
	foreach(string word in onlyCimputerWords){
		recordWordForPlayer(word, COMPUTER);
	}
	
}


bool endMsg(){
	string answer = toUpperCase(getLine("Would you like to play again?"));
	

	while(true){	
		if(answer == "YES") {
			return true;
			
		}else if(answer == "NO"){
			return false;
		}
		cout << "Please answer yes or no."  << endl;
		answer = toUpperCase(getLine());
	}
	
}


