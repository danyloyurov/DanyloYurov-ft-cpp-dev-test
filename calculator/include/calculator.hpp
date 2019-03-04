#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_

#include "bookkeeper.hpp"
#include "parser.hpp"

class Calculator {
    public:
        void StartCalculation(const std::string incoming_expression);
    private:
        Bookkeeper bookkeeper_;
        Parser parser_;
};

#endif // CALCULATOR_HPP_
