# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/keltar/Downloads/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/keltar/Downloads/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/keltar/Desktop/Computer-Graphics/CG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CG.dir/flags.make

CMakeFiles/CG.dir/src/main.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CG.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/main.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/main.cpp

CMakeFiles/CG.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/main.cpp > CMakeFiles/CG.dir/src/main.cpp.i

CMakeFiles/CG.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/main.cpp -o CMakeFiles/CG.dir/src/main.cpp.s

CMakeFiles/CG.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/main.cpp.o.requires

CMakeFiles/CG.dir/src/main.cpp.o.provides: CMakeFiles/CG.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/main.cpp.o.provides

CMakeFiles/CG.dir/src/main.cpp.o.provides.build: CMakeFiles/CG.dir/src/main.cpp.o


CMakeFiles/CG.dir/src/Shader.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CG.dir/src/Shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Shader.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Shader.cpp

CMakeFiles/CG.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Shader.cpp > CMakeFiles/CG.dir/src/Shader.cpp.i

CMakeFiles/CG.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Shader.cpp -o CMakeFiles/CG.dir/src/Shader.cpp.s

CMakeFiles/CG.dir/src/Shader.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Shader.cpp.o.requires

CMakeFiles/CG.dir/src/Shader.cpp.o.provides: CMakeFiles/CG.dir/src/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Shader.cpp.o.provides

CMakeFiles/CG.dir/src/Shader.cpp.o.provides.build: CMakeFiles/CG.dir/src/Shader.cpp.o


CMakeFiles/CG.dir/src/ShaderProgram.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/ShaderProgram.cpp.o: ../src/ShaderProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CG.dir/src/ShaderProgram.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/ShaderProgram.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/ShaderProgram.cpp

CMakeFiles/CG.dir/src/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/ShaderProgram.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/ShaderProgram.cpp > CMakeFiles/CG.dir/src/ShaderProgram.cpp.i

CMakeFiles/CG.dir/src/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/ShaderProgram.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/ShaderProgram.cpp -o CMakeFiles/CG.dir/src/ShaderProgram.cpp.s

CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.requires

CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.provides: CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.provides

CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.provides.build: CMakeFiles/CG.dir/src/ShaderProgram.cpp.o


CMakeFiles/CG.dir/src/Window.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CG.dir/src/Window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Window.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Window.cpp

CMakeFiles/CG.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Window.cpp > CMakeFiles/CG.dir/src/Window.cpp.i

CMakeFiles/CG.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Window.cpp -o CMakeFiles/CG.dir/src/Window.cpp.s

CMakeFiles/CG.dir/src/Window.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Window.cpp.o.requires

CMakeFiles/CG.dir/src/Window.cpp.o.provides: CMakeFiles/CG.dir/src/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Window.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Window.cpp.o.provides

CMakeFiles/CG.dir/src/Window.cpp.o.provides.build: CMakeFiles/CG.dir/src/Window.cpp.o


CMakeFiles/CG.dir/src/Matrix4.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Matrix4.cpp.o: ../src/Matrix4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CG.dir/src/Matrix4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Matrix4.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Matrix4.cpp

CMakeFiles/CG.dir/src/Matrix4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Matrix4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Matrix4.cpp > CMakeFiles/CG.dir/src/Matrix4.cpp.i

CMakeFiles/CG.dir/src/Matrix4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Matrix4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Matrix4.cpp -o CMakeFiles/CG.dir/src/Matrix4.cpp.s

CMakeFiles/CG.dir/src/Matrix4.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Matrix4.cpp.o.requires

CMakeFiles/CG.dir/src/Matrix4.cpp.o.provides: CMakeFiles/CG.dir/src/Matrix4.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Matrix4.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Matrix4.cpp.o.provides

CMakeFiles/CG.dir/src/Matrix4.cpp.o.provides.build: CMakeFiles/CG.dir/src/Matrix4.cpp.o


CMakeFiles/CG.dir/src/Quaternion.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Quaternion.cpp.o: ../src/Quaternion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CG.dir/src/Quaternion.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Quaternion.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Quaternion.cpp

CMakeFiles/CG.dir/src/Quaternion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Quaternion.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Quaternion.cpp > CMakeFiles/CG.dir/src/Quaternion.cpp.i

