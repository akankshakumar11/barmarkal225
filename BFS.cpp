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
    while (!bfs_queue_.empty()) {
        bfs_queue_.pop();
    }
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

void BFS::push(Vertex v) {
    bfs_queue_.push(v);
    is_visited_[v] = true;
}


Vertex BFS::front(){
    return bfs_queue_.front();
}

std::queue<Vertex> BFS::getQueue(){
    return bfs_queue_;
}


void BFS::startBFS() {
    std::list<int>::iterator i;

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

int BFS::findBFS(Vertex source, Vertex dest) {
    std::list<int>::iterator i;
    int counter = 1;

    while (!bfs_queue_.empty()) {
        Vertex v = bfs_queue_.front();
        //std::cout << v << " --> ";
        bfs_queue_.pop();

        for (Vertex iter : adj_verts_[v]) {
            if (is_visited_[iter] == false) {
                is_visited_[iter] = true;
                //std::cout << iter << " --> ";
                bfs_queue_.push(iter);
                counter++;
                if (iter == dest) {
                    unvisit(dest);
                    bfs_queue_.pop();
                    bfs_queue_.push(source);
                    return counter;
                }

            }
        }
    }
    unvisit(dest);
    bfs_queue_.pop();
    bfs_queue_.push(source);
    return counter;
}

void BFS::unvisit(Vertex v) {
    is_visited_[v] = false;
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
