#include <iostream>
#include "ps6_1.h"

#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>
#include "vector.h"
#include "strlib.h"
#include "set.h"
#include "map.h"

using namespace std;

void stringToSet();
void readFileCreateStats();
void areSwapable();
Set<string> swapChars(Set<string> s);
Set<string>  swap(string str);

void bla(){

	
	//stringToSet();
	//readFileCreateStats();

	areSwapable();
	

}


//problem 1
//void stringToSet(){
//	string str1 = getLine();
//	string str2 = getLine();
//
//	Set<char> s1;
//	Set<char> s2;
//
//	for(int i=0; i< str1.length(); i++){
//		s1.add(str1[i]);
//	}
//	for(int i=0; i< str2.length(); i++){
//		s2.add(str2[i]);
//	}
//
//	cout << (s1*s2) << endl;
//	cout << (s1-s2) << endl;
//	cout << (s2-s1) << endl;
//}

//void readFileCreateStats(){
//
//	string file = getLine();
//
//	ifstream input;
//	input.open(file.c_str());
//
//	TokenScanner scanner;
//	scanner.setInput(input);
//	scanner.ignoreWhitespace();
//	scanner.addWordCharacters(".,/-?!");
//
//	Map<string, int> stats;
//
//	while(scanner.hasMoreTokens()){
//		string tok = scanner.nextToken();
//		if(stats.containsKey(tok)){
//			stats[tok]++;
//		}else{
//			stats[tok]=1;
//		}
//		
//	}
//	input.close();
//
//	foreach(string str in stats){
//		cout << str << " :" << stats[str] << endl;
//	}
//	cout<<"done"<<endl;
//	
//}


void areSwapable(){

	int n = getInteger();

	string str1 = getLine();
	string str2 = getLine();


	Set<string> s1;
	Set<string> s2;

	s1.add(str1);
	s2.add(str2);
	
	for(int i=0;i<n;i++){
		s1 += swapChars(s1);
		s2 += swapChars(s2);
	}
	
	cout << (s1*s2) <<endl;

}

Set<string> swapChars(Set<string> s){
	Set<string> result;

	foreach(string str in s){
		result += swap(str);
	}

	

	return result;
}

Set<string>  swap(string str){
	Set<string> newSet;
	

	//solution if replacement is permited with any possible index
	/*for(int i=0; i < str.length(); i++){
		for(int j= i+1; j < str.length(); j++){
			
			string newStr = str;
			newStr[i]=str[j];
			newStr[j]=str[i];
			newSet.add(newStr);
		}
		
	}*/

	//actual solve where replacement is only permited with next character
	for(int i=0; i < str.length()-1; i++){
		
			
			string newStr = str;
			newStr[i+1]=str[i];
			newStr[i]=str[i+1];
			newSet.add(newStr);
		
		
	}

	return newSet;


}

