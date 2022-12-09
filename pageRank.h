#include <map>
#include <vector>
#include <string>
using namespace std; 

class PageRank {
    public:
    /**
     * Takes in directed graph of airports and returns a map with a ranking for each airport 
     * @param routes - 2d vector with route data (in each row, 1st element is src and 2nd is dest)
     * @return map of airports with ranking
     */
        map<string, double> pageRank(vector<vector<string>> routes);

    /**
     * Takes in directed graph of airports and returns a vector with the airports ranked 
     * @param routes - 2d vector with route data (in each row, 1st element is src and 2nd is dest)
     * @return vector with airports ranked 
     */
        vector<string> ranked(map<string, vector<double>> page_rank);

    /**
     * creates a map with the destination airport as the key and vector of the source airports as the data
     * @param routes - 2d vector with route data (in each row, 1st element is src and 2nd is dest)
     * @param key_ either 0 (source), or 1 (dest)
     * @param data_ either 0 (source), or 1 (dest)
     * @return vector with airports ranked 
     */
        map<string, vector<string>> links(vector<vector<string>> routes, int key_, int data_);
    private:
    

};