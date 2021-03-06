# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/garnet/Desktop/Programming/fractle/mandlebrot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/garnet/Desktop/Programming/fractle/mandlebrot

# Include any dependencies generated for this target.
include CMakeFiles/model.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/model.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/model.dir/flags.make

CMakeFiles/model.dir/src/model/genfrac.cpp.o: CMakeFiles/model.dir/flags.make
CMakeFiles/model.dir/src/model/genfrac.cpp.o: src/model/genfrac.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garnet/Desktop/Programming/fractle/mandlebrot/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/model.dir/src/model/genfrac.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/model.dir/src/model/genfrac.cpp.o -c /home/garnet/Desktop/Programming/fractle/mandlebrot/src/model/genfrac.cpp

CMakeFiles/model.dir/src/model/genfrac.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model.dir/src/model/genfrac.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/garnet/Desktop/Programming/fractle/mandlebrot/src/model/genfrac.cpp > CMakeFiles/model.dir/src/model/genfrac.cpp.i

CMakeFiles/model.dir/src/model/genfrac.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model.dir/src/model/genfrac.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/garnet/Desktop/Programming/fractle/mandlebrot/src/model/genfrac.cpp -o CMakeFiles/model.dir/src/model/genfrac.cpp.s

CMakeFiles/model.dir/src/model/genfrac.cpp.o.requires:

.PHONY : CMakeFiles/model.dir/src/model/genfrac.cpp.o.requires

CMakeFiles/model.dir/src/model/genfrac.cpp.o.provides: CMakeFiles/model.dir/src/model/genfrac.cpp.o.requires
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/model/genfrac.cpp.o.provides.build
.PHONY : CMakeFiles/model.dir/src/model/genfrac.cpp.o.provides

CMakeFiles/model.dir/src/model/genfrac.cpp.o.provides.build: CMakeFiles/model.dir/src/model/genfrac.cpp.o


# Object files for target model
model_OBJECTS = \
"CMakeFiles/model.dir/src/model/genfrac.cpp.o"

# External object files for target model
model_EXTERNAL_OBJECTS =

libmodel.a: CMakeFiles/model.dir/src/model/genfrac.cpp.o
libmodel.a: CMakeFiles/model.dir/build.make
libmodel.a: CMakeFiles/model.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/garnet/Desktop/Programming/fractle/mandlebrot/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmodel.a"
	$(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/model.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/model.dir/build: libmodel.a

.PHONY : CMakeFiles/model.dir/build

CMakeFiles/model.dir/requires: CMakeFiles/model.dir/src/model/genfrac.cpp.o.requires

.PHONY : CMakeFiles/model.dir/requires

CMakeFiles/model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean.cmake
.PHONY : CMakeFiles/model.dir/clean

CMakeFiles/model.dir/depend:
	cd /home/garnet/Desktop/Programming/fractle/mandlebrot && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot/CMakeFiles/model.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/model.dir/depend

