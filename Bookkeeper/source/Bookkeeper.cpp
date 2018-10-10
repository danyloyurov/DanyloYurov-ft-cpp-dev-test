#include "Bookkeeper.hpp"

#include <stack>

double Bookkeeper::calculateExpression(const std::string& expression) const {
    std::stack<double> operands;

    for(auto iter = expression.begin(); iter < expression.end(); iter++) {

        if( mHelper.isDigit( iter ) ) {
            std::string operand = mHelper.getDigit( iter );
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
