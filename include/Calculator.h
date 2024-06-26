#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "MathFunctions.h"
#include "ConfigReader.h"
#include <spdlog/spdlog.h>
#include <memory>

class Calculator {
public:
    Calculator(const std::string &configFile);
    void PerformCalculations();

private:
    std::shared_ptr<spdlog::logger> logger;
};

#endif // CALCULATOR_H
