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
CMAKE_SOURCE_DIR = C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build

# Include any dependencies generated for this target.
include p6/third-party/imgui/CMakeFiles/ImGui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.make

# Include the progress variables for this target.
include p6/third-party/imgui/CMakeFiles/ImGui.dir/progress.make

# Include the compile flags for this target's objects.
include p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.obj: ../p6/third-party/imgui/imgui_demo.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.obj -MF CMakeFiles\ImGui.dir\imgui_demo.cpp.obj.d -o CMakeFiles\ImGui.dir\imgui_demo.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_demo.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/imgui_demo.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_demo.cpp > CMakeFiles\ImGui.dir\imgui_demo.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/imgui_demo.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_demo.cpp -o CMakeFiles\ImGui.dir\imgui_demo.cpp.s

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.obj: ../p6/third-party/imgui/imgui_draw.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.obj -MF CMakeFiles\ImGui.dir\imgui_draw.cpp.obj.d -o CMakeFiles\ImGui.dir\imgui_draw.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_draw.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/imgui_draw.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_draw.cpp > CMakeFiles\ImGui.dir\imgui_draw.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/imgui_draw.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_draw.cpp -o CMakeFiles\ImGui.dir\imgui_draw.cpp.s

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.obj: ../p6/third-party/imgui/imgui_tables.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.obj -MF CMakeFiles\ImGui.dir\imgui_tables.cpp.obj.d -o CMakeFiles\ImGui.dir\imgui_tables.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_tables.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/imgui_tables.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_tables.cpp > CMakeFiles\ImGui.dir\imgui_tables.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/imgui_tables.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_tables.cpp -o CMakeFiles\ImGui.dir\imgui_tables.cpp.s

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj: ../p6/third-party/imgui/imgui_widgets.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj -MF CMakeFiles\ImGui.dir\imgui_widgets.cpp.obj.d -o CMakeFiles\ImGui.dir\imgui_widgets.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_widgets.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/imgui_widgets.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_widgets.cpp > CMakeFiles\ImGui.dir\imgui_widgets.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/imgui_widgets.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui_widgets.cpp -o CMakeFiles\ImGui.dir\imgui_widgets.cpp.s

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.obj: ../p6/third-party/imgui/imgui.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.obj -MF CMakeFiles\ImGui.dir\imgui.cpp.obj.d -o CMakeFiles\ImGui.dir\imgui.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/imgui.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui.cpp > CMakeFiles\ImGui.dir\imgui.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/imgui.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\imgui.cpp -o CMakeFiles\ImGui.dir\imgui.cpp.s

p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj: ../p6/third-party/imgui/misc/cpp/imgui_stdlib.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj -MF CMakeFiles\ImGui.dir\misc\cpp\imgui_stdlib.cpp.obj.d -o CMakeFiles\ImGui.dir\misc\cpp\imgui_stdlib.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\misc\cpp\imgui_stdlib.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\misc\cpp\imgui_stdlib.cpp > CMakeFiles\ImGui.dir\misc\cpp\imgui_stdlib.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\misc\cpp\imgui_stdlib.cpp -o CMakeFiles\ImGui.dir\misc\cpp\imgui_stdlib.cpp.s

p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj: ../p6/third-party/imgui/backends/imgui_impl_glfw.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj -MF CMakeFiles\ImGui.dir\backends\imgui_impl_glfw.cpp.obj.d -o CMakeFiles\ImGui.dir\backends\imgui_impl_glfw.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\backends\imgui_impl_glfw.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\backends\imgui_impl_glfw.cpp > CMakeFiles\ImGui.dir\backends\imgui_impl_glfw.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\backends\imgui_impl_glfw.cpp -o CMakeFiles\ImGui.dir\backends\imgui_impl_glfw.cpp.s

p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/flags.make
p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/includes_CXX.rsp
p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj: ../p6/third-party/imgui/backends/imgui_impl_opengl3.cpp
p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj: p6/third-party/imgui/CMakeFiles/ImGui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj -MF CMakeFiles\ImGui.dir\backends\imgui_impl_opengl3.cpp.obj.d -o CMakeFiles\ImGui.dir\backends\imgui_impl_opengl3.cpp.obj -c C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\backends\imgui_impl_opengl3.cpp

p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.i"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\backends\imgui_impl_opengl3.cpp > CMakeFiles\ImGui.dir\backends\imgui_impl_opengl3.cpp.i

p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.s"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui\backends\imgui_impl_opengl3.cpp -o CMakeFiles\ImGui.dir\backends\imgui_impl_opengl3.cpp.s

# Object files for target ImGui
ImGui_OBJECTS = \
"CMakeFiles/ImGui.dir/imgui_demo.cpp.obj" \
"CMakeFiles/ImGui.dir/imgui_draw.cpp.obj" \
"CMakeFiles/ImGui.dir/imgui_tables.cpp.obj" \
"CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj" \
"CMakeFiles/ImGui.dir/imgui.cpp.obj" \
"CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj" \
"CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj" \
"CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj"

# External object files for target ImGui
ImGui_EXTERNAL_OBJECTS =

p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_demo.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_draw.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_tables.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui_widgets.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/imgui.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/misc/cpp/imgui_stdlib.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_glfw.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/backends/imgui_impl_opengl3.cpp.obj
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/build.make
p6/third-party/imgui/libImGui.a: p6/third-party/imgui/CMakeFiles/ImGui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libImGui.a"
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && $(CMAKE_COMMAND) -P CMakeFiles\ImGui.dir\cmake_clean_target.cmake
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ImGui.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
p6/third-party/imgui/CMakeFiles/ImGui.dir/build: p6/third-party/imgui/libImGui.a
.PHONY : p6/third-party/imgui/CMakeFiles/ImGui.dir/build

p6/third-party/imgui/CMakeFiles/ImGui.dir/clean:
	cd /d C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui && $(CMAKE_COMMAND) -P CMakeFiles\ImGui.dir\cmake_clean.cmake
.PHONY : p6/third-party/imgui/CMakeFiles/ImGui.dir/clean

p6/third-party/imgui/CMakeFiles/ImGui.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\p6\third-party\imgui C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui C:\Users\victo\Desktop\IMAC2S2\C++\particulesProject\particulesProject\build\p6\third-party\imgui\CMakeFiles\ImGui.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : p6/third-party/imgui/CMakeFiles/ImGui.dir/depend
