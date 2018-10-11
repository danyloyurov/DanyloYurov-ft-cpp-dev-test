#ifndef PARSER_HPP
#define PARSER_HPP

#include "Helper.hpp"
#include <map>
#include <string>

class Parser {
    public:
        std::string parseExpression(const std::string& expression);
    private:
        bool isExpressionValid(const std::string& expression) const;
        bool isOperandsValid(const std::string& expression) const;
        bool isOperatorsValid(const std::string& expression) const;
        bool isBracketsValid(const std::string& expression) const;
        int getOperandsCount(const std::string& expression) const;
    private:
        static const std::map<char, int> mOperationsPriorities;
        Helper mHelper;
};

#endif
