#include "DGraph.h"
#include "error.h"
#include "queue.h"

//class DGraph {
//private:
//	struct Vertex {
//		Set<Vertex*> neighbours;
//	};
//	int numVertices;
//	int numEdges;
//	Vertex* vertices;
//	bool hasPath(Vertex* start, Vertex* finish, Set<Vertex*> visited);
//
//	public:
//	DGraph(int size);
//	~DGraph();
//	int size();
//	int edgeCount();
//	void addEdge(int i, int j);
//	void removeEdge(int i, int j);
//	bool hasEdge(int i, int j);
//	bool hasPath(int i, int j);
//};

DGraph::DGraph(int size){
	if(size < 1) error("invalid size");

	numVertices= size;
	numEdges = 0;
	vertices = new Vertex[numVertices];
}

DGraph::~DGraph(void){
	delete[] vertices;
}

int DGraph::size(){
	return numVertices;
}
int DGraph::edgeCount(){
	return numEdges;
}

bool DGraph:: hasEdge(int i, int j){
	if(i >= 0 && j >= 0 && i < numVertices && j < numVertices){
		//another possible syntax
		//return vertices[i].neighbours.contains(vertices + j);
		return vertices[i].neighbours.contains(&vertices[j]);
	}else{
		error("invalid size");
	}
}

void DGraph::addEdge(int i, int j){
	if(!hasEdge(i, j)){
		vertices[i].neighbours.insert(&vertices[j]);
		numEdges++;
	}
}

void DGraph :: removeEdge(int i, int j){
	if(hasEdge(i, j)){
		vertices[i].neighbours.remove(&vertices[j]);
		numEdges--;
	}
}

//bool DGraph :: hasPath(int i, int j){
//	Vertex* start = &vertices[i];
//	Vertex* end = &vertices[j];
//	if(start == end) return true;
//	Set<Vertex*> visited;
//	Queue<Vertex*> toVisit;
//	toVisit.enqueue(start);
//	while(!toVisit.isEmpty()){
//		Vertex* cur = toVisit.dequeue();
//		if(cur == end) return true;
//		
//		foreach(Vertex* neig in cur->neighbours){
//			if(!visited.contains(neig)){
//				visited.add(neig);
//				toVisit.enqueue(neig);
//			}
//		}
//
//		/*if(!visited.contains(cur)){
//			visited.add(cur);
//
//			if(cur == &vertices[j]) return true;
//
//			foreach(Vertex* neig in cur->neighbours){
//				if(!visited.contains(neig)){
//					toVisit.enqueue(neig);
//				}
//			}
//
//		}*/
//
//	}
//	return false;
//}


bool DGraph::hasPath(Vertex* start, Vertex* finish, Set<Vertex*> visited){
	if(start == finish) return true;
	visited.add(start);
	foreach(Vertex* neig in start->neighbours){
		if(!visited.contains(neig)){
			if(hasPath(neig, finish, visited)){
				return true;
			}	
		}
	}

	return false;
}

bool DGraph::hasPath(int i, int j){
	Vertex* start = &vertices[i];
	//Vertex* end = &vertices[j];
	Vertex* end = vertices + j;
	Set<Vertex*> visited;
	return hasPath(start, end, visited);
	
}

int DGraph :: shortestPath(int i, int j){
	Vertex* start = &vertices[i];
	Vertex* end = &vertices[j];
	Set<Vertex*> visited;
	Queue<Vertex*> toVisit;
	toVisit.enqueue(start);
	int dist = 0;
	int nodesTillNextLevel = 1;

	while(!toVisit.isEmpty()){
		Vertex* cur = toVisit.dequeue();
		nodesTillNextLevel--;

		if(cur == end) return dist;
		

		foreach(Vertex* neig in cur->neighbours){
			if(!visited.contains(neig)){
				visited.add(neig);
				toVisit.enqueue(neig);
			}
		}
		if(nodesTillNextLevel == 0){
			dist++;
			nodesTillNextLevel = toVisit.size();
		}

	}



	return -1;
}

void DGraph :: bfs(Set<Vertex*>& visited, Vertex*& cur ){
	Queue<Vertex*> toVisit;

	toVisit.enqueue(cur);
	while(!toVisit.isEmpty()){
		Vertex* curVert = toVisit.dequeue();
		foreach(Vertex* neig in curVert->neighbours){
			if(!visited.contains(neig)){
				visited.add(neig);
				toVisit.enqueue(neig);
			}
		}

	}
}

int DGraph :: numComponents(){
	Set<Vertex*> visited;
	int numComps = 0;

	for(int i = 0; i < numVertices; i++){
		Vertex* cur = &vertices[i];

		if(!visited.contains(cur)){
			numComps++; 
			bfs(visited, cur);
		}
	}
	return numComps;
}