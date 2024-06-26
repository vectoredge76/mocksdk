#include "Calculator.h"
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

Calculator::Calculator(const std::string &configFile) {
    ConfigReader configReader(configFile);
    std::string logFilePath = configReader.GetLogFilePath();
    std::string logFileName = configReader.GetLogFileName();

    logger = spdlog::basic_logger_mt("CalculatorLogger", logFilePath + "/" + logFileName);
    spdlog::set_default_logger(logger);
}

void Calculator::PerformCalculations() {
    int a = 10;
    int b = 5;

    int sum = MathFunctions::Add(a, b);
    logger->info("Add: {} + {} = {}", a, b, sum);

    int difference = MathFunctions::Subtract(a, b);
    logger->info("Subtract: {} - {} = {}", a, b, difference);

    int product = MathFunctions::Multiply(a, b);
    logger->info("Multiply: {} * {} = {}", a, b, product);

    double quotient;
    try {
        quotient = MathFunctions::Divide(a, b);
        logger->info("Divide: {} / {} = {}", a, b, quotient);
    } catch (const std::invalid_argument &e) {
        logger->error("Divide: {}", e.what());
    }
}
