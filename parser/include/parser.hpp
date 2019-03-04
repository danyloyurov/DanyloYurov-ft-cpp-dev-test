#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "helper.hpp"
#include <map>
#include <string>

class Parser {
    public:
        std::string ParseExpression(const std::string& expression);
    private:
        bool IsExpressionValid(const std::string& expression) const;
        bool IsSyntaxisValid(const std::string& expression) const;
        bool IsOperandsValid(const std::string& expression) const;
        bool IsOperatorsValid(const std::string& expression) const;
        bool IsBracketsValid(const std::string& expression) const;
        int GetOperandsCount(const std::string& expression) const;
    private:
        static const std::map<char, int> operations_priorities_;
        Helper helper_;
};

#endif // PARSER_HPP_
