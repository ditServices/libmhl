//
// Created by Howard Colin on 10/08/2023.
//
//
// Created by Howard Colin on 09/08/2023.
//

#include <iostream>

#include "../../src/Utils.h"

int test_host_details() {
   MHL::ClientDetails cDetails = MHL::get_client_details();
   std::cout << cDetails.mUserName << " " << cDetails.mHostDetails.nodename << std::endl;
    return 0;
}

int main() {
    return test_host_details();
}