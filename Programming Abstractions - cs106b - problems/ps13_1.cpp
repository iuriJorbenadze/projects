#include <iostream>
#include "ps13_1.h"

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

void swap(Vector<int>& vec, int i, int j){
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

int selectionSortWithCompareCount(Vector<int>& vec) {
	int res =0;
	for(int i=0; i < vec.size(); i++){
		int minIndex = i;
		for(int j=i;j<vec.size(); j++){
			if(vec[j]<vec[minIndex]){
				minIndex = j;
			}
			res++;
		}
		swap(vec, i, minIndex);
	}
	return res;

}
int insertionSortWithCompareCount(Vector<int>& vec) {
	int res =0;
	for(int i=1; i < vec.size(); i++){
		int curPos = i;
		while(curPos > 0){
			if(vec[curPos] < vec[curPos-1]){
				swap(vec, curPos, curPos-1);
				curPos--;
			}else{
				break;
			}
			res++;

		}
	}
	return res;
}




//
//struct intPair{
//	int first;	
//	int second;
//};
//
//int evaluateExpression(string s);
//int fib(int n);
//intPair fibonachi(int n);



string swapCharsAtIndex(string s, int index) {
	string result = s;
	result[index] = s[index + 1];
	result[index + 1] = s[index];
	return result;
}

//void extendSet(Set<string>& words){
//	Set<string> newWords;
//	
//	foreach(string word in words){
//		for(int i =0; i< word.length-1; i++){
//			string newWord = swapCharsAtIndex(word, i);	
//			newWords.add(newWord);
//		}
//	}
//	words += newWords;
//}

// problem set 8
bool canComposeWith(int value, Vector<int>& units) {
	if (0 == value)
		return true;
	if ( 0 > value)
		return false;

	for (int i = 0; i < units.size(); i++) {
		if( canComposeWith(value - units[i], units)){
			return true;
		}
	}
	return false;
}

bool subsetSum(int target, Vector<int>& set, int startIndex = 0) {
	if(target == 0){
		return true;
	}
	if(startIndex == set.size()){
		return false;
	}

	return subsetSum(target - set[startIndex], set, startIndex + 1) || subsetSum(target, set, startIndex + 1);
}


void ps13(){
	//cout<< evaluateExpression("5-(7-4-(3-2-1))") << endl;

	//cout<<fib(4)<<endl;

	//cout<<fibonachi(4).first<<endl;
	Vector<int> units;
	units.add(3);
	units.add(9);
		cout<<canComposeWith(10,  units) <<endl;
	
	
}

//
//int evaluateExpression(string s) {
//	Stack<int> savedValues;
//	bool firstInteger = true;
//	int curValue;
//
//	for(int i=0; i< s.length(); i++){
//		if(s[i] == '-'){
//			
//		}else if(s[i]=='('){
//			savedValues.push(curValue);
//			firstInteger = true;
//		}else if(s[i] == ')'){
//			curValue = savedValues.pop() - curValue;
//		}else{
//			if(firstInteger){
//				curValue = s[i] -'0';
//				firstInteger = false;
//			}else{
//				curValue -= (s[i] - '0');
//			}
//
//		}
//	}
//
//	return curValue;
//}
//
//int fib(int n){
//	if(n <= 1){
//		return n;
//	}
//
//	return fib(n - 1) + fib(n - 2);
//}
//
//
//
//intPair fibonachi(int n){
//	if(n == 0){
//		intPair res;
//		res.first = 0;
//		res.second = 1;
//		return res;
//	}
//
//	intPair res;
//	intPair prev = fibonachi(n -1);
//	res.first = prev.second;
//	res.second = prev.first + prev.second;
//
//
//	return res;
//}