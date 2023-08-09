//
// Created by Howard Colin on 09/08/2023.
//

#include <iostream>

#include "../../src/IgnoreSpec.h"

int create_ignorelist(std::vector<std::string> *patterns) {
    try {
        MHL::IgnoreSpec spec(patterns);
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

int main() {
    std::vector<std::string> pats;
    pats.emplace_back(".DS_Store");
    pats.emplace_back("ascmhl");
    pats.emplace_back("");

    return create_ignorelist(&pats);
}