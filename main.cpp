#include "dataparser.cpp"
#include <cassert>
#include "BFS.cpp"
#include "Dijkstras.cpp"
#include "pageRank.cpp"
#include <vector>
#include <iostream>

using namespace std;

void run_bfs(Vertex source, Vertex dest) {
    std::cout << "Running BFS Implementation:" << std::endl;

    int bfs_tests = 0;

    DataParser d;

    
    std::map<std::string, std::vector<std::string>> airport_map = d.makeAirportMap("airports.dat.csv");
    std::vector<std::vector<std::string>> route_vector_2d = d.makeRouteVector("routes.dat.csv");

    std::vector<Vertex> vertices;

    for (const auto &curr : airport_map) {
        vertices.push_back(curr.second[2]);
    }

    BFS bfs(vertices, source);

    for (auto& a : route_vector_2d) {
        bfs.addEdge(Edge(a[0], a[1]));
    }

    // bfs.startBFS();
    bfs.slowBFS();
    bfs.slowBFS();


    int airport_num = 1;

    while (!bfs.getQueue().empty()) {
        std::cout << "Airport #" << airport_num << ": " << bfs.front() << std::endl;
        airport_num++;
        bfs.pop();
    }


    std::cout << std::endl;

    BFS bfs2(vertices, source);


    for (size_t i = 0; i < route_vector_2d.size(); i++) {
        bfs2.addEdge(Edge(route_vector_2d[i][0], route_vector_2d[i][1]));
    }

    int min_path_length = route_vector_2d.size();
    int curr_path_length = 0;

    while ((curr_path_length = bfs2.findBFS(source, dest)) > 1) {
        if (curr_path_length < min_path_length) {
            min_path_length = curr_path_length;
        }
        // std::cout << std::endl;
        // std::cout << std::endl;
    }
    std::cout << "Number of Flights in Shortest Path Trip (BFS):" << std::endl;
    std::cout << min_path_length << std::endl;

    std::cout << "Number of layovers:" << std::endl;
    std::cout << min_path_length - 1 << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

}

void run_dijkstras(Vertex source, Vertex dest) {
    std::cout << "Running Dijkstra's algorithm on " << source << " --> " << dest << ":" << std::endl;


    DataParser d;
    std::vector<std::vector<std::string>> route_vector_2d = d.makeRouteVector("routes.dat.csv");

    Dijkstras test_1 = Dijkstras(route_vector_2d);
    Graph graph_1 = test_1.getGraph();

    vector<Edge> path_1 = test_1.dijkstrasImplementation(source, dest);

    std::cout << "You need to take at least " << path_1.size() << " flights to get from " << source << " to " << dest << ":" << std::endl;



    std::cout << std::endl;
}


void page_rank_test(){
    DataParser d;
    PageRank p;
    vector<vector<string>> route_vector_2d = d.makeRouteVector("routes.dat.csv");
    map<string, vector<double>> page_rank = p.pageRank(route_vector_2d); 


    
    //print out ranking 
    // map<string, vector<double>>::iterator it; 
    // for(it = page_rank.begin(); it != page_rank.end(); it++){ //iteration through map
    //     cout << "airport: " << it->first << " ranking:  " << it->second[0] << endl; 
    // }

    std::vector<string> pr = p.ranked(page_rank);

            // std::cout << page_rank.size() << std::endl;

    std::cout << "Top 10 Most Popular Airports (using PageRank): " << std::endl; 
    for(unsigned i = 0; i < 10; i++){
        std::cout << i+1 << ". " <<  pr[pr.size() - i - 1] << std::endl; 
    }
}

int main(int argc, char** argv) {
    run_bfs(argv[1], argv[2]);
    run_dijkstras(argv[1], argv[2]);
    page_rank_test();
    return argc;
}
