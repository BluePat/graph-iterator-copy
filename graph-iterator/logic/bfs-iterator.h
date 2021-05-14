#include <queue>

#include "iterator.h"

/** Simple implementation of breadth-first search algorithm over graph. */
class BFSIterator : public Iterator {

private:

    /** A graph to iterate over. */
    Graph graph;

    /**
     * Queue used by breadth-first search algorithm.
     *
     * At the beggining of the queue, there is a currently proccesed vertex.
     * Behind are unprocessed known vertices.
     */
    std::queue<int> queue;

public:

    /** Constructs DFS iterator for given graph. */
    BFSIterator(Graph graph = Graph(0));

    /** Prepares an interation by placing vertex with the lowest int value onto the stack. */
    void reset();

    /**
     * Moves the iterator to the next vertex.
     *
     * The method tests if the queue is empty:
     *  a. If it is not empty, it removes current vertex and add all its uknown neighbours to the queue.
     *  b. Otherwise uses collection of vertices `visited` to find (if any) unprocessed vertex and puts it to the queue.
     */
    void next();

    /** Returns true if all verticis have been visited. */
    bool isEnd();

    /** Returns int value of currently processed vertex. */
    int currentKey();

    /** Iterate through the entire graph. */
    void iterate();
};
