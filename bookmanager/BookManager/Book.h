#pragma once
#include <string>

namespace libcli {

    using Pages = unsigned;

    struct Book {
        std::string title;
        std::string author;
        int rok;
        Pages pages;
    };

}