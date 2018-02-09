//
// Created by Stephen on 2/4/18.
//

#include <sstream>
#include <iostream>
#include "custom_subwords.h"

CustomSubwords::CustomSubwords(std::istream&& in) {
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        if (!iss.good()) continue;
        std::string key;
        std::getline(iss, key, ',');
        if (!iss.good()) {
            throw std::runtime_error("malformed input");
        }
        std::vector<std::string> subwords;
        std::string subword;
        while (iss.good()) {
            std::getline(iss, subword, ',');
            subwords.push_back(subword);
        }
        subword_map[key] = subwords;
    }
}

const std::vector<std::string>& CustomSubwords::getSubwordsFor(const std::string& word) const {
    if (subword_map.find(word) != subword_map.end()) {
        return subword_map.at(word);
    } else {
        std::cerr << "warning: no subwords found for " << word << std::endl;
        return empty_vector;
    }
}
