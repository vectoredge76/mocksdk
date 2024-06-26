# mocksdk
Mock SDK project

Requirements of the project

Project Tasks
1. Classification Application Development
Interns are expected to develop a classification application with the following specifications:
Google RE2 Regex Integration: Utilise Google RE2 for efficient regex operations.
Shared Object File (.so): Create a `.so` file for the classification application.
Confidence Score Assignment: Integrate provided code to assign confidence scores to detections made using regex.
GRPC Client for Push Notification: Develop a gRPC client to handle push notifications.

2. Standard SDK Components
The application must include the following standard SDK components:
Logger: Implement a logging mechanism to track application behaviour, errors, and performance metrics.
Configuration File: Develop a configuration file to manage application settings and parameters.
SQLite Integration: Incorporate SQLite for data storage and management needs.
Required Skills and Knowledge
Regex and Google RE2: Strong understanding of regular expressions and experience with Google RE2 regex library.
C++ Programming: C++ for developing the core application and creating the `.so` file.
Unstructured Data Processing: Experience in handling and processing unstructured data formats.
Shared Object File Creation: Knowledge of creating and managing `.so` files in a Linux environment.
CMake: Proficiency in CMake for building and managing the project.
gRPC: Experience with gRPC for client-server communication.
SQLite: Knowledge of SQLite for database management.

Responsibilities
1. Development:
Design and implement the classification application using Google RE2 regex.
Ensure the application can handle unstructured data efficiently.
Create a shared object file (`.so`) for the application.

2. Standard SDK Components:
 Implement a robust logging mechanism.
 Develop and maintain a configuration file for the application.

3. Documentation and Testing:
Write comprehensive documentation for the application, including usage instructions and API references.
 Develop unit tests and integration tests to ensure application reliability and accuracy.

Deliverables
We are expecting you to deliver the following by the end of the internship:


Classification Application: A fully functional classification application integrated 
with Google RE2 regex and capable of assigning confidence scores.

Shared Object File: A `.so` file for the classification application.
Logger Implementation: A complete logging mechanism integrated into the application.
Configuration File: A configuration file to manage application settings.
Documentation: Detailed documentation covering the application’s features, usage, and APIs.
Tests: A suite of unit and integration tests validating the application’s functionality and performance.


Execution Steps

1) Install spdlog (https://github.com/gabime/spdlog) you can use the below based on Linux flavor u have

Debian: sudo apt install libspdlog-dev
Homebrew: brew install spdlog
MacPorts: sudo port install spdlog
FreeBSD: pkg install spdlog
Fedora: dnf install spdlog
Gentoo: emerge dev-libs/spdlog
Arch Linux: pacman -S spdlog
openSUSE: sudo zypper in spdlog-devel
vcpkg: vcpkg install spdlog
conan: spdlog/[>=1.4.1]
conda: conda install -c conda-forge spdlog
build2: depends: spdlog ^1.8.2

2) Use following commands to run the program
cd build
cmake ..
make
./Calculator ../config/config.yaml

