#include "bookkeeper.hpp"

#include <stack>

double Bookkeeper::CalculateExpression(const std::string& expression) const {
    std::stack<double> operands;

    for(auto iter = expression.begin(); iter < expression.end(); iter++) {

        if( helper_.IsDigit( iter ) ) {
            std::string operand = helper_.GetDigit( iter );
            operands.push( std::stof(operand) );
            iter += (operand.length() - 1);
        } else {
            if(*iter == ',')
                continue;

            double secondOperand = operands.top();
            operands.pop();
            double firstOperand = operands.top();
            operands.pop();

            switch(*iter) {
                case '+':
                    operands.push( firstOperand + secondOperand );
                    break;
                case '-':
                    operands.push( firstOperand - secondOperand );
                    break;
                case '*':
                    operands.push( firstOperand * secondOperand );
                    break;
                case '/':
                    operands.push( firstOperand / secondOperand );
                    break;
                case '^':
                    operands.push( pow(firstOperand, secondOperand) );
                    break;
                default:
                    break;
            }
        }
    }

    return operands.top();
}
