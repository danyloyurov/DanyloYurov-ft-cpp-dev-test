#ifndef HELPER_HPP_
#define HELPER_HPP_

#include <string>

class Helper {
    public:
        std::string GetDigit(const std::string::const_iterator iter) const;
        bool IsDigit(const std::string::const_iterator iter) const;
        bool IsOperator(const std::string::const_iterator iter) const;
        bool IsSpecialSymbol(const std::string::const_iterator iter) const;
};

#endif // HELPER_HPP_
