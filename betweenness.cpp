#include "betweenness.h"
#include "graph.h"
#include <queue>
#include <utility>
#include <map>
#include <functional>
#include <sstream>
#include <string>
#include <iostream>

Betweenness::Betweenness(std::vector<std::vector<std::string>> data) : graph_(true, false) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (graph_.vertexExists(data[i][0]) == false) {
            graph_.insertVertex(data[i][0]);
        }

        if (graph_.vertexExists(data[i][1]) == false) {
            graph_.insertVertex(data[i][1]);
        }

        if (graph_.edgeExists(data[i][0], data[i][1]) == false) {
            graph_.insertEdge(data[i][0], data[i][1]);
            graph_.setEdgeWeight(data[i][0], data[i][1], 1);
        }
    }
}

Graph Betweenness::getGraph() {
    return graph_;
}

std::unordered_map<Node, double> Betweenness::BetweennessImplementation(Graph g, std::string weight_attribute, bool endpoints) {
    std::unordered_map<Node, double> betweenness;
    std::vector<Node> nodes;
    for (const auto& elem : g) {
        betweenness[elem] = 0.0;
        nodes.push_back(elem);
    }
    
    for (const auto& n : nodes) {
        if (weight_attribute == "") {
            // bfs            
        } else {
            // djikstra
        }

        if (endpoints) {

        } else {
            
        }
    }

    return betweenness;
}