cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

# Set the version number
set(Calculator_VERSION_MAJOR 1)
set(Calculator_VERSION_MINOR 0)

# Configure a header file to pass some of the CMake settings to the source code
configure_file(config/config.h.in config.h)

# Add include directories
include_directories(${CMAKE_BINARY_DIR} include)

# Add external libraries
find_package(spdlog REQUIRED)
find_package(yaml-cpp REQUIRED)

# Add the MathFunctions library
add_library(MathFunctions src/MathFunctions.cpp)

# Add the executable
add_executable(Calculator src/main.cpp src/Calculator.cpp src/ConfigReader.cpp)

# Link the MathFunctions library and external libraries
target_link_libraries(Calculator MathFunctions spdlog::spdlog yaml-cpp)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
