#include "calculator.hpp"

#include <iostream>

void Calculator::StartCalculation(const std::string incoming_expression) {
    double calculation_result = 0.0;
    std::string expression = incoming_expression;

    expression = parser_.ParseExpression(expression);

    if("" == expression) {
        std::cout << "[TerminalCalculator::Error] Parser does not understand what you want from it..." << std::endl;
        return;
    }

    calculation_result = bookkeeper_.CalculateExpression(expression);

    std::cout << "Result: " << calculation_result << std::endl;
}
