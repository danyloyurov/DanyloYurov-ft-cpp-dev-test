#include "calculator.hpp"

#include <iostream>

void Calculator::StartCalculation() {
    std::string file_path;
    std::string file_name;
    std::string expression;
    double calculation_result = 0.0;

    expression = parser_.ParseExpression(expression);

    if(expression == "") {
        return;
    }

    calculation_result = bookkeeper_.CalculateExpression(expression);
}
