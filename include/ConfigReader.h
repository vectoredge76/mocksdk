#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <string>
#include <yaml-cpp/yaml.h>

class ConfigReader {
public:
    ConfigReader(const std::string &configFile);
    std::string GetLogFilePath() const;
    std::string GetLogFileName() const;

private:
    YAML::Node config;
};

#endif // CONFIGREADER_H
