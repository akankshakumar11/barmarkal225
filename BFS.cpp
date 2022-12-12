#include "BFS.h"
#include <queue>
#include <vector>


BFS::BFS(std::vector<Vertex> vect, Vertex start) {
    adj_verts_ = std::map<Vertex, std::vector<Vertex>>();
    is_visited_ = std::map<Vertex, bool>();
    bfs_queue_.push(start);

    for (Vertex v : vect) {
        verts_.push_back(v);
    }

    for (Vertex v2 : verts_) {
        is_visited_[v2] = false;
    }

    is_visited_[start] = true;
}


BFS::BFS(std::vector<Vertex> vect, std::vector<Edge> edge, Vertex start) {
    adj_verts_ = std::map<Vertex, std::vector<Vertex>>();
    is_visited_ = std::map<Vertex, bool>();
    bfs_queue_.push(start);

    for (Vertex v : vect) {
        verts_.push_back(v);
    }

    for (Edge e : edge) {
        adj_verts_[e.source].push_back(e.dest);
        adj_verts_[e.dest].push_back(e.source);
    }

    for (Vertex v2 : verts_) {
        is_visited_[v2] = false;
    }

    is_visited_[start] = true;
}


BFS::~BFS() {
    std::queue<Vertex> empty;
    std::swap(bfs_queue_, empty);
    is_visited_.clear();
    adj_verts_.clear();
    verts_.clear();
}


void BFS::addEdge(Vertex vert1, Vertex vert2) {
    adj_verts_[vert1].push_back(vert2);
    adj_verts_[vert2].push_back(vert1);
}


void BFS::addEdge(Edge edge) {
    adj_verts_[edge.source].push_back(edge.dest);
    adj_verts_[edge.dest].push_back(edge.source);
}


void BFS::pop() {
    bfs_queue_.pop();
}


Vertex BFS::front(){
    return bfs_queue_.front();
}


void BFS::startBFS() {
    std::list<int>::iterator iter;

    while (!bfs_queue_.empty()) {
        Vertex v = bfs_queue_.front();
        bfs_queue_.pop();

        for (Vertex iter : adj_verts_[v]) {
            if (is_visited_[iter] == false) {
                is_visited_[iter] = true;
                bfs_queue_.push(iter);
            }
        }
    }
}


Vertex BFS::slowBFS() {
    std::list<int>::iterator i;

    while (!bfs_queue_.empty()) {
        Vertex v = bfs_queue_.front();
        for (Vertex iter : adj_verts_[v]) {
            if (is_visited_[iter] == false) {
                bfs_queue_.push(iter);
                is_visited_[iter] = true;
                return iter;
            }
        }

        bfs_queue_.pop();
    }

    return NULL;
}

bool BFS::queue_empty() {
    return bfs_queue_.empty();
}

int BFS::size() {
    return bfs_queue_.size();
}

std::string BFS::display_vertices() {
    string to_return = "";
    for (Vertex v : verts_) {
        to_return += v + " ";
    }
    return to_return;
}


std::string BFS::display_edges(Vertex vert) {
    string to_return = "";
    for (Vertex v : adj_verts_[vert]) {
        to_return += vert + " goes to " + v + " ";
    }
    return to_return;
}
