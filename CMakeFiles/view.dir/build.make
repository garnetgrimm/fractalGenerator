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
include CMakeFiles/view.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/view.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/view.dir/flags.make

CMakeFiles/view.dir/src/view/gui.cpp.o: CMakeFiles/view.dir/flags.make
CMakeFiles/view.dir/src/view/gui.cpp.o: src/view/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garnet/Desktop/Programming/fractle/mandlebrot/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/view.dir/src/view/gui.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/view.dir/src/view/gui.cpp.o -c /home/garnet/Desktop/Programming/fractle/mandlebrot/src/view/gui.cpp

CMakeFiles/view.dir/src/view/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/view.dir/src/view/gui.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/garnet/Desktop/Programming/fractle/mandlebrot/src/view/gui.cpp > CMakeFiles/view.dir/src/view/gui.cpp.i

CMakeFiles/view.dir/src/view/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/view.dir/src/view/gui.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/garnet/Desktop/Programming/fractle/mandlebrot/src/view/gui.cpp -o CMakeFiles/view.dir/src/view/gui.cpp.s

CMakeFiles/view.dir/src/view/gui.cpp.o.requires:

.PHONY : CMakeFiles/view.dir/src/view/gui.cpp.o.requires

CMakeFiles/view.dir/src/view/gui.cpp.o.provides: CMakeFiles/view.dir/src/view/gui.cpp.o.requires
	$(MAKE) -f CMakeFiles/view.dir/build.make CMakeFiles/view.dir/src/view/gui.cpp.o.provides.build
.PHONY : CMakeFiles/view.dir/src/view/gui.cpp.o.provides

CMakeFiles/view.dir/src/view/gui.cpp.o.provides.build: CMakeFiles/view.dir/src/view/gui.cpp.o


# Object files for target view
view_OBJECTS = \
"CMakeFiles/view.dir/src/view/gui.cpp.o"

# External object files for target view
view_EXTERNAL_OBJECTS =

libview.a: CMakeFiles/view.dir/src/view/gui.cpp.o
libview.a: CMakeFiles/view.dir/build.make
libview.a: CMakeFiles/view.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/garnet/Desktop/Programming/fractle/mandlebrot/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libview.a"
	$(CMAKE_COMMAND) -P CMakeFiles/view.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/view.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/view.dir/build: libview.a

.PHONY : CMakeFiles/view.dir/build

CMakeFiles/view.dir/requires: CMakeFiles/view.dir/src/view/gui.cpp.o.requires

.PHONY : CMakeFiles/view.dir/requires

CMakeFiles/view.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/view.dir/cmake_clean.cmake
.PHONY : CMakeFiles/view.dir/clean

CMakeFiles/view.dir/depend:
	cd /home/garnet/Desktop/Programming/fractle/mandlebrot && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot /home/garnet/Desktop/Programming/fractle/mandlebrot/CMakeFiles/view.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/view.dir/depend