CMakeFiles/CG.dir/src/Quaternion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Quaternion.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Quaternion.cpp -o CMakeFiles/CG.dir/src/Quaternion.cpp.s

CMakeFiles/CG.dir/src/Quaternion.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Quaternion.cpp.o.requires

CMakeFiles/CG.dir/src/Quaternion.cpp.o.provides: CMakeFiles/CG.dir/src/Quaternion.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Quaternion.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Quaternion.cpp.o.provides

CMakeFiles/CG.dir/src/Quaternion.cpp.o.provides.build: CMakeFiles/CG.dir/src/Quaternion.cpp.o


CMakeFiles/CG.dir/src/gl_math.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/gl_math.cpp.o: ../src/gl_math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CG.dir/src/gl_math.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/gl_math.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/gl_math.cpp

CMakeFiles/CG.dir/src/gl_math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/gl_math.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/gl_math.cpp > CMakeFiles/CG.dir/src/gl_math.cpp.i

CMakeFiles/CG.dir/src/gl_math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/gl_math.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/gl_math.cpp -o CMakeFiles/CG.dir/src/gl_math.cpp.s

CMakeFiles/CG.dir/src/gl_math.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/gl_math.cpp.o.requires

CMakeFiles/CG.dir/src/gl_math.cpp.o.provides: CMakeFiles/CG.dir/src/gl_math.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/gl_math.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/gl_math.cpp.o.provides

CMakeFiles/CG.dir/src/gl_math.cpp.o.provides.build: CMakeFiles/CG.dir/src/gl_math.cpp.o


CMakeFiles/CG.dir/src/Camera.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Camera.cpp.o: ../src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CG.dir/src/Camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Camera.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Camera.cpp

CMakeFiles/CG.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Camera.cpp > CMakeFiles/CG.dir/src/Camera.cpp.i

CMakeFiles/CG.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Camera.cpp -o CMakeFiles/CG.dir/src/Camera.cpp.s

CMakeFiles/CG.dir/src/Camera.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Camera.cpp.o.requires

CMakeFiles/CG.dir/src/Camera.cpp.o.provides: CMakeFiles/CG.dir/src/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Camera.cpp.o.provides

CMakeFiles/CG.dir/src/Camera.cpp.o.provides.build: CMakeFiles/CG.dir/src/Camera.cpp.o


CMakeFiles/CG.dir/src/EventHandler.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/EventHandler.cpp.o: ../src/EventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CG.dir/src/EventHandler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/EventHandler.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/EventHandler.cpp

CMakeFiles/CG.dir/src/EventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/EventHandler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/EventHandler.cpp > CMakeFiles/CG.dir/src/EventHandler.cpp.i

CMakeFiles/CG.dir/src/EventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/EventHandler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/EventHandler.cpp -o CMakeFiles/CG.dir/src/EventHandler.cpp.s

CMakeFiles/CG.dir/src/EventHandler.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/EventHandler.cpp.o.requires

CMakeFiles/CG.dir/src/EventHandler.cpp.o.provides: CMakeFiles/CG.dir/src/EventHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/EventHandler.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/EventHandler.cpp.o.provides

CMakeFiles/CG.dir/src/EventHandler.cpp.o.provides.build: CMakeFiles/CG.dir/src/EventHandler.cpp.o


CMakeFiles/CG.dir/src/Event.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Event.cpp.o: ../src/Event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/CG.dir/src/Event.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Event.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Event.cpp

CMakeFiles/CG.dir/src/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Event.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Event.cpp > CMakeFiles/CG.dir/src/Event.cpp.i

CMakeFiles/CG.dir/src/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Event.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Event.cpp -o CMakeFiles/CG.dir/src/Event.cpp.s

CMakeFiles/CG.dir/src/Event.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Event.cpp.o.requires

CMakeFiles/CG.dir/src/Event.cpp.o.provides: CMakeFiles/CG.dir/src/Event.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Event.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Event.cpp.o.provides

CMakeFiles/CG.dir/src/Event.cpp.o.provides.build: CMakeFiles/CG.dir/src/Event.cpp.o


CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o: ../src/KeyboardEventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/KeyboardEventHandler.cpp

CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/KeyboardEventHandler.cpp > CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.i

CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/KeyboardEventHandler.cpp -o CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.s

CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.requires

CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.provides: CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.provides

CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.provides.build: CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o


CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o: ../src/CameraEventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/CameraEventHandler.cpp

CMakeFiles/CG.dir/src/CameraEventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/CameraEventHandler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/CameraEventHandler.cpp > CMakeFiles/CG.dir/src/CameraEventHandler.cpp.i

CMakeFiles/CG.dir/src/CameraEventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/CameraEventHandler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/CameraEventHandler.cpp -o CMakeFiles/CG.dir/src/CameraEventHandler.cpp.s

CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.requires

CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.provides: CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.provides

CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.provides.build: CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o


CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o: ../src/MouseEventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/MouseEventHandler.cpp

CMakeFiles/CG.dir/src/MouseEventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/MouseEventHandler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/MouseEventHandler.cpp > CMakeFiles/CG.dir/src/MouseEventHandler.cpp.i

CMakeFiles/CG.dir/src/MouseEventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/MouseEventHandler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/MouseEventHandler.cpp -o CMakeFiles/CG.dir/src/MouseEventHandler.cpp.s

CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.requires

CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.provides: CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.provides

CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.provides.build: CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o


CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o: ../src/MouseEventArgs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/MouseEventArgs.cpp

CMakeFiles/CG.dir/src/MouseEventArgs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/MouseEventArgs.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/MouseEventArgs.cpp > CMakeFiles/CG.dir/src/MouseEventArgs.cpp.i

CMakeFiles/CG.dir/src/MouseEventArgs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/MouseEventArgs.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/MouseEventArgs.cpp -o CMakeFiles/CG.dir/src/MouseEventArgs.cpp.s

CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.requires

CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.provides: CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.provides

CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.provides.build: CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o


CMakeFiles/CG.dir/src/Point.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Point.cpp.o: ../src/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/CG.dir/src/Point.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Point.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Point.cpp

CMakeFiles/CG.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Point.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Point.cpp > CMakeFiles/CG.dir/src/Point.cpp.i

CMakeFiles/CG.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Point.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Point.cpp -o CMakeFiles/CG.dir/src/Point.cpp.s

CMakeFiles/CG.dir/src/Point.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Point.cpp.o.requires

CMakeFiles/CG.dir/src/Point.cpp.o.provides: CMakeFiles/CG.dir/src/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Point.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Point.cpp.o.provides

CMakeFiles/CG.dir/src/Point.cpp.o.provides.build: CMakeFiles/CG.dir/src/Point.cpp.o


CMakeFiles/CG.dir/src/Texture.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Texture.cpp.o: ../src/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/CG.dir/src/Texture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Texture.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Texture.cpp

CMakeFiles/CG.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Texture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Texture.cpp > CMakeFiles/CG.dir/src/Texture.cpp.i

CMakeFiles/CG.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Texture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Texture.cpp -o CMakeFiles/CG.dir/src/Texture.cpp.s

CMakeFiles/CG.dir/src/Texture.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Texture.cpp.o.requires

CMakeFiles/CG.dir/src/Texture.cpp.o.provides: CMakeFiles/CG.dir/src/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Texture.cpp.o.provides

CMakeFiles/CG.dir/src/Texture.cpp.o.provides.build: CMakeFiles/CG.dir/src/Texture.cpp.o


CMakeFiles/CG.dir/src/Light.cpp.o: CMakeFiles/CG.dir/flags.make
CMakeFiles/CG.dir/src/Light.cpp.o: ../src/Light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/CG.dir/src/Light.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CG.dir/src/Light.cpp.o -c /home/keltar/Desktop/Computer-Graphics/CG/src/Light.cpp

CMakeFiles/CG.dir/src/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CG.dir/src/Light.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keltar/Desktop/Computer-Graphics/CG/src/Light.cpp > CMakeFiles/CG.dir/src/Light.cpp.i

CMakeFiles/CG.dir/src/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CG.dir/src/Light.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keltar/Desktop/Computer-Graphics/CG/src/Light.cpp -o CMakeFiles/CG.dir/src/Light.cpp.s

CMakeFiles/CG.dir/src/Light.cpp.o.requires:

.PHONY : CMakeFiles/CG.dir/src/Light.cpp.o.requires

