# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lokesh/VectoredgeWorkspace/mocksdk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lokesh/VectoredgeWorkspace/mocksdk/build

# Include any dependencies generated for this target.
include CMakeFiles/Calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Calculator.dir/flags.make

CMakeFiles/Calculator.dir/src/main.cpp.o: CMakeFiles/Calculator.dir/flags.make
CMakeFiles/Calculator.dir/src/main.cpp.o: /Users/lokesh/VectoredgeWorkspace/mocksdk/src/main.cpp
CMakeFiles/Calculator.dir/src/main.cpp.o: CMakeFiles/Calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lokesh/VectoredgeWorkspace/mocksdk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Calculator.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Calculator.dir/src/main.cpp.o -MF CMakeFiles/Calculator.dir/src/main.cpp.o.d -o CMakeFiles/Calculator.dir/src/main.cpp.o -c /Users/lokesh/VectoredgeWorkspace/mocksdk/src/main.cpp

CMakeFiles/Calculator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Calculator.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lokesh/VectoredgeWorkspace/mocksdk/src/main.cpp > CMakeFiles/Calculator.dir/src/main.cpp.i

CMakeFiles/Calculator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Calculator.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lokesh/VectoredgeWorkspace/mocksdk/src/main.cpp -o CMakeFiles/Calculator.dir/src/main.cpp.s

CMakeFiles/Calculator.dir/src/Calculator.cpp.o: CMakeFiles/Calculator.dir/flags.make
CMakeFiles/Calculator.dir/src/Calculator.cpp.o: /Users/lokesh/VectoredgeWorkspace/mocksdk/src/Calculator.cpp
CMakeFiles/Calculator.dir/src/Calculator.cpp.o: CMakeFiles/Calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lokesh/VectoredgeWorkspace/mocksdk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Calculator.dir/src/Calculator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Calculator.dir/src/Calculator.cpp.o -MF CMakeFiles/Calculator.dir/src/Calculator.cpp.o.d -o CMakeFiles/Calculator.dir/src/Calculator.cpp.o -c /Users/lokesh/VectoredgeWorkspace/mocksdk/src/Calculator.cpp

CMakeFiles/Calculator.dir/src/Calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Calculator.dir/src/Calculator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lokesh/VectoredgeWorkspace/mocksdk/src/Calculator.cpp > CMakeFiles/Calculator.dir/src/Calculator.cpp.i

CMakeFiles/Calculator.dir/src/Calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Calculator.dir/src/Calculator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lokesh/VectoredgeWorkspace/mocksdk/src/Calculator.cpp -o CMakeFiles/Calculator.dir/src/Calculator.cpp.s

CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o: CMakeFiles/Calculator.dir/flags.make
CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o: /Users/lokesh/VectoredgeWorkspace/mocksdk/src/ConfigReader.cpp
CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o: CMakeFiles/Calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lokesh/VectoredgeWorkspace/mocksdk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o -MF CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o.d -o CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o -c /Users/lokesh/VectoredgeWorkspace/mocksdk/src/ConfigReader.cpp

CMakeFiles/Calculator.dir/src/ConfigReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Calculator.dir/src/ConfigReader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lokesh/VectoredgeWorkspace/mocksdk/src/ConfigReader.cpp > CMakeFiles/Calculator.dir/src/ConfigReader.cpp.i

CMakeFiles/Calculator.dir/src/ConfigReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Calculator.dir/src/ConfigReader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lokesh/VectoredgeWorkspace/mocksdk/src/ConfigReader.cpp -o CMakeFiles/Calculator.dir/src/ConfigReader.cpp.s

# Object files for target Calculator
Calculator_OBJECTS = \
"CMakeFiles/Calculator.dir/src/main.cpp.o" \
"CMakeFiles/Calculator.dir/src/Calculator.cpp.o" \
"CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o"

# External object files for target Calculator
Calculator_EXTERNAL_OBJECTS =

Calculator: CMakeFiles/Calculator.dir/src/main.cpp.o
Calculator: CMakeFiles/Calculator.dir/src/Calculator.cpp.o
Calculator: CMakeFiles/Calculator.dir/src/ConfigReader.cpp.o
Calculator: CMakeFiles/Calculator.dir/build.make
Calculator: libMathFunctions.a
Calculator: /opt/homebrew/lib/libspdlog.1.14.1.dylib
Calculator: /Users/lokesh/anaconda3/lib/libyaml-cpp.0.7.0.dylib
Calculator: /opt/homebrew/lib/libfmt.10.2.1.dylib
Calculator: CMakeFiles/Calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lokesh/VectoredgeWorkspace/mocksdk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Calculator.dir/build: Calculator
.PHONY : CMakeFiles/Calculator.dir/build

CMakeFiles/Calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Calculator.dir/clean

CMakeFiles/Calculator.dir/depend:
	cd /Users/lokesh/VectoredgeWorkspace/mocksdk/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lokesh/VectoredgeWorkspace/mocksdk /Users/lokesh/VectoredgeWorkspace/mocksdk /Users/lokesh/VectoredgeWorkspace/mocksdk/build /Users/lokesh/VectoredgeWorkspace/mocksdk/build /Users/lokesh/VectoredgeWorkspace/mocksdk/build/CMakeFiles/Calculator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Calculator.dir/depend
