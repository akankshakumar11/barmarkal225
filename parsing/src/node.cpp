#include "../include/node.h"

using std::string;

namespace Parser {
    unsigned Node::num_nodes_;
    
    Node::Node(string data) {
        id_ = num_nodes_++;
        data_ = data;
    }

    Node::~Node() {
        num_nodes_--;
    }

    unsigned Node::getID() {
        return id_;
    }

    string Node::getData() {
        std::string s = data_;
        std::string delimiter = ",";
        std::map<std::string, int> m;

        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            std::cout << token << std::endl;
//             if (!(m.count(token))) {
//                 m.insert(std::pair<std::string,int>('a',100));
//             }
            s.erase(0, pos + delimiter.length());
        }
            return data_;
    }
}