CMakeFiles/CG.dir/src/Light.cpp.o.provides: CMakeFiles/CG.dir/src/Light.cpp.o.requires
	$(MAKE) -f CMakeFiles/CG.dir/build.make CMakeFiles/CG.dir/src/Light.cpp.o.provides.build
.PHONY : CMakeFiles/CG.dir/src/Light.cpp.o.provides

CMakeFiles/CG.dir/src/Light.cpp.o.provides.build: CMakeFiles/CG.dir/src/Light.cpp.o


# Object files for target CG
CG_OBJECTS = \
"CMakeFiles/CG.dir/src/main.cpp.o" \
"CMakeFiles/CG.dir/src/Shader.cpp.o" \
"CMakeFiles/CG.dir/src/ShaderProgram.cpp.o" \
"CMakeFiles/CG.dir/src/Window.cpp.o" \
"CMakeFiles/CG.dir/src/Matrix4.cpp.o" \
"CMakeFiles/CG.dir/src/Quaternion.cpp.o" \
"CMakeFiles/CG.dir/src/gl_math.cpp.o" \
"CMakeFiles/CG.dir/src/Camera.cpp.o" \
"CMakeFiles/CG.dir/src/EventHandler.cpp.o" \
"CMakeFiles/CG.dir/src/Event.cpp.o" \
"CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o" \
"CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o" \
"CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o" \
"CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o" \
"CMakeFiles/CG.dir/src/Point.cpp.o" \
"CMakeFiles/CG.dir/src/Texture.cpp.o" \
"CMakeFiles/CG.dir/src/Light.cpp.o"

# External object files for target CG
CG_EXTERNAL_OBJECTS =

CG: CMakeFiles/CG.dir/src/main.cpp.o
CG: CMakeFiles/CG.dir/src/Shader.cpp.o
CG: CMakeFiles/CG.dir/src/ShaderProgram.cpp.o
CG: CMakeFiles/CG.dir/src/Window.cpp.o
CG: CMakeFiles/CG.dir/src/Matrix4.cpp.o
CG: CMakeFiles/CG.dir/src/Quaternion.cpp.o
CG: CMakeFiles/CG.dir/src/gl_math.cpp.o
CG: CMakeFiles/CG.dir/src/Camera.cpp.o
CG: CMakeFiles/CG.dir/src/EventHandler.cpp.o
CG: CMakeFiles/CG.dir/src/Event.cpp.o
CG: CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o
CG: CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o
CG: CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o
CG: CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o
CG: CMakeFiles/CG.dir/src/Point.cpp.o
CG: CMakeFiles/CG.dir/src/Texture.cpp.o
CG: CMakeFiles/CG.dir/src/Light.cpp.o
CG: CMakeFiles/CG.dir/build.make
CG: /usr/lib/x86_64-linux-gnu/libGLU.so
CG: /usr/lib/x86_64-linux-gnu/libGL.so
CG: /usr/lib/x86_64-linux-gnu/libglut.so
CG: /usr/lib/x86_64-linux-gnu/libXmu.so
CG: /usr/lib/x86_64-linux-gnu/libXi.so
CG: /usr/lib/x86_64-linux-gnu/libGLEW.so
CG: /usr/lib/x86_64-linux-gnu/libMagick++-6.Q16.so
CG: CMakeFiles/CG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable CG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CG.dir/build: CG

.PHONY : CMakeFiles/CG.dir/build

CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/main.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Shader.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/ShaderProgram.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Window.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Matrix4.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Quaternion.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/gl_math.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Camera.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/EventHandler.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Event.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/KeyboardEventHandler.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/CameraEventHandler.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/MouseEventHandler.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/MouseEventArgs.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Point.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Texture.cpp.o.requires
CMakeFiles/CG.dir/requires: CMakeFiles/CG.dir/src/Light.cpp.o.requires

.PHONY : CMakeFiles/CG.dir/requires

CMakeFiles/CG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CG.dir/clean

CMakeFiles/CG.dir/depend:
	cd /home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keltar/Desktop/Computer-Graphics/CG /home/keltar/Desktop/Computer-Graphics/CG /home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug /home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug /home/keltar/Desktop/Computer-Graphics/CG/cmake-build-debug/CMakeFiles/CG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CG.dir/depend

