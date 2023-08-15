//
// Created by Howard Colin on 10/08/2023.
//

#include <iostream>

#include "../../src/ChainFile.h"
#include "pugixml.hpp"

int test_chain_file() {
    fs::path sourceMHLChain = "resources/ascmhl_chain.xml";
    try {
        MHL::ChainFile ascMHLChain(sourceMHLChain);
    } catch(std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int main() {
    return test_chain_file();
}