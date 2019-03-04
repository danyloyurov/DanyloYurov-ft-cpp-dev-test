#include <sstream>
#include "helper.hpp"

std::string Helper::GetDigit(const std::string::const_iterator iter) const {
    std::string digit;

    for(auto s = iter; this->IsDigit(s); s++)
        digit += *s;

    return digit;
}

bool Helper::IsDigit(const std::string::const_iterator iter) const {
    if( ((*iter >= '0' && *iter <= '9') || *iter == '.') ||
        ((*iter == '-' && (*(iter + 1) >= '0' && *(iter + 1) <= '9')) && !(*(iter - 1) >= '0' && *(iter - 1) <= '9')) )
        return true;

    return false;
}

bool Helper::IsOperator(const std::string::const_iterator iter) const {
    if(*iter == '-' && this->IsDigit(iter - 1))
        return true;

    if(*iter == '-' && this->IsDigit(iter + 1))
        return false;

    if( (((*iter >= '*' && *iter <= '/') && *iter != '.') || *iter == '^'))
            return true;

    return false;
}

bool Helper::IsSpecialSymbol(const std::string::const_iterator iter) const {
    if( *iter != '(' && *iter != ')' && *iter != ' ' )
        return false;

    return true;
}
