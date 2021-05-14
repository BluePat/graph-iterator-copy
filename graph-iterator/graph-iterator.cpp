#include <iostream>

#include "logic/bfs-iterator.h"
#include "logic/dfs-iterator.h"
#include "logic/iterator.h"
#include "model/graph.h"

int main(int argc, char* argv[]) {

	try {
		Graph graph("graph1.txt");
		graph.printGraph();

		DFSIterator dfs(graph);
		dfs.iterate();

		BFSIterator bfs(graph);
		bfs.iterate();

	} catch (std::string msg) {
		std::cout << msg;
		return 1;
	}

	return 0;
}
