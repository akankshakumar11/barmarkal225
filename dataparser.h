#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

class DataParser {
    public:
    /**
     * Reads airport data from file and creates a map whose pairs are made of strings and vectors of strings (airport names and additional data, respectively)
     * @param to_parse - name of file to parse
     * @return map of airports from file
     */
        std::map<std::string, std::vector<std::string>> makeAirportMap(const std::string& to_parse);

    /**
     * Reads route data from file and creates a 2-dimensional vector with cleaned data (only source and destination airports' codes and ids)
     * @param to_parse - name of file to parse
     * @return 2-dimensional vector of routes from file
     */
        std::vector<std::vector<std::string>> makeRouteVector(const std::string& to_parse);
    private:
    /**
     * Parses CSV files into an more organized format: a 2-dimensional vector of strings
     * @param to_parse - name of file to parse
     * @return 2-dimensional vector of strings (lines) from file
     */
        const std::vector<std::vector<std::string>> tokenizeCSV(const std::string& to_parse) const;

};
