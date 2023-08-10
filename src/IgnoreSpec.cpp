//
// Created by Howard Colin on 09/08/2023.
//

#include "IgnoreSpec.h"


//check for empty strings
int MHL::IgnoreSpec::check_pattern_len(std::string *pattern) {
    if(pattern->empty()) {
        return 1;
    }
    return 0;
}

// constructor loop over each item, check and add.
MHL::IgnoreSpec::IgnoreSpec(std::vector<std::string> *pattern_list) {
    for(auto &pat : *pattern_list) {
        if(check_pattern_len(&pat) == 1) {
            throw std::length_error("Pattern cannot be null");
        }
        add_pattern(&pat);
    }
}

int MHL::IgnoreSpec::add_pattern(std::string *pattern) {
    if(check_pattern_len(pattern) == 1) {
        throw std::length_error("Pattern cannot be null");
    }
    this->mIgnoreList.push_back(*pattern);
    return 0;
}

std::vector<std::string> MHL::IgnoreSpec::get_pattern_list() {
    return this->mIgnoreList;
}
