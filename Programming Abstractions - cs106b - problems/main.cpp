/*
 * File: main.cpp
 * --------------
 * This is a blank C++ source file.
 */

#include <iostream>
#include "console.h"
#include "stack.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>

#include "set.h"
#include "map.h"
#include "foreach.h"

#include "OurLexicon.h"
#include "OurHashMap.h"
#include "OurQueue.h"
//#include "islands.h"
//#include "graph.h"
//#include "DGraph.h"


#include "pseudoPalindrom.h"

//#include "ps22_1.h"

//#include "bst.h"
//#include "LLstring.h"
//#include "deque.h"
//#include "ps13_1.h"
//#include "ps12_1.h"
//#include "ps11_1.h"
//#include "ps10_1.h"
//#include "ps9_1.h"
//#include "ps12_1.h"
//#include "ps11_1.h"
//#include "ps6_1.h"
//#include "ps5_1.h"
//#include "ps4_1.h"
//#include "ps3_1.h"

using namespace std;

//bool isTwosPower(int n); 
//string replace(string str); 
    // Function to find the number of islands.
  /*  struct Node{
      int i;
      int j;
    };*/
    
 //   void bfs(pair<int, int> cur, Set<pair<int, int>>& visited, Vector<Vector<char>>& grid){
	//     for(int i = -1; i <= 1; i++){
 //           for(int j = -1; j <= 1; j++){
 //               if(!(i == 0 && j == 0)){
 //                  /* Node* neig = new Node;
 //                   neig->i = cur->i + i;
 //                   neig->j = cur->j + j;*/
	//				pair<int, int> neig;
	//				neig.first = cur.first + i;
	//				neig.second = cur.second + j;
	//				if(neig.first >= 0 && neig.first < grid.size() && neig.second >= 0 && neig.second < grid[0].size() ){
	//					if(grid[neig.first][neig.second] == '1'){
	//						if(!visited.contains(neig)){
	//							  visited.add(neig);
	//							  bfs(neig, visited, grid);
	//						 }
	//					}
	//				}                                                 
 //               }
 //           }   
 //       }       
 //   }
 //   
 //   int numIslands(Vector<Vector<char>>& grid) {
 //       // Code here
 //       int islands=0;
 //       Set<pair<int, int>> visited;
 //       for(int i =0; i < grid.size(); i++){
 //           for(int j =0; j < grid[0].size(); j++){
 //               if(grid[i][j] == '1'){
 //                   //Node* cur = new Node;  ////////
 //                   //cur->i = i;
 //                   //cur->j = j;
	//				pair<int, int> cur;
	//				cur.first = i;
	//				cur.second = j;

 //                   if(!visited.contains(cur)){
 //                       islands++;
 //                       visited.add(cur);
 //                       bfs(cur, visited, grid);
 //                       
 //                   }
 //                   
 //               }
 //           }
	//		
 //       }
	//	return islands;
 //   }

	//Vector<string> permutationOf(string str){
	//	Vector<string> res;
	//	if(str.size() == 0){
	//		res.add("");
	//		return res;
	//	}
	//	for(int i = 0; i < str.size(); i++){
	//		Vector<string> permutations = permutationOf(str.substr(0,i) + str.substr(i+1));
	//		foreach(string perm in permutations){
	//			res.add(str[i] + perm);
	//		}

	//	}

	//	return res;
	//}

	//void stringPermutationsOf(string soFar, string remaining){
	//	if(remaining == ""){
	//		cout<<soFar<<endl;
	//	}
	//	for(int i = 0; i < remaining.size(); i++){
	//		stringPermutationsOf(soFar + remaining[i], remaining.substr(0, i) + remaining.substr(i + 1));

	//	}


	//}

///////////////////////////////////////////////////////////////////////////////////////////////////// merge sort

