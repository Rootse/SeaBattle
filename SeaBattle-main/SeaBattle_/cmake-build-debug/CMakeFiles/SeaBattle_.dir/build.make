# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SeaBattle_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SeaBattle_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SeaBattle_.dir/flags.make

CMakeFiles/SeaBattle_.dir/main.cpp.obj: CMakeFiles/SeaBattle_.dir/flags.make
CMakeFiles/SeaBattle_.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SeaBattle_.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SeaBattle_.dir\main.cpp.obj -c C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\main.cpp

CMakeFiles/SeaBattle_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SeaBattle_.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\main.cpp > CMakeFiles\SeaBattle_.dir\main.cpp.i

CMakeFiles/SeaBattle_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SeaBattle_.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\main.cpp -o CMakeFiles\SeaBattle_.dir\main.cpp.s

CMakeFiles/SeaBattle_.dir/GameField.cpp.obj: CMakeFiles/SeaBattle_.dir/flags.make
CMakeFiles/SeaBattle_.dir/GameField.cpp.obj: ../GameField.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SeaBattle_.dir/GameField.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SeaBattle_.dir\GameField.cpp.obj -c C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\GameField.cpp

CMakeFiles/SeaBattle_.dir/GameField.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SeaBattle_.dir/GameField.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\GameField.cpp > CMakeFiles\SeaBattle_.dir\GameField.cpp.i

CMakeFiles/SeaBattle_.dir/GameField.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SeaBattle_.dir/GameField.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\GameField.cpp -o CMakeFiles\SeaBattle_.dir\GameField.cpp.s

CMakeFiles/SeaBattle_.dir/Ships.cpp.obj: CMakeFiles/SeaBattle_.dir/flags.make
CMakeFiles/SeaBattle_.dir/Ships.cpp.obj: ../Ships.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SeaBattle_.dir/Ships.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SeaBattle_.dir\Ships.cpp.obj -c C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\Ships.cpp

CMakeFiles/SeaBattle_.dir/Ships.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SeaBattle_.dir/Ships.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\Ships.cpp > CMakeFiles\SeaBattle_.dir\Ships.cpp.i

CMakeFiles/SeaBattle_.dir/Ships.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SeaBattle_.dir/Ships.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\Ships.cpp -o CMakeFiles\SeaBattle_.dir\Ships.cpp.s

CMakeFiles/SeaBattle_.dir/Game.cpp.obj: CMakeFiles/SeaBattle_.dir/flags.make
CMakeFiles/SeaBattle_.dir/Game.cpp.obj: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SeaBattle_.dir/Game.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SeaBattle_.dir\Game.cpp.obj -c C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\Game.cpp

CMakeFiles/SeaBattle_.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SeaBattle_.dir/Game.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\Game.cpp > CMakeFiles\SeaBattle_.dir\Game.cpp.i

CMakeFiles/SeaBattle_.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SeaBattle_.dir/Game.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\Game.cpp -o CMakeFiles\SeaBattle_.dir\Game.cpp.s

# Object files for target SeaBattle_
SeaBattle__OBJECTS = \
"CMakeFiles/SeaBattle_.dir/main.cpp.obj" \
"CMakeFiles/SeaBattle_.dir/GameField.cpp.obj" \
"CMakeFiles/SeaBattle_.dir/Ships.cpp.obj" \
"CMakeFiles/SeaBattle_.dir/Game.cpp.obj"

# External object files for target SeaBattle_
SeaBattle__EXTERNAL_OBJECTS =

SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/main.cpp.obj
SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/GameField.cpp.obj
SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/Ships.cpp.obj
SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/Game.cpp.obj
SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/build.make
SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/linklibs.rsp
SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/objects1.rsp
SeaBattle_.exe: CMakeFiles/SeaBattle_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SeaBattle_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SeaBattle_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SeaBattle_.dir/build: SeaBattle_.exe

.PHONY : CMakeFiles/SeaBattle_.dir/build

CMakeFiles/SeaBattle_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SeaBattle_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SeaBattle_.dir/clean

CMakeFiles/SeaBattle_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_ C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_ C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug C:\Users\Yan\Desktop\SeaBattle-main\SeaBattle_\cmake-build-debug\CMakeFiles\SeaBattle_.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SeaBattle_.dir/depend

