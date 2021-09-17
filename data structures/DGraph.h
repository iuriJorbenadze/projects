#pragma once
#include "set.h"

class DGraph {
	private:
		struct Vertex {
			Set<Vertex*> neighbours;
		};
		int numVertices;
		int numEdges;
		Vertex* vertices;
		bool hasPath(Vertex* start, Vertex* finish, Set<Vertex*> visited);

		void bfs(Set<Vertex*>& visited, Vertex*& cur);

	public:
		DGraph(int size);
		~DGraph();
		int size();
		int edgeCount();
		void addEdge(int i, int j);
		void removeEdge(int i, int j);
		bool hasEdge(int i, int j);
		bool hasPath(int i, int j);

		int shortestPath(int i, int j);
		int numComponents();
};