//void merge(Vector<int>& left, Vector<int>& right, Vector<int>& v){
//	while(!left.isEmpty() && !right.isEmpty()){
//		int firstL = left[0];
//		int firstR = right[0];
//		
//		if(firstL < firstR){
//			left.remove(0);
//			v.push_back(firstL);
//		}else{
//			right.remove(0);
//			v.push_back(firstR);
//		}
//	}
//
//	/*while(!left.isEmpty()){
//		int cur = left[0];
//		left.remove(0);
//		v.push_back(cur);
//	}
//	while(!right.isEmpty()){
//		int cur = right[0];
//		right.remove(0);
//		v.push_back(cur);
//	}*/
//
//	if(!left.isEmpty()){
//		v+= left;
//	}
//	if(!right.isEmpty()){
//		v+= right;
//	}
//
//
//
//}
//
//void mergeSort(Vector<int>& v){
//	if(v.size() <= 1){
//		return;
//	}
//
//	Vector<int> left;
//	Vector<int> right;
//
//	for(int i = 0; i < v.size()/2; i++){
//		left += v[i];
//	}
//	for(int i = v.size()/2; i < v.size(); i++){
//		right += v[i];
//	}
//	mergeSort(left);
//	cout<<left.toString()<<endl;
//
//	mergeSort(right);
//	cout<<right.toString()<<endl;
//
//	Vector<int> temp;
//	merge(left, right, temp);
//
//	v = temp;
//	
//	cout<<v.toString()<<endl;
//	
//
//}


////
////// from 0 till leftIndex is sorted
//////another part is sorted from rightIndex till the end  ////// noooo
////
//////sorted till left index
//////and another part is sorted from leftIndex + 1 till right index
//
//
//
//// me unda gadavawado dasawyisic, tore mergs izavs 0_dan rodesac sheidzleba me vtxove 1_dan
//
//void mergeOneVector(int bottom, int leftIndex, int rightIndex, Vector<int>& v){
//	cout<<leftIndex<<rightIndex<<endl;
//	for(int i = bottom; i < rightIndex; i++){ ////aqamde righIndex mewera
//		for(int j = leftIndex + 1; j < rightIndex; j++){
//			if(i <= j){///////////////////////////////////////////////////////////////////// ragac momentshi i ufro didi gaxda da ukugma cvlida
//				cout<<v.toString()<<endl;
//				cout<<i<<" "<<j<<endl;
//				if(v[j] < v[i]){
//					int temp = v[j];
//					v.remove(j);   //////// aq jer vainsertebdi da mere vaketebdi removes da shesabamisad araswor indeqsze myofs vshlidi
//					v.insert(i, temp);
//					
//					leftIndex++;
//					break;
//					
//				}///right index -- tu gadavaadgilo washlis mere
//			}
//		
//		}	
//	}
//
//}
//
//  
//void optimisedMergeSort(Vector<int>& v, int low, int high){
//	cout<<"aaa"<<low<<high<<endl;
//	if(v.size() <= 1){
//		return;
//	}
//	if(low + 1 == high){
//		//mergeOneVector(low, high, v);
//		return;
//	}
//
//
//	if(low >= high){
//		return;
//	}
//	//if(high == 1){
//	//	return;
//	//}
//
//	optimisedMergeSort(v, low, (low + high)/2);
//
//	optimisedMergeSort(v, (low + high)/2, high);/////////leqciashi + 1 uweria
//
//
//	//Vector<int> temp;
//	
//	cout<<(low + high)/2<<""<<high<<endl;
//
//	mergeOneVector(low, (low + high)/2 , high , v); ////////////////  aq gadavamowmo low unda eweros?
//
//
//	//v = temp;
//	
//	cout<<v.toString()<<endl;
//	
//
//}

//int partition(Vector<int>& v, int low, int high){
//	int left = low + 1;
//	int right = high;
//	int pivot = v[low];
//
//	while(left < right){
//		if(left<right && v[right] >= pivot) right--; 
//		if(left<right && v[left] < pivot) left++;
//
//		if(left < right){
//			swap(v[left], v[right]);
//		}
//
//	}
//	if(v[right] > pivot){
//		return low;
//	}
//	swap(v[right], v[low]);
//	return right;
//}

//void quickSort(Vector<int>& v, int low, int high){
//	if(low >= high){
//		return;
//	}
//	int partition = partition(v, low, high);
//	quickSort(v, low, partition - 1);
//	quickSort(v, partition + 1, high);
//}

