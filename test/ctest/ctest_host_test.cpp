//
// Created by Howard Colin on 10/08/2023.
//
//
// Created by Howard Colin on 09/08/2023.
//

#include <iostream>

#include "../../src/Utils.h"

int test_host_details() {
    try {
        MHL::Utils utilHelper;
        std::cout << utilHelper.mHostDetails.nodename << std::endl;
        std::cout << utilHelper.mHostDetails.release<< std::endl;
        std::cout << utilHelper.mHostDetails.version << std::endl;
        std::cout << utilHelper.mUserName << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
    return 0;
}

int main() {
    return test_host_details();
}