//
// Created by Howard Colin on 10/08/2023.
//

#include <iostream>

#include "../../src/ChainFile.h"

int test_chain_file() {
    fs::path sourceMHLChain = "resources/ascmhl_chain.xml";
    MHL::ChainFile ascMHLChain(sourceMHLChain);
    return 0;
}

int main() {
    return test_chain_file();
}