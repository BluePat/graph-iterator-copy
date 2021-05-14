#include <vector>
#include <string>

/** Simple undirected graph implementation using adjecency list representation. */
class Graph {

private:

    /** Number of graph's vertices. */
    int V;

    /** Representation of Graph as an adjecency list. */
    std::vector<int> *adjacency_list;

public:

    /** Constructs V-vertex graph with no edges. */
    Graph(int V = 0);

    /** Reads graph from given input file. */
    Graph(std::string file_name);

    /** Getter, returns number of vertices. */
    int getNumberOfVertices();

    /** Returns neighbours of a given vertex. */
    std::vector<int> getNeighbours(int vertex);

    /** Connects vertices u, v by an edge. */
    void addEdge(int u, int w);

    /** Prints the adjacency list representation of the graph. */
    void printGraph();
};
