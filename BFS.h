
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "graph.h"
#include "edge.h"

class BFS
{
public:
    /**
     * Creates BFS object
     * @param vect - 2-dimensional vector of vertices
     * @param start - starting vertex
    */
    BFS(std::vector<Vertex> vect, Vertex start);

    /**
     * Creates BFS object
     * @param vect - 2-dimensional vector of vertices
     * @param edges - 2-dimensional vector of edges
     * @param start - starting vertex
    */
    BFS(std::vector<Vertex> vect, std::vector<Edge> edge, Vertex start);

    /**
     * Destroys BFS object
    */
    ~BFS();

    /**
     * Adds edge between two vertices
     * @param vert1 - starting vertex
     * @param vert2 - ending vertex
    */
    void addEdge(Vertex vert1, Vertex vert2);

    /**
     * Adds edge
     * @param edge - edge to add
    */
    void addEdge(Edge edge);

    /**
     * Pops vertex at the front of the queue
    */
    void pop();

     /**
     * Returns vertex at the front of the queue
     * @return vertex at the front of the queue
    */
    Vertex front();
    
    /**
     * Starts the BFS traversal
    */
    void startBFS();

    /**
     * Conducts BFS slowly
     * @return next vertex in the  (technically null)
    */
    Vertex slowBFS();

    /**
     * Displays vertices in current BFS
     * @return vertices in order
    */
    std::string display_vertices();

    /**
     * Displays edges in current BFS
     * @return edges in order
    */
    std::string display_edges(Vertex vert);

    std::queue<Vertex> getQueue();

private:
    /* Vector of vertices */
    std::vector<Vertex> verts_;

    /* Map whose pairs are of form (vertex, vector of adjacent vertices) */
    std::map<Vertex, std::vector<Vertex>> adj_verts_;

    /* Queue of vertices to visit during the BFS traversal */
    std::queue<Vertex> bfs_queue_;

    /* Map whose pairs are of form (vertex, bool indicating whether or not the vertex has been visited) */
    std::map<Vertex, bool> is_visited_;
};
