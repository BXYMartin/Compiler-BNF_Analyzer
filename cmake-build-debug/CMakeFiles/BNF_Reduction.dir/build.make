# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /cygdrive/c/Users/BXYMartin/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/BXYMartin/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BNF_Reduction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BNF_Reduction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BNF_Reduction.dir/flags.make

CMakeFiles/BNF_Reduction.dir/main.cpp.o: CMakeFiles/BNF_Reduction.dir/flags.make
CMakeFiles/BNF_Reduction.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BNF_Reduction.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BNF_Reduction.dir/main.cpp.o -c "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/main.cpp"

CMakeFiles/BNF_Reduction.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BNF_Reduction.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/main.cpp" > CMakeFiles/BNF_Reduction.dir/main.cpp.i

CMakeFiles/BNF_Reduction.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BNF_Reduction.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/main.cpp" -o CMakeFiles/BNF_Reduction.dir/main.cpp.s

# Object files for target BNF_Reduction
BNF_Reduction_OBJECTS = \
"CMakeFiles/BNF_Reduction.dir/main.cpp.o"

# External object files for target BNF_Reduction
BNF_Reduction_EXTERNAL_OBJECTS =

BNF_Reduction.exe: CMakeFiles/BNF_Reduction.dir/main.cpp.o
BNF_Reduction.exe: CMakeFiles/BNF_Reduction.dir/build.make
BNF_Reduction.exe: CMakeFiles/BNF_Reduction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BNF_Reduction.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BNF_Reduction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BNF_Reduction.dir/build: BNF_Reduction.exe

.PHONY : CMakeFiles/BNF_Reduction.dir/build

CMakeFiles/BNF_Reduction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BNF_Reduction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BNF_Reduction.dir/clean

CMakeFiles/BNF_Reduction.dir/depend:
	cd "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction" "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction" "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/cmake-build-debug" "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/cmake-build-debug" "/cygdrive/e/Visual Studio C Programming/Windows Studio/BNF_Reduction/cmake-build-debug/CMakeFiles/BNF_Reduction.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BNF_Reduction.dir/depend

