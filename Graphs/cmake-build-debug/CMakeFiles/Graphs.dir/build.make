# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\steph\Desktop\Data-Structures-C\Graphs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\steph\Desktop\Data-Structures-C\Graphs\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Graphs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Graphs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Graphs.dir/flags.make

CMakeFiles/Graphs.dir/main.cpp.obj: CMakeFiles/Graphs.dir/flags.make
CMakeFiles/Graphs.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\steph\Desktop\Data-Structures-C\Graphs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Graphs.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Graphs.dir\main.cpp.obj -c C:\Users\steph\Desktop\Data-Structures-C\Graphs\main.cpp

CMakeFiles/Graphs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Graphs.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\steph\Desktop\Data-Structures-C\Graphs\main.cpp > CMakeFiles\Graphs.dir\main.cpp.i

CMakeFiles/Graphs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Graphs.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\steph\Desktop\Data-Structures-C\Graphs\main.cpp -o CMakeFiles\Graphs.dir\main.cpp.s

CMakeFiles/Graphs.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Graphs.dir/main.cpp.obj.requires

CMakeFiles/Graphs.dir/main.cpp.obj.provides: CMakeFiles/Graphs.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Graphs.dir\build.make CMakeFiles/Graphs.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Graphs.dir/main.cpp.obj.provides

CMakeFiles/Graphs.dir/main.cpp.obj.provides.build: CMakeFiles/Graphs.dir/main.cpp.obj


# Object files for target Graphs
Graphs_OBJECTS = \
"CMakeFiles/Graphs.dir/main.cpp.obj"

# External object files for target Graphs
Graphs_EXTERNAL_OBJECTS =

Graphs.exe: CMakeFiles/Graphs.dir/main.cpp.obj
Graphs.exe: CMakeFiles/Graphs.dir/build.make
Graphs.exe: CMakeFiles/Graphs.dir/linklibs.rsp
Graphs.exe: CMakeFiles/Graphs.dir/objects1.rsp
Graphs.exe: CMakeFiles/Graphs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\steph\Desktop\Data-Structures-C\Graphs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Graphs.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Graphs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Graphs.dir/build: Graphs.exe

.PHONY : CMakeFiles/Graphs.dir/build

CMakeFiles/Graphs.dir/requires: CMakeFiles/Graphs.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Graphs.dir/requires

CMakeFiles/Graphs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Graphs.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Graphs.dir/clean

CMakeFiles/Graphs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\steph\Desktop\Data-Structures-C\Graphs C:\Users\steph\Desktop\Data-Structures-C\Graphs C:\Users\steph\Desktop\Data-Structures-C\Graphs\cmake-build-debug C:\Users\steph\Desktop\Data-Structures-C\Graphs\cmake-build-debug C:\Users\steph\Desktop\Data-Structures-C\Graphs\cmake-build-debug\CMakeFiles\Graphs.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Graphs.dir/depend

