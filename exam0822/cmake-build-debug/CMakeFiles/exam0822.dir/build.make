# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/percy/code1/LeedCode/exam0822

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/percy/code1/LeedCode/exam0822/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/exam0822.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/exam0822.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exam0822.dir/flags.make

CMakeFiles/exam0822.dir/main.cpp.o: CMakeFiles/exam0822.dir/flags.make
CMakeFiles/exam0822.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/percy/code1/LeedCode/exam0822/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exam0822.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exam0822.dir/main.cpp.o -c /Users/percy/code1/LeedCode/exam0822/main.cpp

CMakeFiles/exam0822.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam0822.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/percy/code1/LeedCode/exam0822/main.cpp > CMakeFiles/exam0822.dir/main.cpp.i

CMakeFiles/exam0822.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam0822.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/percy/code1/LeedCode/exam0822/main.cpp -o CMakeFiles/exam0822.dir/main.cpp.s

# Object files for target exam0822
exam0822_OBJECTS = \
"CMakeFiles/exam0822.dir/main.cpp.o"

# External object files for target exam0822
exam0822_EXTERNAL_OBJECTS =

exam0822: CMakeFiles/exam0822.dir/main.cpp.o
exam0822: CMakeFiles/exam0822.dir/build.make
exam0822: CMakeFiles/exam0822.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/percy/code1/LeedCode/exam0822/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exam0822"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exam0822.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exam0822.dir/build: exam0822
.PHONY : CMakeFiles/exam0822.dir/build

CMakeFiles/exam0822.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exam0822.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exam0822.dir/clean

CMakeFiles/exam0822.dir/depend:
	cd /Users/percy/code1/LeedCode/exam0822/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/percy/code1/LeedCode/exam0822 /Users/percy/code1/LeedCode/exam0822 /Users/percy/code1/LeedCode/exam0822/cmake-build-debug /Users/percy/code1/LeedCode/exam0822/cmake-build-debug /Users/percy/code1/LeedCode/exam0822/cmake-build-debug/CMakeFiles/exam0822.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exam0822.dir/depend

