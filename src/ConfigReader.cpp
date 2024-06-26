#include "ConfigReader.h"
#include <stdexcept>

ConfigReader::ConfigReader(const std::string &configFile) {
    config = YAML::LoadFile(configFile);
}

std::string ConfigReader::GetLogFilePath() const {
    if (config["logfile"]["path"]) {
        return config["logfile"]["path"].as<std::string>();
    }
    throw std::runtime_error("Log file path not specified in config");
}

std::string ConfigReader::GetLogFileName() const {
    if (config["logfile"]["name"]) {
        return config["logfile"]["name"].as<std::string>();
    }
    throw std::runtime_error("Log file name not specified in config");
}
