#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double performOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: throw std::invalid_argument("Invalid operator");
    }
}

double evaluateInfixExpression(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char current = expression[i];

        if (isspace(current)) continue;

        if (isdigit(current)) {
            double number = 0;
            size_t j = i;
            while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
                ++j;
            }
            std::stringstream(expression.substr(i, j - i)) >> number;
            values.push(number);
            i = j - 1;
        } else if (current == '(') {
            operators.push(current);
        } else if (current == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(performOperation(val1, val2, op));
            }
            if (!operators.empty()) operators.pop();
        } else if (current == '+' || current == '-' || current == '*' || current == '/') {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(current)) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(performOperation(val1, val2, op));
            }
            operators.push(current);
        }
    }

    while (!operators.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(performOperation(val1, val2, op));
    }

    return values.top();
}

int main() {
    std::string expression;
    std::cout << "Enter an infix expression (e.g., 3 + 5 - 2 * 3 / 2): ";
    std::getline(std::cin, expression);

    try {
        double result = evaluateInfixExpression(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}