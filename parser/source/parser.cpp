#include "parser.hpp"
#include <stack>

const std::map<char, int> Parser::operations_priorities_ { {'+', 1}, {'-', 1},
                                                           {'*', 2}, {'/', 2},
                                                           {'^', 3} };

std::string Parser::ParseExpression(const std::string& expression) {
    if( !this->IsExpressionValid(expression) )
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

                auto newOperationPrio = operations_priorities_.find( *iter )->second;
                auto lastOperationPrio = operations_priorities_.find( operations.top() )->second;

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
                if(*(iter + 1) == '-') {
                    int left_bracket_index = (expression.end() - expression.begin()) - (expression.end() - iter) + 1;
                    int right_bracket_index =  expression.substr(left_bracket_index, expression.length() - 1).find_first_of(")") + left_bracket_index;

                    output_expression += expression.substr( left_bracket_index, right_bracket_index - left_bracket_index ) + ",";

                    iter += right_bracket_index - left_bracket_index + 1;
                    continue;
                }

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
                std::string operand = helper_.GetDigit( iter );
                output_expression += (operand + ",");
                iter += (operand.length() - 1);
                break;
        }
    }

    return output_expression;
}

bool Parser::IsExpressionValid(const std::string& expression) const {
    if( expression.empty() )
        return false;

    if( this->IsSyntaxisValid(expression) &&
        this->IsBracketsValid(expression) &&
        this->IsOperandsValid(expression) &&
        this->IsOperatorsValid(expression) )
        return true;

    return false;
}

bool Parser::IsSyntaxisValid(const std::string& expression) const {
    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( !helper_.IsDigit(iter) &&
            !helper_.IsOperator(iter) &&
            !helper_.IsSpecialSymbol(iter) )
            return false;
    }

    return true;
}

bool Parser::IsOperandsValid(const std::string& expression) const {
    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( helper_.IsDigit(iter) ) {
            std::string operand = helper_.GetDigit(iter);
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

bool Parser::IsOperatorsValid(const std::string& expression) const {
    if( helper_.IsOperator(expression.begin()) || helper_.IsOperator(expression.end()) )
        return false;

    int operators_count = 0;
    int operands_count = this->GetOperandsCount(expression);

    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( helper_.IsOperator(iter) ) {

            if( *iter == '/' && *(iter + 1) == '0' )
                return false;

            if( helper_.IsOperator(iter + 1) )
                return false;

            operators_count++;
        }
    }

    if( operators_count >= operands_count ||
        operators_count < operands_count - 1 )
        return false;

    return true;
}

bool Parser::IsBracketsValid(const std::string& expression) const {
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

int Parser::GetOperandsCount(const std::string& expression) const {
    int operands_count = 0;

    for(auto iter = expression.begin(); iter < expression.end(); iter++) {
        if( helper_.IsDigit(iter) ) {
            operands_count++;

            iter += helper_.GetDigit(iter).length();
        }
    }

    return operands_count;
}
