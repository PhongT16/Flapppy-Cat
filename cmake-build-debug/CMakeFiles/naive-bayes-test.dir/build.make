# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /private/var/folders/9z/t2v795kn50b92vbm686c2n0c0000gn/T/AppTranslocation/0181007C-16AB-4F95-A039-B26AF8FF9800/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/9z/t2v795kn50b92vbm686c2n0c0000gn/T/AppTranslocation/0181007C-16AB-4F95-A039-B26AF8FF9800/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/naive-bayes-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/naive-bayes-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/naive-bayes-test.dir/flags.make

Debug/naive-bayes-test/naive-bayes-test.app/Contents/Resources/CinderApp.icns: /Users/phongtran/Downloads/cinder_0.9.2_mac/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/naive-bayes-test/naive-bayes-test.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/phongtran/Downloads/cinder_0.9.2_mac/samples/data/CinderApp.icns Debug/naive-bayes-test/naive-bayes-test.app/Contents/Resources/CinderApp.icns

CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.o: CMakeFiles/naive-bayes-test.dir/flags.make
CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.o: ../tests/test_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/tests/test_main.cc

CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/tests/test_main.cc > CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.i

CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/tests/test_main.cc -o CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.s

CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.o: CMakeFiles/naive-bayes-test.dir/flags.make
CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.o: ../src/core/rename_this_file.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/core/rename_this_file.cc

CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/core/rename_this_file.cc > CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.i

CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/core/rename_this_file.cc -o CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.s

CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.o: CMakeFiles/naive-bayes-test.dir/flags.make
CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.o: ../src/visualizer/naive_bayes_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/naive_bayes_app.cc

CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/naive_bayes_app.cc > CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.i

CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/naive_bayes_app.cc -o CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.s

CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.o: CMakeFiles/naive-bayes-test.dir/flags.make
CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.o: ../src/visualizer/sketchpad.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sketchpad.cc

CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sketchpad.cc > CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.i

CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sketchpad.cc -o CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.s

CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.o: CMakeFiles/naive-bayes-test.dir/flags.make
CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.o: ../src/visualizer/sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sprite.cpp

CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sprite.cpp > CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.i

CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sprite.cpp -o CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.s

CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.o: CMakeFiles/naive-bayes-test.dir/flags.make
CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.o: ../src/visualizer/pipe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/pipe.cpp

CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/pipe.cpp > CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.i

CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/pipe.cpp -o CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.s

CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.o: CMakeFiles/naive-bayes-test.dir/flags.make
CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.o: ../tests/rename_this_test_file.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/tests/rename_this_test_file.cc

CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/tests/rename_this_test_file.cc > CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.i

CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/tests/rename_this_test_file.cc -o CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.s

# Object files for target naive-bayes-test
naive__bayes__test_OBJECTS = \
"CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.o" \
"CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.o" \
"CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.o" \
"CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.o" \
"CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.o" \
"CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.o" \
"CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.o"

# External object files for target naive-bayes-test
naive__bayes__test_EXTERNAL_OBJECTS =

Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/tests/test_main.cc.o
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/src/core/rename_this_file.cc.o
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/src/visualizer/naive_bayes_app.cc.o
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/src/visualizer/sketchpad.cc.o
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/src/visualizer/sprite.cpp.o
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/src/visualizer/pipe.cpp.o
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/tests/rename_this_test_file.cc.o
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/build.make
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: /Users/phongtran/Downloads/cinder_0.9.2_mac/lib/macosx/Debug/libcinder.a
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: /Users/phongtran/Downloads/cinder_0.9.2_mac/lib/macosx/libboost_system.a
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: /Users/phongtran/Downloads/cinder_0.9.2_mac/lib/macosx/libboost_filesystem.a
Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test: CMakeFiles/naive-bayes-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/naive-bayes-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/naive-bayes-test.dir/build: Debug/naive-bayes-test/naive-bayes-test.app/Contents/MacOS/naive-bayes-test
CMakeFiles/naive-bayes-test.dir/build: Debug/naive-bayes-test/naive-bayes-test.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/naive-bayes-test.dir/build

CMakeFiles/naive-bayes-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/naive-bayes-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/naive-bayes-test.dir/clean

CMakeFiles/naive-bayes-test.dir/depend:
	cd /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16 /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16 /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles/naive-bayes-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/naive-bayes-test.dir/depend
