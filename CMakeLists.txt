cmake_minimum_required(VERSION 3.10)

# Set your project name
project(gtk_multimedia_organiser)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
# Include directories for gtkmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

# Add include directories and linker flags
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

# Specify your source files
set(SRC_FILES
    src/main.cpp
    src/core.cpp
    src/config.cpp
)
add_executable(gtk_multimedia_organiser ${SRC_FILES} )

# Link the gtkmm libraries
target_link_libraries(gtk_multimedia_organiser ${GTKMM_LIBRARIES})

