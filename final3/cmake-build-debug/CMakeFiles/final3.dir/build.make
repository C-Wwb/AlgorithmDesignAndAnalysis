# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "T:\C++\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "T:\C++\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "T:\C++\Algorithm design and analysis\final3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "T:\C++\Algorithm design and analysis\final3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/final3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/final3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/final3.dir/flags.make

CMakeFiles/final3.dir/main.cpp.obj: CMakeFiles/final3.dir/flags.make
CMakeFiles/final3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="T:\C++\Algorithm design and analysis\final3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/final3.dir/main.cpp.obj"
	Y:\QT\Tools\mingw530_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\final3.dir\main.cpp.obj -c "T:\C++\Algorithm design and analysis\final3\main.cpp"

CMakeFiles/final3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final3.dir/main.cpp.i"
	Y:\QT\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "T:\C++\Algorithm design and analysis\final3\main.cpp" > CMakeFiles\final3.dir\main.cpp.i

CMakeFiles/final3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final3.dir/main.cpp.s"
	Y:\QT\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "T:\C++\Algorithm design and analysis\final3\main.cpp" -o CMakeFiles\final3.dir\main.cpp.s

# Object files for target final3
final3_OBJECTS = \
"CMakeFiles/final3.dir/main.cpp.obj"

# External object files for target final3
final3_EXTERNAL_OBJECTS =

final3.exe: CMakeFiles/final3.dir/main.cpp.obj
final3.exe: CMakeFiles/final3.dir/build.make
final3.exe: CMakeFiles/final3.dir/linklibs.rsp
final3.exe: CMakeFiles/final3.dir/objects1.rsp
final3.exe: CMakeFiles/final3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="T:\C++\Algorithm design and analysis\final3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable final3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\final3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/final3.dir/build: final3.exe

.PHONY : CMakeFiles/final3.dir/build

CMakeFiles/final3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\final3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/final3.dir/clean

CMakeFiles/final3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "T:\C++\Algorithm design and analysis\final3" "T:\C++\Algorithm design and analysis\final3" "T:\C++\Algorithm design and analysis\final3\cmake-build-debug" "T:\C++\Algorithm design and analysis\final3\cmake-build-debug" "T:\C++\Algorithm design and analysis\final3\cmake-build-debug\CMakeFiles\final3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/final3.dir/depend

