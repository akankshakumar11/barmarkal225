#include "pageRank.h"

 map<string, vector<double>> PageRank::pageRank(vector<vector<string>> routes){

    map<string, vector<string>> in_links = links(routes, 1, 0); //has vector with all the airports that have flights going into key airport
    map<string, vector<string>> out_links = links(routes, 0, 1); //has vector with all the airports that have flights going out of key airport

    map<string, vector<double>> pr; //1st element is updated rank, 2nd element is previous rank, 3rd element indicates 
                                    //whether it has already been updated in the same iteration
    double d = 0.15; //damping factor
    double num_airports = 3418; //3321; //total number of airports
    for(unsigned route_index = 0; route_index < routes.size(); route_index++){ //initialize map to have the inital rankings
        vector<double> ranks; 
        ranks.push_back(d/num_airports); //initial ranking should be damping factor divided by number of airports
        ranks.push_back(d/num_airports);
        ranks.push_back(-123); //-123 means that it hasn't been updated in same iteration 
        if(pr.find(routes[route_index][1]) == pr.end()) {
            pr.insert(pair<string,vector<double>> (routes[route_index][1], ranks)); //insert for each unique airport
        }


    }

    for(unsigned update = 0; update < 15; update++){ //15 iterations for pageRank 
        map<string, vector<double>>::iterator it;
        for(unsigned i = 0; i < routes.size(); i++){ //iterate through all routes
        
            // if (i >= 67662) {
            //             std::cout << routes[i].size() << endl;
            // }
            // std::cout << routes[i][1] << std::endl;
            it = pr.find(routes[i][1]);
                        // std::cout << routes[i][1] << std::endl;

            if (it == pr.end())  {
                continue;
            }
            if(it->second[2] == -123){ //check if the airports rank hasn't been updated yet in this iteration
                for(unsigned j = 0; j < in_links.find(routes[i][1])->second.size(); j++){ // go through all the flights going into destination airport
                    double previous_rank = pr.find(in_links.find(routes[i][1])->second[j])->second[1]; // find the previous iteration's rank
                    double out_degree = out_links.find(in_links.find(routes[i][1])->second[j])->second.size(); //count the number of planes leaving that specific airport
                    it->second[0] += (1-d) * previous_rank/out_degree; //update rank
                    it->second[2] = 1233; //rank has been updated in this iteration already
                }
            }
        }
        for(unsigned k = 0; k < routes.size(); k++){  //go through all the routes
            it = pr.find(routes[k][1]);

            if (it != pr.end())  {
                // if (it->second.size() >= 3) {
                    it->second[1] = it->second[0];  //previous rank = current rank
                    it->second[2] = -123;
                // }
                
            }
        }
    }
    // map<string, double> page_ranking; //map to return 
    // map<string, vector<double>>::iterator it; 
    // for(it = pr.begin(); it != pr.end(); it++){ //iteration through map
    //     page_ranking.insert(pair<string,double> (it->first, it->second[0])); //insert just the airport with it's ranking 
    // }
    // return page_ranking;

    return pr;
 }

 vector<string> PageRank::ranked(map<string, vector<double>> page_rank){ //rank all the airports using a vector 
   vector<string> ranked; 
   map<string, vector<double>>::iterator it; 
   for(it = page_rank.begin(); it != page_rank.end(); it++){ //add all airports into vector
        ranked.push_back(it->first);
    }
    //bubble sort 
    // std::cout << ranked.size();
    // return ranked;
    for (int i = 0; i < ranked.size() - 1; i++){ 
        // if (i > 1000) {
        //         break;
        //     }
        for (int j = 0; j < ranked.size() - i - 1; j++){
            // std::cout << i << ", " << j<< std::endl;
            // if (j > 1000) {
            //     break;
            // }

            map<string, vector<double>>::iterator it1 = page_rank.find(ranked[j]);
            map<string, vector<double>>::iterator it2 = page_rank.find(ranked[j+1]);
            if (it1 == page_rank.end()) {
                continue;
            }
            if (it2 == page_rank.end()) {
                continue;
            }
            if (it1->second > it2->second){
                string temp = ranked[j];
                ranked[j] = ranked[j+1];
                ranked[j+1] = temp; 
            }
                
        }

    }
        
            
    return ranked; //ranking of airports in order 
    
 }

 map<string, vector<string>> PageRank::links(vector<vector<string>> routes, int key_, int data_){ //creates map with vector of all src or dest aiports for a single airport 
    map<string, vector<string>> adj_airports; //map to return 
    for(unsigned i = 0; i < routes.size(); i++){ //go through all routes
        if(adj_airports.find(routes[i][key_]) == adj_airports.end()){ //if airport not already in map
            vector<string> airport; //create vector
            airport.push_back(routes[i][data_]); //add the first airport to the vector 
            adj_airports.insert(pair<string,vector<string>> (routes[i][key_], airport)); //insert
        }
        else{
            adj_airports.find(routes[i][key_])->second.push_back(routes[i][data_]); //add airport to vector 
        }
        
    }
    return adj_airports; 
 }

 
