#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>

class Helper {
    public:
        std::string getDigit(const std::string::const_iterator iter) const;
        bool isDigit(const std::string::const_iterator iter) const;
        bool isOperator(const std::string::const_iterator iter) const;
        bool isSpecialSymbol(const std::string::const_iterator iter) const;
};

#endif
