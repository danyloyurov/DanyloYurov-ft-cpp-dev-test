#include "Calculator.hpp"
#include "UIPainter.hpp"

#include <iostream>

void Calculator::startCalculation() {
    bool isFileOpened = false;

    std::string file_path;
    std::string file_name;
    std::string expression;
    double calculation_result = 0.0;

    std::cout << "Enter expression file path (example: \"~/expressions/\"): ";
    getline(std::cin, file_path);
    std::cout << "Enter expression file name (example: \"expression.txt\"): ";
    getline(std::cin, file_name);

    isFileOpened = mFileManager.readFile(file_path, file_name, expression);

    if( !isFileOpened ) {
        UIPainter::Instance().showMessage("File does not exist!");
        return;
    }

    expression = mParser.parseExpression(expression);

    if(expression == "") {
        UIPainter::Instance().showMessage("Incorrect syntaxis of expression!");
        return;
    }

    calculation_result = mBookkeeper.calculateExpression(expression);

    UIPainter::Instance().showMessage(std::to_string(calculation_result));
}
