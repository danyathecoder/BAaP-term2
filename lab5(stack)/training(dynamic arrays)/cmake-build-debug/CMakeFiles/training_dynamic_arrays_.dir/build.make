# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/training_dynamic_arrays_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/training_dynamic_arrays_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/training_dynamic_arrays_.dir/flags.make

CMakeFiles/training_dynamic_arrays_.dir/main.c.o: CMakeFiles/training_dynamic_arrays_.dir/flags.make
CMakeFiles/training_dynamic_arrays_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/training_dynamic_arrays_.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/training_dynamic_arrays_.dir/main.c.o   -c "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/main.c"

CMakeFiles/training_dynamic_arrays_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/training_dynamic_arrays_.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/main.c" > CMakeFiles/training_dynamic_arrays_.dir/main.c.i

CMakeFiles/training_dynamic_arrays_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/training_dynamic_arrays_.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/main.c" -o CMakeFiles/training_dynamic_arrays_.dir/main.c.s

# Object files for target training_dynamic_arrays_
training_dynamic_arrays__OBJECTS = \
"CMakeFiles/training_dynamic_arrays_.dir/main.c.o"

# External object files for target training_dynamic_arrays_
training_dynamic_arrays__EXTERNAL_OBJECTS =

training_dynamic_arrays_: CMakeFiles/training_dynamic_arrays_.dir/main.c.o
training_dynamic_arrays_: CMakeFiles/training_dynamic_arrays_.dir/build.make
training_dynamic_arrays_: CMakeFiles/training_dynamic_arrays_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable training_dynamic_arrays_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/training_dynamic_arrays_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/training_dynamic_arrays_.dir/build: training_dynamic_arrays_

.PHONY : CMakeFiles/training_dynamic_arrays_.dir/build

CMakeFiles/training_dynamic_arrays_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/training_dynamic_arrays_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/training_dynamic_arrays_.dir/clean

CMakeFiles/training_dynamic_arrays_.dir/depend:
	cd "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)" "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)" "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/cmake-build-debug" "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/cmake-build-debug" "/home/danilapoddubny/Programming/c&c++/BA&P_term2/lab5(stack)/training(dynamic arrays)/cmake-build-debug/CMakeFiles/training_dynamic_arrays_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/training_dynamic_arrays_.dir/depend

