#include <vector>

#include "dfs-iterator.h"

constexpr auto FIRST_VERTEX = 0;

DFSIterator::DFSIterator(Graph graph) {
	graph = graph;
	// All verices are initially marked as not visited.
	std::vector<bool> visited(graph.getNumberOfVertices(), false);
	stack;
}

void DFSIterator::reset() {
	this->stack.push(FIRST_VERTEX);
}

void DFSIterator::next() {
	if ( !stack.empty() ) {
		int current = stack.top();
		stack.pop();

		visited[current] = true;

		auto neighbours = graph.getNeighbours(current);
		for (auto i = neighbours.begin(); i != neighbours.end(); ++i) {
			if ( !visited[*i] ) {
				stack.push(*i);
			}
		}
	} else {
		for (int i = 0; i < visited.size(); ++i) {
			if ( !visited[i] ) {
				stack.push(i);
				break;
			}
		}
	}
}

int DFSIterator::currentKey() {
	return stack.top();
}
