# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake

# The command to remove a file.
RM = /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kai/projects/sw/armhf/lpbsl2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kai/projects/sw/armhf/lpbsl2

# Include any dependencies generated for this target.
include lib/src/CMakeFiles/lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/src/CMakeFiles/lib.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/src/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/src/CMakeFiles/lib.dir/flags.make

lib/src/CMakeFiles/lib.dir/tracking.cpp.o: lib/src/CMakeFiles/lib.dir/flags.make
lib/src/CMakeFiles/lib.dir/tracking.cpp.o: lib/src/tracking.cpp
lib/src/CMakeFiles/lib.dir/tracking.cpp.o: lib/src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/projects/sw/armhf/lpbsl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/src/CMakeFiles/lib.dir/tracking.cpp.o"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/src/CMakeFiles/lib.dir/tracking.cpp.o -MF CMakeFiles/lib.dir/tracking.cpp.o.d -o CMakeFiles/lib.dir/tracking.cpp.o -c /home/kai/projects/sw/armhf/lpbsl2/lib/src/tracking.cpp

lib/src/CMakeFiles/lib.dir/tracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/tracking.cpp.i"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/projects/sw/armhf/lpbsl2/lib/src/tracking.cpp > CMakeFiles/lib.dir/tracking.cpp.i

lib/src/CMakeFiles/lib.dir/tracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/tracking.cpp.s"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/projects/sw/armhf/lpbsl2/lib/src/tracking.cpp -o CMakeFiles/lib.dir/tracking.cpp.s

lib/src/CMakeFiles/lib.dir/serialization.cpp.o: lib/src/CMakeFiles/lib.dir/flags.make
lib/src/CMakeFiles/lib.dir/serialization.cpp.o: lib/src/serialization.cpp
lib/src/CMakeFiles/lib.dir/serialization.cpp.o: lib/src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/projects/sw/armhf/lpbsl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/src/CMakeFiles/lib.dir/serialization.cpp.o"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/src/CMakeFiles/lib.dir/serialization.cpp.o -MF CMakeFiles/lib.dir/serialization.cpp.o.d -o CMakeFiles/lib.dir/serialization.cpp.o -c /home/kai/projects/sw/armhf/lpbsl2/lib/src/serialization.cpp

lib/src/CMakeFiles/lib.dir/serialization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/serialization.cpp.i"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/projects/sw/armhf/lpbsl2/lib/src/serialization.cpp > CMakeFiles/lib.dir/serialization.cpp.i

lib/src/CMakeFiles/lib.dir/serialization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/serialization.cpp.s"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/projects/sw/armhf/lpbsl2/lib/src/serialization.cpp -o CMakeFiles/lib.dir/serialization.cpp.s

lib/src/CMakeFiles/lib.dir/datahandling.cpp.o: lib/src/CMakeFiles/lib.dir/flags.make
lib/src/CMakeFiles/lib.dir/datahandling.cpp.o: lib/src/datahandling.cpp
lib/src/CMakeFiles/lib.dir/datahandling.cpp.o: lib/src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/projects/sw/armhf/lpbsl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/src/CMakeFiles/lib.dir/datahandling.cpp.o"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/src/CMakeFiles/lib.dir/datahandling.cpp.o -MF CMakeFiles/lib.dir/datahandling.cpp.o.d -o CMakeFiles/lib.dir/datahandling.cpp.o -c /home/kai/projects/sw/armhf/lpbsl2/lib/src/datahandling.cpp

lib/src/CMakeFiles/lib.dir/datahandling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/datahandling.cpp.i"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/projects/sw/armhf/lpbsl2/lib/src/datahandling.cpp > CMakeFiles/lib.dir/datahandling.cpp.i

lib/src/CMakeFiles/lib.dir/datahandling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/datahandling.cpp.s"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/projects/sw/armhf/lpbsl2/lib/src/datahandling.cpp -o CMakeFiles/lib.dir/datahandling.cpp.s

lib/src/CMakeFiles/lib.dir/cli.cpp.o: lib/src/CMakeFiles/lib.dir/flags.make
lib/src/CMakeFiles/lib.dir/cli.cpp.o: lib/src/cli.cpp
lib/src/CMakeFiles/lib.dir/cli.cpp.o: lib/src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/projects/sw/armhf/lpbsl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/src/CMakeFiles/lib.dir/cli.cpp.o"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/src/CMakeFiles/lib.dir/cli.cpp.o -MF CMakeFiles/lib.dir/cli.cpp.o.d -o CMakeFiles/lib.dir/cli.cpp.o -c /home/kai/projects/sw/armhf/lpbsl2/lib/src/cli.cpp

