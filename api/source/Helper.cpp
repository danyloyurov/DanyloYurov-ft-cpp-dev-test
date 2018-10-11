#include <sstream>
#include "Helper.hpp"

std::string Helper::getDigit(const std::string::const_iterator iter) const {
    std::string digit;

    for(auto s = iter; this->isDigit(s); s++)
        digit += *s;

    return digit;
}

bool Helper::isDigit(const std::string::const_iterator iter) const {
    if( (*iter >= '0' && *iter <= '9') || *iter == '.' )
        return true;

    return false;
}

bool Helper::isOperator(const std::string::const_iterator iter) const {
    if( ((*iter >= '*' && *iter <= '/') && *iter != '.') || *iter == '^' )
        return true;

    return false;
}
