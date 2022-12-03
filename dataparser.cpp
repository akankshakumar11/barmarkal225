#include "dataparser.h"
#include <fstream>
#include <sstream>

std::map<std::string, std::vector<std::string>> DataParser::makeAirportMap(const std::string& to_parse) {
    std::vector<std::vector<std::string>> all_airports = tokenizeCSV(to_parse);

    std::map<std::string, std::vector<std::string>> airport_map;

    for (auto& airport : all_airports) {
        std::vector<std::string> airport_data;
        std::string airport_name = airport[1]; // name
        airport_data.push_back(airport[2]); // city
        airport_data.push_back(airport[3]); // country
        airport_data.push_back(airport[4]); // code
        airport_data.push_back(airport[6]); // latitude
        airport_data.push_back(airport[7]); // longtitude
        airport_map.insert(std::pair<std::string, std::vector<std::string>> (airport_name, airport_data));
    }

    return airport_map;
    
}

std::vector<std::vector<std::string>> DataParser::makeRouteVector(const std::string& to_parse) {
    std::vector<std::vector<std::string>> all_routes = tokenizeCSV(to_parse);

    std::vector<std::vector<std::string>> route_vector_2d;

    for (auto& route : all_routes) {
        std::vector<std::string> route_data;
        route_data.push_back(route[2]); // source airport code
        route_data.push_back(route[4]); // destination airport code
        route_vector_2d.push_back(route_data);
    }
    return route_vector_2d;
}

const std::vector<std::vector<std::string>> DataParser::tokenizeCSV(const std::string& to_parse) const {
    std::vector<std::vector<std::string>> line_vector_2d = std::vector<std::vector<std::string>>();

    std::ifstream ifs (to_parse);
    std::string current_line;
    while (std::getline(ifs,current_line))
    {
        std::stringstream stream(current_line);

        std::vector<std::string> line_data;

        while(stream.good())
        {
            std::string token;
            std::getline(stream, token, ',' );
            line_data.push_back(token);
        }
        line_vector_2d.push_back(line_data);
    }

    ifs.close();
    return line_vector_2d;
}
