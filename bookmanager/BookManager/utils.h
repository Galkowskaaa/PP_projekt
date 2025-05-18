#pragma once
#include <iostream>
#include <string>
#include <algorithm>

namespace libcli {

    inline void toLowerCase(std::string& s) {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    }

    inline void clearCin() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}