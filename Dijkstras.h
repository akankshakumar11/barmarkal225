#pragma once

#include <vector>
#include <algorithm>
#include <string>

#include "graph.h"
#include "edge.h"

class Dijkstras {
    public:
        /**
        * Creates Dijkstras object
        * @param data - 2-dimensional vector of vertices
        */
        Dijkstras(std::vector<std::vector<std::string>> data);

        //Main Dijkstras function, condenses the helper functions
        std::vector<Edge> runAlgorithm(std::vector<std::vector<std::string>> data, Vertex a, Vertex b);

        /**
        * Returns graph
        * @return graph that Dijkstra's is being run on
        */
        Graph getGraph();

        /**
        * Finds shortest path between two vertices by implementing Dijkstra's algorithm
        * @param vert1 - vertex to start path from
        * @param vert2 - vertex to end path at
        * @return a vector of edges containing the path between the two given vertices
        */
        std::vector<Edge> dijkstrasImplementation(Vertex vert1, Vertex vert2);
    private:
        Graph graph_;
};