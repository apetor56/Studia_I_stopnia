# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\build"

# Include any dependencies generated for this target.
include CMakeFiles/SetLinked.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SetLinked.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SetLinked.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SetLinked.dir/flags.make

CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj: CMakeFiles/SetLinked.dir/flags.make
CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj: CMakeFiles/SetLinked.dir/includes_CXX.rsp
CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj: ../src/SetLinked.cpp
CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj: CMakeFiles/SetLinked.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj -MF CMakeFiles\SetLinked.dir\src\SetLinked.cpp.obj.d -o CMakeFiles\SetLinked.dir\src\SetLinked.cpp.obj -c "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\src\SetLinked.cpp"

CMakeFiles/SetLinked.dir/src/SetLinked.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SetLinked.dir/src/SetLinked.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\src\SetLinked.cpp" > CMakeFiles\SetLinked.dir\src\SetLinked.cpp.i

CMakeFiles/SetLinked.dir/src/SetLinked.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SetLinked.dir/src/SetLinked.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\src\SetLinked.cpp" -o CMakeFiles\SetLinked.dir\src\SetLinked.cpp.s

# Object files for target SetLinked
SetLinked_OBJECTS = \
"CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj"

# External object files for target SetLinked
SetLinked_EXTERNAL_OBJECTS =

../out/SetLinked.exe: CMakeFiles/SetLinked.dir/src/SetLinked.cpp.obj
../out/SetLinked.exe: CMakeFiles/SetLinked.dir/build.make
../out/SetLinked.exe: CMakeFiles/SetLinked.dir/linklibs.rsp
../out/SetLinked.exe: CMakeFiles/SetLinked.dir/objects1.rsp
../out/SetLinked.exe: CMakeFiles/SetLinked.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\out\SetLinked.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SetLinked.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SetLinked.dir/build: ../out/SetLinked.exe
.PHONY : CMakeFiles/SetLinked.dir/build

CMakeFiles/SetLinked.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SetLinked.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SetLinked.dir/clean

CMakeFiles/SetLinked.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01" "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01" "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\build" "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\build" "C:\Users\Lukasz Tenerowicz\Desktop\ASD2\Zestaw01\build\CMakeFiles\SetLinked.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SetLinked.dir/depend

