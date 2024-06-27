#include "Calculator.h"
#include <re2/re2.h>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config file path>" << std::endl;
        return 1;
    }

    std::string configFile = argv[1];
    Calculator calculator(configFile);
    calculator.PerformCalculations();

    // Example RE2 usage
    std::string text = "Sample text for regex";
    std::string pattern = "Sample.*regex";
    if (RE2::FullMatch(text, pattern)) {
        std::cout << "Pattern matched!" << std::endl;
    } else {
        std::cout << "Pattern not matched." << std::endl;
    }

    return 0;
}
