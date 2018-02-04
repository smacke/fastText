//
// Created by Stephen on 2/4/18.
//

#ifndef FASTTEXT_CUSTOM_SUBWORDS_H
#define FASTTEXT_CUSTOM_SUBWORDS_H


#include <string>
#include <vector>
#include <map>

class CustomSubwords {
public:
    explicit CustomSubwords(std::istream&& in);
    const std::vector<std::string>& getSubwordsFor(const std::string& word) const;
protected:
    std::map<const std::string, std::vector<std::string>> subword_map;
};


#endif //FASTTEXT_CUSTOM_SUBWORDS_H
