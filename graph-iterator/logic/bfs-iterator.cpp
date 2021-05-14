#include <vector>

#include "bfs-iterator.h"

constexpr auto FIRST_VERTEX = 0;

BFSIterator::BFSIterator(Graph graph) {
	graph = graph;
	// All verices are initially marked as not visited.
	std::vector<bool> visited(graph.getNumberOfVertices(), false);
	queue;
}

void BFSIterator::reset() {
	this->queue.push(FIRST_VERTEX);
}

void BFSIterator::next() {
	if ( !queue.empty() ) {
		int current = queue.front();
		queue.pop();

		visited[current] = true;

		auto neighbours = graph.getNeighbours(current);
		for (auto i = neighbours.begin(); i != neighbours.end(); ++i) {
			if ( !visited[*i] ) {
				queue.push(*i);
			}
		}
	} else {
		for (int i = 0; i < visited.size(); ++i) {
			if ( !visited[i] ) {
				queue.push(i);
				break;
			}
		}
	}
}

int BFSIterator::currentKey() {
	return queue.front();
}
