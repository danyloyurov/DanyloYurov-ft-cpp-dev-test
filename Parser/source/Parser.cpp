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
                } else if( newOperationPrio <= lastOperationPrio ) {
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
    if( expression.empty() )
        return false;

    if( this->isSyntaxisValid(expression) &&
        this->isBracketsValid(expression) &&
        this->isOperandsValid(expression) &&
        this->isOperatorsValid(expression) )
        return true;

    return false;
}

bool Parser::isSyntaxisValid(const std::string& expression) const {
    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( !mHelper.isDigit(iter) &&
            !mHelper.isOperator(iter) &&
            !mHelper.isSpecialSymbol(iter) )
            return false;
    }

    return true;
}

bool Parser::isOperandsValid(const std::string& expression) const {
    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( mHelper.isDigit(iter) ) {
            std::string operand = mHelper.getDigit(iter);
            int endIdx = operand.length() - 1;

            if( *operand.begin() == '.' || *operand.end() == '.' )
                return false;

            int idx = operand.find('.');

            if( idx != std::string::npos ) {
                operand = operand.substr(idx + 1, endIdx);

                if( operand.find('.') != std::string::npos )
                    return false;

            }

            iter += endIdx;
        }
    }

    return true;
}

bool Parser::isOperatorsValid(const std::string& expression) const {
    if( mHelper.isOperator(expression.begin()) || mHelper.isOperator(expression.end()) )
        return false;

    int operators_count = 0;
    int operands_count = this->getOperandsCount(expression);

    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( mHelper.isOperator(iter) ) {

            if( *iter == '/' && *(iter + 1) == '0' )
                return false;

            if( mHelper.isOperator(iter + 1) )
                return false;

            operators_count++;
        }
    }

    if( operators_count >= operands_count ||
        operators_count < operands_count - 1 )
        return false;

    return true;
}

bool Parser::isBracketsValid(const std::string& expression) const {
    if( *expression.begin() == ')' || *expression.end() == '(' )
        return false;

    if( expression.find('(') == std::string::npos &&
        expression.find(')') == std::string::npos )
        return true;

    int left_bracket_counter = 0;

    for(auto iter = expression.begin(); iter < expression.end(); iter++) {

        if(*iter == '(')
            left_bracket_counter++;

        if(*iter == ')') {
            if(left_bracket_counter == 0)
                return false;
            else
                left_bracket_counter--;
        }

    }

    return static_cast<bool>(left_bracket_counter) ? false : true;
}

int Parser::getOperandsCount(const std::string& expression) const {
    int operands_count = 0;

    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( mHelper.isDigit(iter) ) {
            operands_count++;

            iter += mHelper.getDigit(iter).length();
        }
    }

    return operands_count;
}
