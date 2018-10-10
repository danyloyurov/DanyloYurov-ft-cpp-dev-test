#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

class Parser {
    public:
        std::string parseExpression(const std::string& expression);
    private:
        bool isExpressionValid() const;
        void fixExpression();
    private:
        std::string mLastExpression;
};

#endif
