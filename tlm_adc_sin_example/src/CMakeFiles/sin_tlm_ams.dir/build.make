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
CMAKE_SOURCE_DIR = /vagrant/adc_systemc/tlm_adc_sin_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant/adc_systemc/tlm_adc_sin_example

# Include any dependencies generated for this target.
include src/CMakeFiles/sin_tlm_ams.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/sin_tlm_ams.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/sin_tlm_ams.dir/flags.make

src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o: src/CMakeFiles/sin_tlm_ams.dir/flags.make
src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o: src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /vagrant/adc_systemc/tlm_adc_sin_example/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o"
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sin_tlm_ams.dir/main.cpp.o -c /vagrant/adc_systemc/tlm_adc_sin_example/src/main.cpp

src/CMakeFiles/sin_tlm_ams.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sin_tlm_ams.dir/main.cpp.i"
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /vagrant/adc_systemc/tlm_adc_sin_example/src/main.cpp > CMakeFiles/sin_tlm_ams.dir/main.cpp.i

src/CMakeFiles/sin_tlm_ams.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sin_tlm_ams.dir/main.cpp.s"
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /vagrant/adc_systemc/tlm_adc_sin_example/src/main.cpp -o CMakeFiles/sin_tlm_ams.dir/main.cpp.s

src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.requires:
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.requires

src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.provides: src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/sin_tlm_ams.dir/build.make src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.provides

src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.provides.build: src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o

src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o: src/CMakeFiles/sin_tlm_ams.dir/flags.make
src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o: src/tuv_ams_library.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /vagrant/adc_systemc/tlm_adc_sin_example/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o"
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o -c /vagrant/adc_systemc/tlm_adc_sin_example/src/tuv_ams_library.cpp

src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.i"
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /vagrant/adc_systemc/tlm_adc_sin_example/src/tuv_ams_library.cpp > CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.i

src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.s"
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /vagrant/adc_systemc/tlm_adc_sin_example/src/tuv_ams_library.cpp -o CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.s

src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.requires:
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.requires

src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.provides: src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/sin_tlm_ams.dir/build.make src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.provides.build
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.provides

src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.provides.build: src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o

# Object files for target sin_tlm_ams
sin_tlm_ams_OBJECTS = \
"CMakeFiles/sin_tlm_ams.dir/main.cpp.o" \
"CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o"

# External object files for target sin_tlm_ams
sin_tlm_ams_EXTERNAL_OBJECTS =

bin/sin_tlm_ams: src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o
bin/sin_tlm_ams: src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o
bin/sin_tlm_ams: src/CMakeFiles/sin_tlm_ams.dir/build.make
bin/sin_tlm_ams: /usr/local/systemc/lib-linux/libsystemc.so
bin/sin_tlm_ams: /usr/local/systemc-ams/lib-linux/libsystemc-ams.a
bin/sin_tlm_ams: src/CMakeFiles/sin_tlm_ams.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/sin_tlm_ams"
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sin_tlm_ams.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/sin_tlm_ams.dir/build: bin/sin_tlm_ams
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/build

src/CMakeFiles/sin_tlm_ams.dir/requires: src/CMakeFiles/sin_tlm_ams.dir/main.cpp.o.requires
src/CMakeFiles/sin_tlm_ams.dir/requires: src/CMakeFiles/sin_tlm_ams.dir/tuv_ams_library.cpp.o.requires
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/requires

src/CMakeFiles/sin_tlm_ams.dir/clean:
	cd /vagrant/adc_systemc/tlm_adc_sin_example/src && $(CMAKE_COMMAND) -P CMakeFiles/sin_tlm_ams.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/clean

src/CMakeFiles/sin_tlm_ams.dir/depend:
	cd /vagrant/adc_systemc/tlm_adc_sin_example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/adc_systemc/tlm_adc_sin_example /vagrant/adc_systemc/tlm_adc_sin_example/src /vagrant/adc_systemc/tlm_adc_sin_example /vagrant/adc_systemc/tlm_adc_sin_example/src /vagrant/adc_systemc/tlm_adc_sin_example/src/CMakeFiles/sin_tlm_ams.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/sin_tlm_ams.dir/depend

