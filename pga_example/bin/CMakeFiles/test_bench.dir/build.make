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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /vagrant/adc_systemc/pga_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant/adc_systemc/pga_example

# Include any dependencies generated for this target.
include bin/CMakeFiles/test_bench.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/test_bench.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/test_bench.dir/flags.make

bin/CMakeFiles/test_bench.dir/main.cpp.o: bin/CMakeFiles/test_bench.dir/flags.make
bin/CMakeFiles/test_bench.dir/main.cpp.o: test_modules/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /vagrant/adc_systemc/pga_example/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/test_bench.dir/main.cpp.o"
	cd /vagrant/adc_systemc/pga_example/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_bench.dir/main.cpp.o -c /vagrant/adc_systemc/pga_example/test_modules/main.cpp

bin/CMakeFiles/test_bench.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_bench.dir/main.cpp.i"
	cd /vagrant/adc_systemc/pga_example/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /vagrant/adc_systemc/pga_example/test_modules/main.cpp > CMakeFiles/test_bench.dir/main.cpp.i

bin/CMakeFiles/test_bench.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_bench.dir/main.cpp.s"
	cd /vagrant/adc_systemc/pga_example/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /vagrant/adc_systemc/pga_example/test_modules/main.cpp -o CMakeFiles/test_bench.dir/main.cpp.s

bin/CMakeFiles/test_bench.dir/main.cpp.o.requires:
.PHONY : bin/CMakeFiles/test_bench.dir/main.cpp.o.requires

bin/CMakeFiles/test_bench.dir/main.cpp.o.provides: bin/CMakeFiles/test_bench.dir/main.cpp.o.requires
	$(MAKE) -f bin/CMakeFiles/test_bench.dir/build.make bin/CMakeFiles/test_bench.dir/main.cpp.o.provides.build
.PHONY : bin/CMakeFiles/test_bench.dir/main.cpp.o.provides

bin/CMakeFiles/test_bench.dir/main.cpp.o.provides.build: bin/CMakeFiles/test_bench.dir/main.cpp.o

# Object files for target test_bench
test_bench_OBJECTS = \
"CMakeFiles/test_bench.dir/main.cpp.o"

# External object files for target test_bench
test_bench_EXTERNAL_OBJECTS =

bin/test_bench: bin/CMakeFiles/test_bench.dir/main.cpp.o
bin/test_bench: bin/CMakeFiles/test_bench.dir/build.make
bin/test_bench: /usr/local/systemc/lib-linux/libsystemc.so
bin/test_bench: /usr/local/systemc-ams/lib-linux/libsystemc-ams.a
bin/test_bench: bin/CMakeFiles/test_bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test_bench"
	cd /vagrant/adc_systemc/pga_example/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/test_bench.dir/build: bin/test_bench
.PHONY : bin/CMakeFiles/test_bench.dir/build

bin/CMakeFiles/test_bench.dir/requires: bin/CMakeFiles/test_bench.dir/main.cpp.o.requires
.PHONY : bin/CMakeFiles/test_bench.dir/requires

bin/CMakeFiles/test_bench.dir/clean:
	cd /vagrant/adc_systemc/pga_example/bin && $(CMAKE_COMMAND) -P CMakeFiles/test_bench.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/test_bench.dir/clean

bin/CMakeFiles/test_bench.dir/depend:
	cd /vagrant/adc_systemc/pga_example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/adc_systemc/pga_example /vagrant/adc_systemc/pga_example/test_modules /vagrant/adc_systemc/pga_example /vagrant/adc_systemc/pga_example/bin /vagrant/adc_systemc/pga_example/bin/CMakeFiles/test_bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/test_bench.dir/depend

