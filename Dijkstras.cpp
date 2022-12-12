#include <queue>
#include <utility>
#include <map>
#include <functional>
#include <sstream>
#include <string>
#include <iostream>

#include "dijkstras.h"
#include "graph.cpp"

Dijkstras::Dijkstras(std::vector<std::vector<std::string>> data) : graph_(true, false) {
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


std::vector<Edge> runAlgorithm(std::vector<std::vector<std::string>> data, Vertex a, Vertex b) {
    Dijkstras dijkstras = Dijkstras(data);
    return dijkstras.dijkstrasImplementation(a, b);
}


Graph Dijkstras::getGraph() {
    return graph_;
}


std::vector<Edge> Dijkstras::dijkstrasImplementation(Vertex vert1, Vertex vert2) {
    const int INFINITY = 0x3f3f3f3f;
    typedef int distance;
    typedef std::pair<distance, Vertex> distance_pairings;

    std::vector<Vertex> all_verts = graph_.getVertices();
    std::unordered_map<Vertex, distance> dist;

    for (size_t i = 0; i < all_verts.size(); i++) {
        dist[all_verts[i]] = INFINITY;
    }

    std::unordered_map<Vertex, Vertex> previous_nodes;
    std::priority_queue<distance_pairings, std::vector<distance_pairings>, std::greater<distance_pairings>> priority_q;
    dist[vert1] = 0;
    priority_q.push(make_pair(0, vert1));


    std::unordered_map<Vertex, bool> visited_so_far;
    for (size_t i = 0; i < all_verts.size(); i++) {
        visited_so_far[all_verts[i]] = false;
    }


    while (priority_q.top().second != vert2) {
        Vertex current = priority_q.top().second;
        priority_q.pop();

        std::vector<Vertex> adjacent_verts = graph_.getAdjacent(current);
        for (size_t i = 0; i < adjacent_verts.size(); i++) {

            if (visited_so_far[adjacent_verts[i]] == false) {
                Vertex adjacent = adjacent_verts[i];
                int weight = graph_.getEdgeWeight(current, adjacent);

                if (dist[adjacent] > dist[current] + weight) {
                    dist[adjacent] = dist[current] + weight;
                    previous_nodes[adjacent] = current;
                    priority_q.push(make_pair(dist[adjacent], adjacent));
                }
            } else {
                continue;
            }

        }
        visited_so_far[current] = true;
    }

    vector<Edge> shortest_path;
    Vertex curr = vert2;
    int curr_weight = 0;

    for (curr = vert2; curr != vert1; curr = previous_nodes[curr]) {
        curr_weight = graph_.getEdgeWeight(previous_nodes[curr], curr);
        std::vector<Edge>::iterator iter = shortest_path.begin();
        iter = shortest_path.insert(iter, Edge(previous_nodes[curr], curr, curr_weight, previous_nodes[curr] + "-" + curr));
    }

    return shortest_path;
}
