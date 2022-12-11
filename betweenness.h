#pragma once

#include <vector>
#include <algorithm>
#include <string>

#include "graph.h"
#include "edge.h"

class Betweenness {
    public:
        /**
        * Creates Betweenness object
        * @param data - 2-dimensional vector of vertices
        */
        Betweenness(std::vector<std::vector<std::string>> data);

        /**
        * Returns graph
        * @return graph that Betweenness is being run on
        */
        Graph getGraph();

        /**
        * implements Betweenness centrality algorithm
        * @param g - graph to perform algorithm on
        * @param weight_attribute - empty if no weightage, otherwise is name of dataset attribute being used as weightage
        * @param endpoints - whether or not endpoints are being considered in shortest path counts
        * @return a map of nodes with betweenness centrality as the value
        */
        std::unordered_map<Node, double> BetweennessImplementation(Graph g, std::string weight_attribute, bool endpoints);
    private:
        Graph graph_;
};