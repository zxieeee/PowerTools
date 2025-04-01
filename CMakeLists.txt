cmake_minimum_required(VERSION 3.10)

# Set your project name
project(PowerTools)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify your source files

if(UNIX AND NOT CMAKE_CROSSCOMPILING)
  message(STATUS "Adding Linux target")

  set(SRC_FILES
    src/main.cpp
    src/core.cpp
    src/config.cpp
    src/dirMonitor_linux.cpp
)
  # Find GTKMM on Linux
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

  # Add include directories and linker flags
  include_directories(${GTKMM_INCLUDE_DIRS})
  link_directories(${GTKMM_LIBRARY_DIRS})
  add_definitions(${GTKMM_CFLAGS_OTHER})
  add_executable(PowerTools ${SRC_FILES})
  target_link_libraries(PowerTools ${GTKMM_LIBRARIES})
endif()

if(CMAKE_CROSSCOMPILING)
  message(STATUS "Adding Windows target")

  set(SRC_FILES
    src/main.cpp
    src/core.cpp
    src/config.cpp
    src/dirMonitor_win.cpp
    src/systray_win.cpp
)
  # Set Windows-specific compiler
  set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
  set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

  # Link Windows system libraries
  set(WINDOWS_LIBS user32 kernel32)

  # Create Windows executable
  add_executable(PowerTools ${SRC_FILES})
  target_link_libraries(PowerTools ${WINDOWS_LIBS})
endif()
