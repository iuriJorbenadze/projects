#include <iostream>
#include "ps3_1.h"

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

void prob1();
void prob2(string s);

void ps3(){
	//prob1();


	prob2("3-(5-(4-3)-(3-3))");
}

void prob1(){
	Stack<int> st;

	int sentinel = -1;
	
	while(true){
		int n = getInteger();
		if(n == sentinel){
			break;
		}
		st.push(n);

	}
	while(!st.isEmpty()){
		cout<<st.pop()<<endl;
	}

}

void prob2(string s){
	bool firstNum =true;
	Stack<int>savedValues;
	int lastValue=0;

	for(int i=0; i<s.length();i++){
		if(firstNum){
			lastValue += (s[i]-'0');
			firstNum=false;
		}else if(s[i]=='-'){

		}else if(s[i]=='('){
			savedValues.push(lastValue);
			lastValue=0;
			firstNum=true;
		}else if(s[i]==')'){
			lastValue = savedValues.pop() - lastValue;
		}else {
			lastValue -= (s[i]-'0');
		}


	}
	cout<<lastValue<<endl;

	

}