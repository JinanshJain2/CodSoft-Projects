#include <iostream>

int main() {
    char operation;
    double num1, num2;

    std::cout << "Simple Calculator" << std::endl;
    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error! Division by zero is not allowed." << std::endl;
                return 1;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Invalid operation. Please use +, -, *, or /." << std::endl;
            return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
