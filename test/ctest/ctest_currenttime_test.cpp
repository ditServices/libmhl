//
// Created by Howard Colin on 09/08/2023.
//

#include <iostream>

#include "../../src/Utils.h"

int test_current_time() {
    MHL::Utils mTime;
    std::cout << mTime.get_day() << " " << mTime.get_month() << " " << mTime.get_year()<< " " << std::endl;
    std::array<std::string, 3> current_time = mTime.get_time();
    std::cout << current_time[0] << ":" << current_time[1] << ":" << current_time[2] << std::endl;
    return 0;
}

int main() {
    return test_current_time();
}