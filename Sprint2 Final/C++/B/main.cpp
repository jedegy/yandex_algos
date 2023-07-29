/*
-- WORKING PRINCIPLE --
This program implements a reverse Polish notation calculator to perform basic arithmetic operations (+, -, *, /) on integer operands.
The `calculate` function takes an expression in reverse Polish notation as input and evaluates it to produce the result.
The expression is provided as a space-separated string of operators and operands.

The program uses a stack to process the expression. It iterates over each token in the input expression and performs the following steps:
    * If the token is an operand (i.e., not an operator), it is converted to an integer and pushed onto the stack.
    * If the token is an operator, the function issue_operation is called to perform the corresponding arithmetic operation.
    The top two operands from the stack are popped, the operation is executed, and the result is pushed back onto the stack.

After processing all tokens, the final result will be at the top of the stack, which is then returned as the output of the calculate function.

-- PROOF OF CORRECTNESS --
The program handles various scenarios correctly:

 1. It correctly performs addition, subtraction, multiplication, and division on the operands.
 2. For division, it performs mathematical integer division, rounded down.
 3. If the expression contains an invalid operator, the program throws a `std::invalid_argument` exception with an appropriate error message.

-- TIME COMPLEXITY --
The time complexity of the `calculate` function is O(n), where `n` is the number of tokens in the input expression.
Each token is processed once, and the operations involved (pushing and popping from the stack) take constant time.

The time complexity of the issue_operation function is O(1) as it performs simple arithmetic operations on integers.

-- SPACE COMPLEXITY --
The space complexity of the program is O(n) due to the use of a stack to store operands during the evaluation.
In the worst case, the stack may hold all the operands from the input expression.

Successfully report: https://contest.yandex.ru/contest/22781/run-report/89342397/
*/
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

// Function to perform basic arithmetic operations (+, -, *, /)
int issue_operation(const std::string& op, int first, int second) {
    switch (op[0]) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
        {
            // Mathematical integer division rounded down
            std::div_t div = std::div(first, second);
            if ((first < 0 && div.rem != 0) || (first >= 0 && div.rem < 0))
                return --div.quot;

            return div.quot;
        }
        default:
            throw std::invalid_argument("Invalid operator " + op);
    }
}

// Function to calculate the result of a given expression in reverse Polish notation
int calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<int> operands;

    // Process each token in the input expression
    while (iss >> token) {
        if (std::isdigit(*(token.end() - 1))) {
            // If the token is an operand, push it to the stack after converting to an integer
            operands.push(std::stoi(token));
        } else {
            // If the token is an operator, pop the top two operands from the stack, perform the operation,
            // and push the result back to the stack
            int second_op = operands.top();
            operands.pop();
            int first_op = operands.top();
            operands.pop();
            int result = issue_operation(token, first_op, second_op);
            operands.push(result);
        }
    }

    // The final result will be at the top of the stack
    return operands.top();
}

int main() {
    std::string expression;

    getline(std::cin, expression);

    try {
        std::cout << calculate(expression) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
