# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package
.PHONY : package/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cpack --config ./CPackSourceConfig.cmake /home/kai/projects/sw/armhf/lpbsl2/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source
.PHONY : package_source/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\" \"headers\" \"libraries\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/opt/poky/4.1+snapshot/sysroots/x86_64-pokysdk-linux/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kai/projects/sw/armhf/lpbsl2/CMakeFiles /home/kai/projects/sw/armhf/lpbsl2//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kai/projects/sw/armhf/lpbsl2/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named iox-lpb-backbone

# Build rule for target.
iox-lpb-backbone: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 iox-lpb-backbone
.PHONY : iox-lpb-backbone

# fast build rule for target.
iox-lpb-backbone/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iox-lpb-backbone.dir/build.make CMakeFiles/iox-lpb-backbone.dir/build
.PHONY : iox-lpb-backbone/fast

#=============================================================================
# Target rules for targets named lib

# Build rule for target.
lib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 lib
.PHONY : lib

# fast build rule for target.
lib/fast:
	$(MAKE) $(MAKESILENT) -f lib/src/CMakeFiles/lib.dir/build.make lib/src/CMakeFiles/lib.dir/build
.PHONY : lib/fast

#=============================================================================
# Target rules for targets named fmt

# Build rule for target.
fmt: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 fmt
.PHONY : fmt

# fast build rule for target.
fmt/fast:
	$(MAKE) $(MAKESILENT) -f external/fmt/CMakeFiles/fmt.dir/build.make external/fmt/CMakeFiles/fmt.dir/build
.PHONY : fmt/fast

#=============================================================================
# Target rules for targets named SQLiteCpp

# Build rule for target.
SQLiteCpp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 SQLiteCpp
.PHONY : SQLiteCpp

# fast build rule for target.
SQLiteCpp/fast:
	$(MAKE) $(MAKESILENT) -f external/SQLiteCpp/CMakeFiles/SQLiteCpp.dir/build.make external/SQLiteCpp/CMakeFiles/SQLiteCpp.dir/build
.PHONY : SQLiteCpp/fast

#=============================================================================
# Target rules for targets named SQLiteCpp_cpplint

# Build rule for target.
SQLiteCpp_cpplint: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 SQLiteCpp_cpplint
.PHONY : SQLiteCpp_cpplint

# fast build rule for target.
SQLiteCpp_cpplint/fast:
	$(MAKE) $(MAKESILENT) -f external/SQLiteCpp/CMakeFiles/SQLiteCpp_cpplint.dir/build.make external/SQLiteCpp/CMakeFiles/SQLiteCpp_cpplint.dir/build
.PHONY : SQLiteCpp_cpplint/fast

#=============================================================================
# Target rules for targets named sqlite3

# Build rule for target.
sqlite3: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 sqlite3
.PHONY : sqlite3

# fast build rule for target.
sqlite3/fast:
	$(MAKE) $(MAKESILENT) -f external/SQLiteCpp/sqlite3/CMakeFiles/sqlite3.dir/build.make external/SQLiteCpp/sqlite3/CMakeFiles/sqlite3.dir/build
.PHONY : sqlite3/fast

#=============================================================================
# Target rules for targets named cppgpio

# Build rule for target.
cppgpio: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cppgpio
.PHONY : cppgpio

# fast build rule for target.
cppgpio/fast:
	$(MAKE) $(MAKESILENT) -f external/CppGPIO/CMakeFiles/cppgpio.dir/build.make external/CppGPIO/CMakeFiles/cppgpio.dir/build
.PHONY : cppgpio/fast

#=============================================================================
# Target rules for targets named cppgpio-static

# Build rule for target.
cppgpio-static: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cppgpio-static
.PHONY : cppgpio-static

# fast build rule for target.
cppgpio-static/fast:
	$(MAKE) $(MAKESILENT) -f external/CppGPIO/CMakeFiles/cppgpio-static.dir/build.make external/CppGPIO/CMakeFiles/cppgpio-static.dir/build
.PHONY : cppgpio-static/fast

iox_lpb_backbone.o: iox_lpb_backbone.cpp.o
.PHONY : iox_lpb_backbone.o

# target to build an object file
iox_lpb_backbone.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iox-lpb-backbone.dir/build.make CMakeFiles/iox-lpb-backbone.dir/iox_lpb_backbone.cpp.o
.PHONY : iox_lpb_backbone.cpp.o

iox_lpb_backbone.i: iox_lpb_backbone.cpp.i
.PHONY : iox_lpb_backbone.i

# target to preprocess a source file
iox_lpb_backbone.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iox-lpb-backbone.dir/build.make CMakeFiles/iox-lpb-backbone.dir/iox_lpb_backbone.cpp.i
.PHONY : iox_lpb_backbone.cpp.i

iox_lpb_backbone.s: iox_lpb_backbone.cpp.s
.PHONY : iox_lpb_backbone.s

# target to generate assembly for a file
iox_lpb_backbone.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iox-lpb-backbone.dir/build.make CMakeFiles/iox-lpb-backbone.dir/iox_lpb_backbone.cpp.s
.PHONY : iox_lpb_backbone.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... package"
	@echo "... package_source"
	@echo "... rebuild_cache"
	@echo "... SQLiteCpp_cpplint"
	@echo "... SQLiteCpp"
	@echo "... cppgpio"
	@echo "... cppgpio-static"
	@echo "... fmt"
	@echo "... iox-lpb-backbone"
	@echo "... lib"
	@echo "... sqlite3"
	@echo "... iox_lpb_backbone.o"
	@echo "... iox_lpb_backbone.i"
	@echo "... iox_lpb_backbone.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

