# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/build

# Include any dependencies generated for this target.
include CMakeFiles/Ex0504_EvaluatingExpressions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex0504_EvaluatingExpressions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex0504_EvaluatingExpressions.dir/flags.make

CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.o: CMakeFiles/Ex0504_EvaluatingExpressions.dir/flags.make
CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.o: ../Ex0504_EvaluatingExpressions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.o -c /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/Ex0504_EvaluatingExpressions.cpp

CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/Ex0504_EvaluatingExpressions.cpp > CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.i

CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/Ex0504_EvaluatingExpressions.cpp -o CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.s

# Object files for target Ex0504_EvaluatingExpressions
Ex0504_EvaluatingExpressions_OBJECTS = \
"CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.o"

# External object files for target Ex0504_EvaluatingExpressions
Ex0504_EvaluatingExpressions_EXTERNAL_OBJECTS =

../Ex0504_EvaluatingExpressions: CMakeFiles/Ex0504_EvaluatingExpressions.dir/Ex0504_EvaluatingExpressions.cpp.o
../Ex0504_EvaluatingExpressions: CMakeFiles/Ex0504_EvaluatingExpressions.dir/build.make
../Ex0504_EvaluatingExpressions: CMakeFiles/Ex0504_EvaluatingExpressions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../Ex0504_EvaluatingExpressions"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex0504_EvaluatingExpressions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex0504_EvaluatingExpressions.dir/build: ../Ex0504_EvaluatingExpressions

.PHONY : CMakeFiles/Ex0504_EvaluatingExpressions.dir/build

CMakeFiles/Ex0504_EvaluatingExpressions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex0504_EvaluatingExpressions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex0504_EvaluatingExpressions.dir/clean

CMakeFiles/Ex0504_EvaluatingExpressions.dir/depend:
	cd /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/build /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/build /home/cgt20/Codingtest/DataStructures/Ex0504_EvaluatingExpressions/build/CMakeFiles/Ex0504_EvaluatingExpressions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex0504_EvaluatingExpressions.dir/depend

