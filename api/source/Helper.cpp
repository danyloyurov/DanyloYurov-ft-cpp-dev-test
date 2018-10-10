#include <sstream>
#include "Helper.hpp"

std::string Helper::getDigit(const std::string::const_iterator iter) const {
    std::string digit;

    for(auto s = iter; (*s >= '0' && *s <= '9') || *s == '.'; s++)
        digit += *s;

    return digit;
}

bool Helper::isDigit(const std::string::const_iterator iter) const {
    if(*iter >= '0' && *iter <= '9')
        return true;

    return false;
}
