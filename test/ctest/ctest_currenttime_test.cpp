//
// Created by Howard Colin on 09/08/2023.
//

#include <iostream>

#include "../../src/Utils.h"

int test_current_time() {
   MHL::CurrentTime now = MHL::get_current_time();
   std::cout << now.mLtm->tm_hour << now.mLtm->tm_min << now.mLtm->tm_sec << std::endl;
    return 0;
}

int main() {
    return test_current_time();
}