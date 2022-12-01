#include "dataparser.cpp"
#include <cassert>

int airport_map() {
    int airport_tests = 0;
    DataParser d;
    std::map<std::string, std::vector<std::string>> airport_map = d.makeAirportMap("airports.dat.csv");

    // look for CMI
    if (airport_map.find("\"University of Illinois Willard Airport\"")->second[2].compare("\"CMI\"") == 0) {
        std::cout << "CMI found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! CMI not found in airport map!" << std::endl;
    }

    // look for HAM
    if (airport_map.find("\"Hamburg Airport\"")->second[2].compare("\"HAM\"") == 0) {
        std::cout << "HAM found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! HAM not found in airport map!" << std::endl;
    }

    // look for SIN
    if (airport_map.find("\"Singapore Changi Airport\"")->second[2].compare("\"SIN\"") == 0) {
        std::cout << "SIN found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! SIN not found in airport map!" << std::endl;
    }

    // look for PER
    if (airport_map.find("\"Perth International Airport\"")->second[2].compare("\"PER\"") == 0) {
        std::cout << "PER found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! PER not found in airport map!" << std::endl;
    }

    // look for NBO
    if (airport_map.find("\"Jomo Kenyatta International Airport\"")->second[2].compare("\"NBO\"") == 0) {
        std::cout << "NBO found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! NBO not found in airport map!" << std::endl;
    }

    // look for TFF
    if (airport_map.find("\"Tefé Airport\"")->second[2].compare("\"TFF\"") == 0) {
        std::cout << "TFF found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! TFF not found in airport map!" << std::endl;
    }

    // look for LEQ
    if (airport_map.find("\"Land's End Airport\"")->second[2].compare("\"LEQ\"") == 0) {
        std::cout << "LEQ found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! LEQ not found in airport map!" << std::endl;
    }

    // look for KEW
    if (airport_map.find("\"Keewaywin Airport\"")->second[2].compare("\"KEW\"") == 0) {
        std::cout << "KEW found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! KEW not found in airport map!" << std::endl;
    }

    // look for FYN
    if (airport_map.find("\"Fuyun Koktokay Airport\"")->second[2].compare("\"FYN\"") == 0) {
        std::cout << "FYN found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! FYN not found in airport map!" << std::endl;
    }

    // look for PYK
    if (airport_map.find("\"Payam International Airport\"")->second[2].compare("\"PYK\"") == 0) {
        std::cout << "PYK found in airport map!" << std::endl;
        airport_tests++;
    } else {
        std::cout << "Oh man! PYK not found in airport map!" << std::endl;
    }
    return airport_tests;
}

int route_vector_2d() {
    int route_tests = 0;
    DataParser d;
    std::vector<std::vector<std::string>> route_vector_2d = d.makeRouteVector("routes.dat.csv");

    bool fake_route = true;

    // look for several routes
    for (size_t i = 0; i < route_vector_2d.size(); i++) {
        // route from YGL to YGW
        if (route_vector_2d[i][0].compare("YGL") == 0 && route_vector_2d[i][1].compare("YGW") == 0)  {
            std::cout << "Route from YGL to YGW exists" << std::endl;
            route_tests++;
        }
        // route from NBC to SVX
        if (route_vector_2d[i][0].compare("NBC") == 0 && route_vector_2d[i][1].compare("SVX") == 0)  {
            std::cout << "Route from NBC to SVX exists" << std::endl;
            route_tests++;
        }
        // route from UUA to LED
        if (route_vector_2d[i][0].compare("UUA") == 0 && route_vector_2d[i][1].compare("LED") == 0)  {
            std::cout << "Route from UUA to LED exists" << std::endl;
            route_tests++;
        }
        // route from KGD to EGO
        if (route_vector_2d[i][0].compare("KGD") == 0 && route_vector_2d[i][1].compare("EGO") == 0)  {
            std::cout << "Route from KGD to EGO exists" << std::endl;
            route_tests++;
        }
        // route from ASF to KZN
        if (route_vector_2d[i][0].compare("ASF") == 0 && route_vector_2d[i][1].compare("KZN") == 0)  {
            std::cout << "Route from ASF to KZN exists" << std::endl;
            route_tests++;
        }

        // route from JFK to JFK (should not exist!)
        if (route_vector_2d[i][0].compare("JFK") == 0 && route_vector_2d[i][1].compare("JFK") == 0)  {
            std::cout << "Route from JFK to JFk exists (test failed!!!)" << std::endl;
            fake_route = false;
        }
        
    }

    if (fake_route) {
        std::cout << "Route from JFK to JFk does not exist (test passed!!!)" << std::endl;
        route_tests++;
    }

    return route_tests;
}

int main() {
    int tests_passed = airport_map() + route_vector_2d();
    std::cout << tests_passed << " out of 16 tests passed!" << std::endl;
    return -1;
}
