//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_UTILS_H
#define LIBMHL_UTILS_H

// time and date helper functions

#include <ctime>
#include <string>
#include <array>
#include <sys/utsname.h>

namespace MHL {
    const int MAX_HN_LEN = 255;

    typedef struct CurrentTime {
        time_t mNow = time(nullptr);
        tm *mLtm = localtime(&mNow);
    } CurrentTime;

    typedef struct ClientDetails {
        struct utsname mHostDetails{};
        const char *mUserName = nullptr;
    } ClientDetails;

    CurrentTime get_current_time();
    std::array<std::string, 3> current_time_as_string(CurrentTime &current_time);
    std::array<std::string, 3> current_date_as_string(CurrentTime &current_time);
    ClientDetails get_client_details();
}

#endif //LIBMHL_UTILS_H