int main() { ///////////////

	pseudoPalindrom();
	//ps22();




	//OurLexicon words;
	//words.addWord("a");
	//words.addWord("ab");
	//words.addWord("about");
	//words.addWord("ad");
	//words.addWord("adage");
	//words.addWord("adagio");
	//words.addWord("bar");
	//words.addWord("bard");
	//words.addWord("barn");
	//words.addWord("be");
	//words.addWord("bed");
	//words.addWord("bet");
	//words.addWord("beta");
	//words.addWord("can");
	//words.addWord("cane");
	//words.addWord("cat");
	//words.addWord("dictaphone");
	//words.addWord("dictation");
	//words.addWord("dikdik");
	//words.addWord("diktat");
	//
	///* Remove a few words we don't like. */
	//words.removeWord("dictaphone");
	//words.removeWord("dictation");
	//
	//while (true) {
	//	/* Read some text from the user. */
	//	string key = getLine("Enter a search key: ");
	//	if (key == "") break;
	//	
	//	cout << "Is it a word?   " << boolalpha << words.containsWord(key) << endl;
	//	cout << "Is it a prefix? " << boolalpha << words.containsPrefix(key) << endl;
	//}
	//


	/////////////////////////////////////////////////////////ourHashMap
	//OurHashMap map;
	//
	////while (true) {
	////	/* Read some text from the user. */
	////	string key = getLine("Enter a search key: ");
	////	
	////	/* Count how many times we've seen it. */
	////	int lookupTimes = 0;
	////	if (map.containsKey(key)) {
	////		lookupTimes = map.get(key);
	////	}
	////	
	////	cout << "You've looked that up " << lookupTimes
	////	     << " time" << (lookupTimes == 1? "" : "s")
	////	     << " before." << endl;
	////	
	////	/* Update the map. */     
	////	map.put(key, lookupTimes + 1);
	////}

	////map.put("a", 5);
	////cout<<map.size()<<endl;
	////cout<<map.get("a")<<endl;
	////map.put("b", 15);
	////cout<<map.size()<<endl;
	////cout<<map.get("b")<<endl;

	////map.remove("b");
	////cout<<map.get("b")<<endl;

	//for(int i = 0; i < 20; i ++){
	//	char ch = 'a'+ i;
	//	string str = string(1, ch);
	////	cout<<str<<endl;
	//	map.put(str,i);
	//}
	//map.remove("p");
	//cout<<map.get("b")<<endl;
	//cout<<map.get("i")<<endl;
	////cout<<map.get("p")<<endl;

//////// optimised merge sort   not working        
//	Vector<int> res1;
//	res1.add(5);
//	res1.add(3);
//	res1.add(10000);
//
//	res1.add(2);
//	res1.add(4);
//	res1.add(6);
//	//res1.add(222);
//	//res1.add(2222);
//	cout<<res1.toString()<<endl;
//
//	//mergeOneVector(0, 2, res1.size(), res1);
//	//cout<<res1.toString()<<endl;
//
//
//	optimisedMergeSort(res1, 0, res1.size());
//	cout<<res1.toString()<<endl;



	////////////////////////////////////////////////merge sort
	/*Vector<int> res;
	Vector<int> left;
	Vector<int> right;
	for(int i = 0; i <= 9;){
		left.add(i);
		i+=2;
	}
	for(int i = 1; i <= 9;){
		right.add(i);
		i+=2;
	}
	

	merge(left, right, res);
	cout<<res.toString()<<endl;*/

	//Vector<int> res1;
	//for(int i = 9; i > 0;){
	//	res1.add(i);
	//	i--;
	//}

	//mergeSort(res1);
	//cout<<res1.toString()<<endl;
	
	////////////////////////////////////////////////


//	OurQueue q;
//	q.enqueue(1);
//	q.enqueue(2);
//	q.enqueue(3);
//	cout<<q.size()<<endl;
//	cout<<q.front()<<endl;
//	cout<<q.dequeue()<<endl;
//	cout<<q.dequeue()<<endl;
//	cout<<q.dequeue()<<endl;
////	cout<<q.dequeue()<<endl;
//	cout<<q.isEmpty()<<endl;
//	

	//stringPermutationsOf("","abc");
	//cout<<permutationOf("abc")<<endl;

	//countIslands1();

	////////////
	//Vector<Vector<char>> grid;
	//Vector<char> v1(4,'0');
	//Vector<char> v2(4,'0');
	//Vector<char> v3(4,'0');
	//Vector<char> v4(4,'0');
	//grid.add(v1);
	//grid.add(v2);
	//grid.add(v3);
	//grid.add(v4);
	//grid[0][0] = '1';
	//grid[1][1] = '1';
	////grid[0][0] = '1';
	//grid[3][3] = '1';
	////grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};
	//cout<<numIslands(grid)<<endl;


//	//problem set 23
//	DGraph gr(4);
//	gr.addEdge(0, 1);
//	//gr.addEdge(1, 2);
//	gr.addEdge(2, 3);
////	gr.addEdge(0, 3);
//	cout<<gr.edgeCount()<<endl;
//	cout<<gr.hasPath(0,3)<<endl;
//	cout<<gr.shortestPath(0,3)<<endl;
//	cout<<gr.numComponents()<<endl;

	////problems set 22
	//cout<<"start of ps22"<<endl;
	//ps22();

	//cout<<"end of ps22"<<endl;
	//////////////////////

	/////////////// problem set 21 ++++++++ mirror (tree_is shebruneba sarkiseburad)
	//bst tree1 = bst(); 
	//tree1.insert(1);
	//tree1.insert(2);
	//tree1.insert(3);

	//tree1.insert(4);
	//tree1.insert(5);
	//
	///*tree1.insert(1);
	//tree1.insert(2);
	//tree1.insert(3);

	//tree1.insert(5);
	//tree1.insert(4);*/
	//
	////cout<<"mirror tree "<<endl;
	////tree1.printTree();
	////bst::Node* mirroredTree = tree1.mirrorTree();
	////tree1.printSubtree(mirroredTree);

	//cout<<"depth "<<endl;
	//
	//
	///*cout<<mirroredTree->left->val<<endl;
	//cout<<mirroredTree->val<<endl;
	//cout<<mirroredTree->right->val<<endl;*/

	//cout<<tree1.depth()<<endl;
	//cout<<"number of nodes in each level"<<endl;
	//cout<<tree1.printLevels()<<endl;

	//cout<<"buildBalancedTree"<<endl;
	//bst::Node* temp1 = tree1.balanceTree();
	//cout<<temp1->val<<endl;
	//cout<<temp1->left->val<<" "<<temp1->right->val<<endl;
	//cout<<temp1->left->right->val<<" "<<temp1->right->right->val<<endl;

	//
	//tree1.printSubtree(temp1);

	////tree1.printSubtree(tree1.balanceTree());
	////cout<<tree1.printLevels()<<endl;

	///////////////////////////////////////////////////////////////////////////////////////

	
	//LLstring linkedL1("abcd");
	//LLstring linkedL2("efg");
	//LLstring linkedL3 = linkedL1 + linkedL2;
	//LLstring linkedL4(linkedL2);
	//cout<<linkedL1.toString()<<endl;
	//cout<<linkedL2.toString()<<endl;
	//cout<<linkedL3.toString()<<endl;
	//cout<<linkedL4.toString()<<endl;

	/*deque<int> tempData;
	tempData.pushFront(3);
	tempData.pushFront(2);
	tempData.pushFront(1);
	tempData.pushBack(4);
	tempData.pushBack(5);
	tempData.pushBack(6);

	while(!tempData.isEmpty()){
		cout<<tempData.popFront()<<endl;
	}*/

	//ps12();
	//ps11();
	//	ps10();
//	ps9();
	//ps13();

	//problem set 12
	//ps12();

	//problem set 11
	//ps11();

	//problem set 6
	//bla();
	//problem set 5
	//ps5();

	//problem set 4
	//ps4();

	//problem set 3
	//ps3();

	//int n = getInteger();
	//cout << isTwosPower(1) << endl;

	/*string str = "bca";
	
	replace(str);

	cout<<str<<endl;*/

	//int n = getInteger();
	//int sentinel = -1;

	//Stack<int> s; 
	
	//Set<char> s1;
	//Set<char> s2;

	//string str1 = "aaabbc";
	//string str2 = "bca";

	//for(int i=0;i<str1.length();i++){
	//	s1.add(str1[i]);
	//}

	//for(int i=0;i<str2.length();i++){
	//	s2.add(str2[i]);
	//}

	
	


    return 0;
}




//void replace(string &str){
//		
//	cout<<"Shemovedi"<<endl;
//	//int min = INT_MAX;9
//	int minIndex = 0;
//
//	for(int i=0;i<str.length();i++){
//		if(str[i]<str[minIndex]){
//			minIndex=i;
//		//	min=str[i];//char becomes int?
//		}
//	}
//	string temp = str;
//	temp[minIndex]=str[0];
//	temp[0] = str[minIndex];
//	str = temp;
//}


//bool isTwosPower(int n){
//	if(n==1){
//		return true;
//	}
//	if(n%2==1){
//		return false;
//	}
//		return isTwosPower(n/2);
//	
//
//}