#include "Parser.hpp"
#include <stack>

const std::map<char, int> Parser::mOperationsPriorities {   {'+', 1}, {'-', 1},
                                                            {'*', 2}, {'/', 2},
                                                            {'^', 3} };

std::string Parser::parseExpression(const std::string& expression) {
    if( !this->isExpressionValid(expression) )
        return "";

    std::string output_expression;
    std::stack<char> operations;

    auto addOperation = [](const std::string& str, const char& operation)
    {
        std::string output = str;
        output += operation;
        output += ",";
        return output;
    };

    for(auto iter = expression.begin(); iter < expression.end() + 1; iter++) {
        if(iter == expression.end()) {
            if(operations.empty()) {
                output_expression = output_expression.substr(0, output_expression.length() - 1);
                break;
            }

            output_expression = addOperation(output_expression, operations.top());
            operations.pop();
            iter--;
            continue;
        }

        switch(*iter) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            {
                if(operations.empty()) {
                    operations.push(*iter);
                    continue;
                }

                auto newOperationPrio = mOperationsPriorities.find( *iter )->second;
                auto lastOperationPrio = mOperationsPriorities.find( operations.top() )->second;

                if( newOperationPrio > lastOperationPrio ) {
                    operations.push(*iter);
                } else if( newOperationPrio < lastOperationPrio ) {
                    output_expression = addOperation(output_expression, operations.top());
                    operations.pop();
                    iter--;
                }

                break;
            }
            case '(':
                operations.push(*iter);
                break;
            case ')':
                {
                    if( operations.top() != '(' ) {
                        output_expression = addOperation(output_expression, operations.top());
                        iter--;
                    }

                    operations.pop();
                }
                break;
            case ' ': /*avoiding spaces*/
                continue;
            default: /*digits case*/
                std::string operand = mHelper.getDigit( iter );
                output_expression += (operand + ",");
                iter += (operand.length() - 1);
                break;
        }
    }

    return output_expression;
}

bool Parser::isExpressionValid(const std::string& expression) const {
    return true;
}
