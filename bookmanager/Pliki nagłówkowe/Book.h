#pragma once
#include <string>

namespace libcli {

    struct Book {
        std::string title;
        std::string author;
        unsigned int year;
        unsigned int pages;
    };

}
