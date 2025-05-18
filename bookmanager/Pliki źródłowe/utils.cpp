#include "utils.h"
#include <algorithm>

namespace libcli {

    void toLowerCase(std::string& s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    }

}
