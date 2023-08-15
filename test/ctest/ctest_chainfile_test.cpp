//
// Created by Howard Colin on 10/08/2023.
//

#include <iostream>

#include "../../src/ChainFile.h"
#include "pugixml.hpp"
#include <sstream>

int test_chain_file() {
    fs::path sourceMHLChain = "resources/ascmhl_chain.xml";
    try {
        MHL::ChainFile ascMHLChain(sourceMHLChain);
        pugi::xml_node ascChainFile = ascMHLChain.get_first_node();
        std::cout << ascChainFile.name() << std::endl;

        pugi::xml_node hashEntry = ascChainFile.first_child();
        std::cout << hashEntry.name() << std::endl;
    } catch(std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int main() {
    return test_chain_file();
}