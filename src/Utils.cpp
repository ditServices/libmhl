//
// Created by Howard Colin on 09/08/2023.
//

#include "Utils.h"

#include <sys/utsname.h>

#define BASE_YEAR 1900
#define BASE_MONTH 1

MHL::CurrentTime MHL::get_current_time() {
    CurrentTime cTime;
    return cTime;
}

std::array<std::string, 3> current_time_as_string(MHL::CurrentTime &current_time) {
    std::array<std::string, 3> sTime;
    sTime[0] = std::to_string(current_time.mLtm->tm_hour);
    sTime[1] = std::to_string(current_time.mLtm->tm_min);
    sTime[2] = std::to_string(current_time.mLtm->tm_sec);
    return sTime;
}

std::array<std::string, 3> current_date_as_string(MHL::CurrentTime &current_time) {
    std::array<std::string, 3> sDate;
    sDate[0] = std::to_string(current_time.mLtm->tm_mday);
    sDate[1] = std::to_string(BASE_MONTH + current_time.mLtm->tm_mon);
    sDate[2] = std::to_string(BASE_YEAR + current_time.mLtm->tm_year);
    return sDate;
}

MHL::ClientDetails MHL::get_client_details() {
    ClientDetails cDetails;
    cDetails.mUserName = getenv("USER");
    int res = uname(&cDetails.mHostDetails);
    return cDetails;
}



