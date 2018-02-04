//
// Created by Stephen on 2/4/18.
//

#include "custom_subwords.h"

CustomSubwords::CustomSubwords(std::istream&& in) {
    throw std::runtime_error("not yet impled");
}

const std::vector<std::string>& CustomSubwords::getSubwordsFor(const std::string& word) const {
    if (subword_map.find(word) != subword_map.end()) {
        return subword_map.at(word);
    } else {
        return std::vector<std::string>();
    }
}
