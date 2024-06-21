#include "Calculator.h"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config file path>" << std::endl;
        return 1;
    }

    std::string configFile = argv[1];
    Calculator calculator(configFile);
    calculator.PerformCalculations();
    return 0;
}
