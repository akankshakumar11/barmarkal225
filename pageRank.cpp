#include "pageRank.h"

 map<string, double> PageRank::pageRank(vector<vector<string>> routes){

    map<string, vector<string>> in_links = links(routes, 1, 0); //has vector with all the airports that have flights going into key airport
    map<string, vector<string>> out_links = links(routes, 0, 1); //has vector with all the airports that have flights going out of key airport

    map<string, vector<double>> pr; //1st element is updated rank, 2nd element is previous rank, 3rd element indicates 
                                    //whether it has already been updated in the same iteration
    double d = 0.15; 
    double num_airports = 3321; 
    for(unsigned route_index = 0; route_index < routes.size(); route_index++){
        vector<double> ranks; 
        ranks.push_back(d/num_airports);
        ranks.push_back(d/num_airports);
        ranks.push_back(-123);
        if(pr.find(routes[route_index][1]) != pr.end()) pr.insert(pair<string,vector<double>> (routes[route_index][1], ranks));
    }
    for(unsigned update = 0; update < 15; update++){
        for(unsigned i = 0; i < routes.size(); i++){
            if(pr.find(routes[i][1])->second[2] == -123){
                for(unsigned j = 0; j < in_links.find(routes[i][1])->second.size(); j++){
                    double previous_rank = pr.find(in_links.find(routes[i][1])->second[j])->second[1]; 
                    double out_degree = out_links.find(in_links.find(routes[i][1])->second[j])->second.size();
                    pr.find(routes[i][1])->second[0] += (1-d) * previous_rank/out_degree;
                    pr.find(routes[i][1])->second[2] = 1233; 
                }
            }
            
             
        }
        for(unsigned k = 0; k < routes.size(); k++){
            pr.find(routes[k][1])->second[1] = pr.find(routes[k][1])->second[0]; 
            pr.find(routes[k][1])->second[2] = -123; 
        }
    }
    map<string, double> page_ranking;
    map<string, vector<double>>::iterator it; 
    for(it = pr.begin(); it != pr.end(); it++){
        page_ranking.insert(pair<string,double> (it->first, it->second[0]));
    }
    return page_ranking;
 }

 vector<string> PageRank::ranked(map<string, vector<double>> page_rank){
   vector<string> ranked; 
   map<string, double>::iterator it; 
   for(it = page_rank.begin(); it != page_rank.end(); it++){
        ranked.push_back(it->first);
    }
    for (int i = 0; i < ranked.size() - 1; i++)
        for (int j = 0; j < ranked.size() - i - 1; j++){
            if (page_rank.find(ranked[j])->second > page_rank.find(ranked[j+1])->second){
                string temp = ranked[j];
                ranked[j] = ranked[j+1];
                ranked[j+1] = temp; 
            }
                
        }
            
    return ranked; 
    
 }
 map<string, vector<string>> links(vector<vector<string>> routes, int key_, int data_){
    map<string, vector<string>> adj_airports; 
    for(unsigned i = 0; i < routes.size(); i++){
        if(adj_airports.find(routes[i][key_]) == adj_airports.end()){
            vector<string> airport; 
            airport.push_back(routes[i][data_]);
            adj_airports.insert(pair<string,vector<string>> (routes[i][key_], airport));
        }
        else{
            adj_airports.find(routes[i][key_])->second.push_back(routes[i][data_]);
        }
        
    }
    return adj_airports; 
 }

 