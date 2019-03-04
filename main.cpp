#include "calculator.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    if(0 >= argc) {
        std::cout << "[TerminalCalculator::Error] where lost expression?" << std::endl;
        return 1;
    }

    std::string expression(argv[1]);
    Calculator calculator;

    calculator.StartCalculation(expression);

    return 0;
}
