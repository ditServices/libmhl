//
// Created by Howard Colin on 09/08/2023.
//

#include "Utils.h"

#define BASE_YEAR 1900
#define BASE_MONTH 1

std::string MHL::Utils::get_year() {
    return std::to_string(BASE_YEAR + this->mLtm->tm_year);
}

std::string MHL::Utils::get_month() {
    return std::to_string(BASE_MONTH + this->mLtm->tm_mon);
}

std::string MHL::Utils::get_day() {
    return std::to_string(this->mLtm->tm_mday);
}

std::array<std::string, 3> MHL::Utils::get_time() {
    std::array<std::string, 3> current_time;
    current_time[0] = std::to_string(this->mLtm->tm_hour);
    current_time[1] = std::to_string(this->mLtm->tm_min);
    current_time[2] = std::to_string(this->mLtm->tm_sec);
    return current_time;
}

