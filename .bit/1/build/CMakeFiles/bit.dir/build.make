# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/workspaces/Bit Nexustech"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/workspaces/Bit Nexustech/build"

# Include any dependencies generated for this target.
include CMakeFiles/bit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bit.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bit.dir/flags.make

CMakeFiles/bit.dir/src/main.cpp.o: CMakeFiles/bit.dir/flags.make
CMakeFiles/bit.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/bit.dir/src/main.cpp.o: CMakeFiles/bit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/workspaces/Bit Nexustech/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bit.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bit.dir/src/main.cpp.o -MF CMakeFiles/bit.dir/src/main.cpp.o.d -o CMakeFiles/bit.dir/src/main.cpp.o -c "/workspaces/Bit Nexustech/src/main.cpp"

CMakeFiles/bit.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bit.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/workspaces/Bit Nexustech/src/main.cpp" > CMakeFiles/bit.dir/src/main.cpp.i

CMakeFiles/bit.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bit.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/workspaces/Bit Nexustech/src/main.cpp" -o CMakeFiles/bit.dir/src/main.cpp.s

CMakeFiles/bit.dir/src/interactive_terminal.cpp.o: CMakeFiles/bit.dir/flags.make
CMakeFiles/bit.dir/src/interactive_terminal.cpp.o: ../src/interactive_terminal.cpp
CMakeFiles/bit.dir/src/interactive_terminal.cpp.o: CMakeFiles/bit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/workspaces/Bit Nexustech/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bit.dir/src/interactive_terminal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bit.dir/src/interactive_terminal.cpp.o -MF CMakeFiles/bit.dir/src/interactive_terminal.cpp.o.d -o CMakeFiles/bit.dir/src/interactive_terminal.cpp.o -c "/workspaces/Bit Nexustech/src/interactive_terminal.cpp"

CMakeFiles/bit.dir/src/interactive_terminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bit.dir/src/interactive_terminal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/workspaces/Bit Nexustech/src/interactive_terminal.cpp" > CMakeFiles/bit.dir/src/interactive_terminal.cpp.i

CMakeFiles/bit.dir/src/interactive_terminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bit.dir/src/interactive_terminal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/workspaces/Bit Nexustech/src/interactive_terminal.cpp" -o CMakeFiles/bit.dir/src/interactive_terminal.cpp.s

CMakeFiles/bit.dir/src/Bit.cpp.o: CMakeFiles/bit.dir/flags.make
CMakeFiles/bit.dir/src/Bit.cpp.o: ../src/Bit.cpp
CMakeFiles/bit.dir/src/Bit.cpp.o: CMakeFiles/bit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/workspaces/Bit Nexustech/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bit.dir/src/Bit.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bit.dir/src/Bit.cpp.o -MF CMakeFiles/bit.dir/src/Bit.cpp.o.d -o CMakeFiles/bit.dir/src/Bit.cpp.o -c "/workspaces/Bit Nexustech/src/Bit.cpp"

CMakeFiles/bit.dir/src/Bit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bit.dir/src/Bit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/workspaces/Bit Nexustech/src/Bit.cpp" > CMakeFiles/bit.dir/src/Bit.cpp.i

CMakeFiles/bit.dir/src/Bit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bit.dir/src/Bit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/workspaces/Bit Nexustech/src/Bit.cpp" -o CMakeFiles/bit.dir/src/Bit.cpp.s

# Object files for target bit
bit_OBJECTS = \
"CMakeFiles/bit.dir/src/main.cpp.o" \
"CMakeFiles/bit.dir/src/interactive_terminal.cpp.o" \
"CMakeFiles/bit.dir/src/Bit.cpp.o"

# External object files for target bit
bit_EXTERNAL_OBJECTS =

bit: CMakeFiles/bit.dir/src/main.cpp.o
bit: CMakeFiles/bit.dir/src/interactive_terminal.cpp.o
bit: CMakeFiles/bit.dir/src/Bit.cpp.o
bit: CMakeFiles/bit.dir/build.make
bit: CMakeFiles/bit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/workspaces/Bit Nexustech/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bit.dir/build: bit
.PHONY : CMakeFiles/bit.dir/build

CMakeFiles/bit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bit.dir/clean

CMakeFiles/bit.dir/depend:
	cd "/workspaces/Bit Nexustech/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/workspaces/Bit Nexustech" "/workspaces/Bit Nexustech" "/workspaces/Bit Nexustech/build" "/workspaces/Bit Nexustech/build" "/workspaces/Bit Nexustech/build/CMakeFiles/bit.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bit.dir/depend

