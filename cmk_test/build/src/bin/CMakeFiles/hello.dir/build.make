# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chenjian/workspace/test/cmk_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chenjian/workspace/test/cmk_test/build

# Include any dependencies generated for this target.
include src/bin/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include src/bin/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include src/bin/CMakeFiles/hello.dir/flags.make

src/bin/CMakeFiles/hello.dir/main.o: src/bin/CMakeFiles/hello.dir/flags.make
src/bin/CMakeFiles/hello.dir/main.o: ../src/hello/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chenjian/workspace/test/cmk_test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bin/CMakeFiles/hello.dir/main.o"
	cd /home/chenjian/workspace/test/cmk_test/build/src/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/main.o -c /home/chenjian/workspace/test/cmk_test/src/hello/main.cpp

src/bin/CMakeFiles/hello.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/main.i"
	cd /home/chenjian/workspace/test/cmk_test/build/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chenjian/workspace/test/cmk_test/src/hello/main.cpp > CMakeFiles/hello.dir/main.i

src/bin/CMakeFiles/hello.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/main.s"
	cd /home/chenjian/workspace/test/cmk_test/build/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chenjian/workspace/test/cmk_test/src/hello/main.cpp -o CMakeFiles/hello.dir/main.s

src/bin/CMakeFiles/hello.dir/main.o.requires:
.PHONY : src/bin/CMakeFiles/hello.dir/main.o.requires

src/bin/CMakeFiles/hello.dir/main.o.provides: src/bin/CMakeFiles/hello.dir/main.o.requires
	$(MAKE) -f src/bin/CMakeFiles/hello.dir/build.make src/bin/CMakeFiles/hello.dir/main.o.provides.build
.PHONY : src/bin/CMakeFiles/hello.dir/main.o.provides

src/bin/CMakeFiles/hello.dir/main.o.provides.build: src/bin/CMakeFiles/hello.dir/main.o

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/main.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

src/bin/hello: src/bin/CMakeFiles/hello.dir/main.o
src/bin/hello: src/bin/CMakeFiles/hello.dir/build.make
src/bin/hello: src/util/libutil.a
src/bin/hello: src/bin/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable hello"
	cd /home/chenjian/workspace/test/cmk_test/build/src/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/bin/CMakeFiles/hello.dir/build: src/bin/hello
.PHONY : src/bin/CMakeFiles/hello.dir/build

src/bin/CMakeFiles/hello.dir/requires: src/bin/CMakeFiles/hello.dir/main.o.requires
.PHONY : src/bin/CMakeFiles/hello.dir/requires

src/bin/CMakeFiles/hello.dir/clean:
	cd /home/chenjian/workspace/test/cmk_test/build/src/bin && $(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : src/bin/CMakeFiles/hello.dir/clean

src/bin/CMakeFiles/hello.dir/depend:
	cd /home/chenjian/workspace/test/cmk_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chenjian/workspace/test/cmk_test /home/chenjian/workspace/test/cmk_test/src/hello /home/chenjian/workspace/test/cmk_test/build /home/chenjian/workspace/test/cmk_test/build/src/bin /home/chenjian/workspace/test/cmk_test/build/src/bin/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/bin/CMakeFiles/hello.dir/depend
