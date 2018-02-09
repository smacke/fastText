//
// Created by Stephen on 2/4/18.
//

#include <sstream>
#include "custom_subwords.h"

CustomSubwords::CustomSubwords(std::istream&& in) {
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        if (!iss.good()) continue;
        std::string key;
        getline(iss, key, ',');
        if (!iss.good()) {
            throw std::runtime_error("malformed input");
        }
        std::vector<std::string> subwords;
        std::string subword;
        while (iss.good()) {
            getline(iss, subword, ',');
            subwords.push_back(subword);
        }
        subword_map[key] = subwords;
    }
}

const std::vector<std::string>& CustomSubwords::getSubwordsFor(const std::string& word) const {
    if (subword_map.find(word) != subword_map.end()) {
        return subword_map.at(word);
    } else {
        return empty_vector;
    }
}
