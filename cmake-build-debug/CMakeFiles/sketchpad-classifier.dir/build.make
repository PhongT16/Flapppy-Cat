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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sketchpad-classifier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sketchpad-classifier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sketchpad-classifier.dir/flags.make

Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns: /Users/phongtran/Downloads/cinder_0.9.2_mac/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/phongtran/Downloads/cinder_0.9.2_mac/samples/data/CinderApp.icns Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns

CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o: ../apps/cinder_app_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/apps/cinder_app_main.cc

CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/apps/cinder_app_main.cc > CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.i

CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/apps/cinder_app_main.cc -o CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.s

CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.o: ../src/core/rename_this_file.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/core/rename_this_file.cc

CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/core/rename_this_file.cc > CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.i

CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/core/rename_this_file.cc -o CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.s

CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.o: ../src/visualizer/jetpack_cat.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/jetpack_cat.cc

CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/jetpack_cat.cc > CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.i

CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/jetpack_cat.cc -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.s

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o: ../src/visualizer/sketchpad.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sketchpad.cc

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sketchpad.cc > CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.i

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sketchpad.cc -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.s

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.o: ../src/visualizer/sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sprite.cpp

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sprite.cpp > CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.i

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/sprite.cpp -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.s

CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.o: ../src/visualizer/pipe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.o -c /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/pipe.cpp

CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/pipe.cpp > CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.i

CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/src/visualizer/pipe.cpp -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.s

# Object files for target sketchpad-classifier
sketchpad__classifier_OBJECTS = \
"CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.o" \
"CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.o"

# External object files for target sketchpad-classifier
sketchpad__classifier_EXTERNAL_OBJECTS =

Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/core/rename_this_file.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/visualizer/jetpack_cat.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/visualizer/sprite.cpp.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/visualizer/pipe.cpp.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/build.make
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: /Users/phongtran/Downloads/cinder_0.9.2_mac/lib/macosx/Debug/libcinder.a
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: /Users/phongtran/Downloads/cinder_0.9.2_mac/lib/macosx/libboost_system.a
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: /Users/phongtran/Downloads/cinder_0.9.2_mac/lib/macosx/libboost_filesystem.a
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sketchpad-classifier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sketchpad-classifier.dir/build: Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier
CMakeFiles/sketchpad-classifier.dir/build: Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/sketchpad-classifier.dir/build

CMakeFiles/sketchpad-classifier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sketchpad-classifier.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sketchpad-classifier.dir/clean

CMakeFiles/sketchpad-classifier.dir/depend:
	cd /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16 /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16 /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug /Users/phongtran/Downloads/cinder_0.9.2_mac/my-projects/final-project-PhongT16/cmake-build-debug/CMakeFiles/sketchpad-classifier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sketchpad-classifier.dir/depend

