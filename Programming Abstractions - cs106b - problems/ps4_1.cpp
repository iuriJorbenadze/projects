#include <iostream>
#include "ps4_1.h"

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

void problem1();
void problem2();
void problem3();

void countChars(string word, Vector<int>& alphabetStatistics);

const int alphabetSize = 26;

void ps4(){
	//problem1();	
	//problem2();	
	problem3();	

}

void problem1(){
	string file = "t.txt";
	ifstream input;
	input.open(file.c_str());
	
	TokenScanner scanner;
	scanner.setInput(input);
	scanner.ignoreWhitespace();

	Stack<string> st;
	while(scanner.hasMoreTokens()){
		st.push(scanner.nextToken());
	}
	input.close();

	ofstream output;
	output.open("output.txt");
	
	while(!st.isEmpty()){
		output << st.pop();
		if(!st.isEmpty()){
			output << " ";
		}else{
			output<<endl;
		}

	}


	output.close();
}


void problem2(){
	
	string file = "t.txt";
	ifstream input;
	input.open(file.c_str());

	TokenScanner scanner;
	scanner.setInput(input);
	scanner.ignoreWhitespace();

	Vector<string> vec;
	while(scanner.hasMoreTokens()){

		vec.add(scanner.nextToken());
	}
	input.close();
	
	ofstream output;
	output.open("output.txt");
	
	for(int i=0; i< vec.size(); i+=2){
		output<<vec[i];
		if(i+2 < vec.size()){
			output << " ";
		}else{
			output<<endl;
		}

	}
	for(int i=1; i< vec.size(); i+=2){
		output<<vec[i];

		if(i+2 < vec.size()){
			output << " ";
		}else{
			output<<endl;
		}
	}
	output.close();
}

void problem3(){
	string file = "t.txt";
	ifstream input;
	input.open(file.c_str());

	TokenScanner scanner;
	scanner.setInput(input);
	scanner.ignoreWhitespace();

	Vector<int> alphabetStatistics(alphabetSize,0);
	while(scanner.hasMoreTokens()){
		countChars(scanner.nextToken(),alphabetStatistics);
	}
	input.close();
	
	int count =0;
	foreach(int x in alphabetStatistics){
		cout << (char)('a'+count) << ": " << x << " ";
		count++;
	}
	cout<<endl;
}

void countChars(string word, Vector<int>& alphabetStatistics){


	for(int i=0;i<word.length();i++){
		word[i] = tolower(word[i]); 
	}

	for(int i=0; i< word.size(); i++){
		alphabetStatistics[word[i]-'a']++;

	}

	
}