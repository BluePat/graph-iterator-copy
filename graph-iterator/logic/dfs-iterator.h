#include <stack>

#include "iterator.h"  

/** Simple implementation of depth-first search algorithm over graph. */
class DFSIterator : public Iterator {

private:

    /** A graph to iterate over. */
    Graph graph;

    /**
     * Stack used by depth-first search algorithm.
     *
     * At the top of the stack, there is a currently proccesed vertex.
     * Bellow are unprocessed known vertices.
     */
    std::stack<int> stack;

public:

    /** Constructs DFS iterator for given graph. */
    DFSIterator(Graph graph = Graph(0));

    /** Prepares an interation by placing vertex with the lowest int value onto the stack. */
    void reset();

    /**
     * Moves the iterator to the next vertex.
     *
     * The method tests if the stack is empty:
     *  a. If it is not empty, it removes current vertex and add all its uknown neighbours onto the stack.
     *  b. Otherwise uses collection of vertices `visited` to find (if any) unprocessed vertex and puts it onto the stack.
     */
    void next();

    /** Returns true if all verticis have been visited. */
    bool isEnd();

    /** Returns int value of currently processed vertex. */
    int currentKey();

    /** Iterate through the entire graph. */
    void iterate();
};
