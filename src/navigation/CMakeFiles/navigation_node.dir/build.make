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
CMAKE_SOURCE_DIR = /home/greg/trobo_cpp/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/greg/trobo_cpp/src

# Include any dependencies generated for this target.
include navigation/CMakeFiles/navigation_node.dir/depend.make

# Include the progress variables for this target.
include navigation/CMakeFiles/navigation_node.dir/progress.make

# Include the compile flags for this target's objects.
include navigation/CMakeFiles/navigation_node.dir/flags.make

navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o: navigation/CMakeFiles/navigation_node.dir/flags.make
navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o: navigation/src/navigation_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/trobo_cpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o -c /home/greg/trobo_cpp/src/navigation/src/navigation_node.cpp

navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/navigation_node.dir/src/navigation_node.cpp.i"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/greg/trobo_cpp/src/navigation/src/navigation_node.cpp > CMakeFiles/navigation_node.dir/src/navigation_node.cpp.i

navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/navigation_node.dir/src/navigation_node.cpp.s"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/greg/trobo_cpp/src/navigation/src/navigation_node.cpp -o CMakeFiles/navigation_node.dir/src/navigation_node.cpp.s

navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.requires:

.PHONY : navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.requires

navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.provides: navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.requires
	$(MAKE) -f navigation/CMakeFiles/navigation_node.dir/build.make navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.provides.build
.PHONY : navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.provides

navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.provides.build: navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o


navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o: navigation/CMakeFiles/navigation_node.dir/flags.make
navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o: navigation/src/navigator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/trobo_cpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/navigation_node.dir/src/navigator.cpp.o -c /home/greg/trobo_cpp/src/navigation/src/navigator.cpp

navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/navigation_node.dir/src/navigator.cpp.i"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/greg/trobo_cpp/src/navigation/src/navigator.cpp > CMakeFiles/navigation_node.dir/src/navigator.cpp.i

navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/navigation_node.dir/src/navigator.cpp.s"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/greg/trobo_cpp/src/navigation/src/navigator.cpp -o CMakeFiles/navigation_node.dir/src/navigator.cpp.s

navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.requires:

.PHONY : navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.requires

navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.provides: navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.requires
	$(MAKE) -f navigation/CMakeFiles/navigation_node.dir/build.make navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.provides.build
.PHONY : navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.provides

navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.provides.build: navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o


navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o: navigation/CMakeFiles/navigation_node.dir/flags.make
navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o: navigation/src/BoxTracker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/trobo_cpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o -c /home/greg/trobo_cpp/src/navigation/src/BoxTracker.cpp

navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.i"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/greg/trobo_cpp/src/navigation/src/BoxTracker.cpp > CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.i

navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.s"
	cd /home/greg/trobo_cpp/src/navigation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/greg/trobo_cpp/src/navigation/src/BoxTracker.cpp -o CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.s

navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.requires:

.PHONY : navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.requires

navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.provides: navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.requires
	$(MAKE) -f navigation/CMakeFiles/navigation_node.dir/build.make navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.provides.build
.PHONY : navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.provides

navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.provides.build: navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o


# Object files for target navigation_node
navigation_node_OBJECTS = \
"CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o" \
"CMakeFiles/navigation_node.dir/src/navigator.cpp.o" \
"CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o"

# External object files for target navigation_node
navigation_node_EXTERNAL_OBJECTS =

devel/lib/navigation/navigation_node: navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o
devel/lib/navigation/navigation_node: navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o
devel/lib/navigation/navigation_node: navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o
devel/lib/navigation/navigation_node: navigation/CMakeFiles/navigation_node.dir/build.make
devel/lib/navigation/navigation_node: devel/lib/libsrv_wrapper.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/libroscpp.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/librosconsole.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/librosconsole_log4cxx.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/librosconsole_backend_interface.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/libroscpp_serialization.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/libxmlrpcpp.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/librostime.so
devel/lib/navigation/navigation_node: /opt/ros/melodic/lib/libcpp_common.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/navigation/navigation_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
devel/lib/navigation/navigation_node: navigation/CMakeFiles/navigation_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/greg/trobo_cpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../devel/lib/navigation/navigation_node"
	cd /home/greg/trobo_cpp/src/navigation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/navigation_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
navigation/CMakeFiles/navigation_node.dir/build: devel/lib/navigation/navigation_node

.PHONY : navigation/CMakeFiles/navigation_node.dir/build

navigation/CMakeFiles/navigation_node.dir/requires: navigation/CMakeFiles/navigation_node.dir/src/navigation_node.cpp.o.requires
navigation/CMakeFiles/navigation_node.dir/requires: navigation/CMakeFiles/navigation_node.dir/src/navigator.cpp.o.requires
navigation/CMakeFiles/navigation_node.dir/requires: navigation/CMakeFiles/navigation_node.dir/src/BoxTracker.cpp.o.requires

.PHONY : navigation/CMakeFiles/navigation_node.dir/requires

navigation/CMakeFiles/navigation_node.dir/clean:
	cd /home/greg/trobo_cpp/src/navigation && $(CMAKE_COMMAND) -P CMakeFiles/navigation_node.dir/cmake_clean.cmake
.PHONY : navigation/CMakeFiles/navigation_node.dir/clean

navigation/CMakeFiles/navigation_node.dir/depend:
	cd /home/greg/trobo_cpp/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/greg/trobo_cpp/src /home/greg/trobo_cpp/src/navigation /home/greg/trobo_cpp/src /home/greg/trobo_cpp/src/navigation /home/greg/trobo_cpp/src/navigation/CMakeFiles/navigation_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : navigation/CMakeFiles/navigation_node.dir/depend

