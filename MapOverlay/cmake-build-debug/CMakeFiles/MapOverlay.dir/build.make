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
CMAKE_SOURCE_DIR = "T:\C++\Algorithm design and analysis\MapOverlay"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "T:\C++\Algorithm design and analysis\MapOverlay\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/MapOverlay.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MapOverlay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MapOverlay.dir/flags.make

CMakeFiles/MapOverlay.dir/main.cpp.obj: CMakeFiles/MapOverlay.dir/flags.make
CMakeFiles/MapOverlay.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="T:\C++\Algorithm design and analysis\MapOverlay\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MapOverlay.dir/main.cpp.obj"
	Y:\QT\Tools\mingw530_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MapOverlay.dir\main.cpp.obj -c "T:\C++\Algorithm design and analysis\MapOverlay\main.cpp"

CMakeFiles/MapOverlay.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MapOverlay.dir/main.cpp.i"
	Y:\QT\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "T:\C++\Algorithm design and analysis\MapOverlay\main.cpp" > CMakeFiles\MapOverlay.dir\main.cpp.i

CMakeFiles/MapOverlay.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MapOverlay.dir/main.cpp.s"
	Y:\QT\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "T:\C++\Algorithm design and analysis\MapOverlay\main.cpp" -o CMakeFiles\MapOverlay.dir\main.cpp.s

# Object files for target MapOverlay
MapOverlay_OBJECTS = \
"CMakeFiles/MapOverlay.dir/main.cpp.obj"

# External object files for target MapOverlay
MapOverlay_EXTERNAL_OBJECTS =

MapOverlay.exe: CMakeFiles/MapOverlay.dir/main.cpp.obj
MapOverlay.exe: CMakeFiles/MapOverlay.dir/build.make
MapOverlay.exe: CMakeFiles/MapOverlay.dir/linklibs.rsp
MapOverlay.exe: CMakeFiles/MapOverlay.dir/objects1.rsp
MapOverlay.exe: CMakeFiles/MapOverlay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="T:\C++\Algorithm design and analysis\MapOverlay\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MapOverlay.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MapOverlay.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MapOverlay.dir/build: MapOverlay.exe

.PHONY : CMakeFiles/MapOverlay.dir/build

CMakeFiles/MapOverlay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MapOverlay.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MapOverlay.dir/clean

CMakeFiles/MapOverlay.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "T:\C++\Algorithm design and analysis\MapOverlay" "T:\C++\Algorithm design and analysis\MapOverlay" "T:\C++\Algorithm design and analysis\MapOverlay\cmake-build-debug" "T:\C++\Algorithm design and analysis\MapOverlay\cmake-build-debug" "T:\C++\Algorithm design and analysis\MapOverlay\cmake-build-debug\CMakeFiles\MapOverlay.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MapOverlay.dir/depend

