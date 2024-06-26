#include "MathFunctions.h"
#include <stdexcept>

int MathFunctions::Add(int a, int b) {
    return a + b;
}

int MathFunctions::Subtract(int a, int b) {
    return a - b;
}

int MathFunctions::Multiply(int a, int b) {
    return a * b;
}

double MathFunctions::Divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return static_cast<double>(a) / b;
}
