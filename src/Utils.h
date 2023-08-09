//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_UTILS_H
#define LIBMHL_UTILS_H

// time and date helper functions

#include <ctime>
#include <string>
#include <array>

namespace MHL {

    class Utils {
    private:
        time_t mNow = time(nullptr);
        tm *mLtm = localtime(&mNow);
    public:
        std::string get_year();
        std::string get_month();
        std::string get_day();
        std::array<std::string, 3> get_time();
    };
}

#endif //LIBMHL_UTILS_H