lib/src/CMakeFiles/lib.dir/cli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/cli.cpp.i"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/projects/sw/armhf/lpbsl2/lib/src/cli.cpp > CMakeFiles/lib.dir/cli.cpp.i

lib/src/CMakeFiles/lib.dir/cli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/cli.cpp.s"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/projects/sw/armhf/lpbsl2/lib/src/cli.cpp -o CMakeFiles/lib.dir/cli.cpp.s

lib/src/CMakeFiles/lib.dir/sysinfo.cpp.o: lib/src/CMakeFiles/lib.dir/flags.make
lib/src/CMakeFiles/lib.dir/sysinfo.cpp.o: lib/src/sysinfo.cpp
lib/src/CMakeFiles/lib.dir/sysinfo.cpp.o: lib/src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/projects/sw/armhf/lpbsl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib/src/CMakeFiles/lib.dir/sysinfo.cpp.o"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/src/CMakeFiles/lib.dir/sysinfo.cpp.o -MF CMakeFiles/lib.dir/sysinfo.cpp.o.d -o CMakeFiles/lib.dir/sysinfo.cpp.o -c /home/kai/projects/sw/armhf/lpbsl2/lib/src/sysinfo.cpp

lib/src/CMakeFiles/lib.dir/sysinfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/sysinfo.cpp.i"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/projects/sw/armhf/lpbsl2/lib/src/sysinfo.cpp > CMakeFiles/lib.dir/sysinfo.cpp.i

lib/src/CMakeFiles/lib.dir/sysinfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/sysinfo.cpp.s"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/projects/sw/armhf/lpbsl2/lib/src/sysinfo.cpp -o CMakeFiles/lib.dir/sysinfo.cpp.s

lib/src/CMakeFiles/lib.dir/datarouter.cpp.o: lib/src/CMakeFiles/lib.dir/flags.make
lib/src/CMakeFiles/lib.dir/datarouter.cpp.o: lib/src/datarouter.cpp
lib/src/CMakeFiles/lib.dir/datarouter.cpp.o: lib/src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/projects/sw/armhf/lpbsl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object lib/src/CMakeFiles/lib.dir/datarouter.cpp.o"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/src/CMakeFiles/lib.dir/datarouter.cpp.o -MF CMakeFiles/lib.dir/datarouter.cpp.o.d -o CMakeFiles/lib.dir/datarouter.cpp.o -c /home/kai/projects/sw/armhf/lpbsl2/lib/src/datarouter.cpp

lib/src/CMakeFiles/lib.dir/datarouter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/datarouter.cpp.i"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/projects/sw/armhf/lpbsl2/lib/src/datarouter.cpp > CMakeFiles/lib.dir/datarouter.cpp.i

lib/src/CMakeFiles/lib.dir/datarouter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/datarouter.cpp.s"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && /opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++   -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 -fstack-protector-strong  -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi --sysroot=/opt/poky/4.1+snapshot/sysroots/cortexa8hf-neon-poky-linux-gnueabi $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/projects/sw/armhf/lpbsl2/lib/src/datarouter.cpp -o CMakeFiles/lib.dir/datarouter.cpp.s

# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/tracking.cpp.o" \
"CMakeFiles/lib.dir/serialization.cpp.o" \
"CMakeFiles/lib.dir/datahandling.cpp.o" \
"CMakeFiles/lib.dir/cli.cpp.o" \
"CMakeFiles/lib.dir/sysinfo.cpp.o" \
"CMakeFiles/lib.dir/datarouter.cpp.o"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/tracking.cpp.o
lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/serialization.cpp.o
lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/datahandling.cpp.o
lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/cli.cpp.o
lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/sysinfo.cpp.o
lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/datarouter.cpp.o
lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/build.make
lib/src/liblib.a: lib/src/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kai/projects/sw/armhf/lpbsl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library liblib.a"
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean_target.cmake
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/src/CMakeFiles/lib.dir/build: lib/src/liblib.a
.PHONY : lib/src/CMakeFiles/lib.dir/build

lib/src/CMakeFiles/lib.dir/clean:
	cd /home/kai/projects/sw/armhf/lpbsl2/lib/src && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : lib/src/CMakeFiles/lib.dir/clean

lib/src/CMakeFiles/lib.dir/depend:
	cd /home/kai/projects/sw/armhf/lpbsl2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kai/projects/sw/armhf/lpbsl2 /home/kai/projects/sw/armhf/lpbsl2/lib/src /home/kai/projects/sw/armhf/lpbsl2 /home/kai/projects/sw/armhf/lpbsl2/lib/src /home/kai/projects/sw/armhf/lpbsl2/lib/src/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/src/CMakeFiles/lib.dir/depend

