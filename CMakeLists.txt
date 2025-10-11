# -----------------------------------------------------------
#  Jim PHP - Educational Project
# -----------------------------------------------------------

# CMake version required
cmake_minimum_required(VERSION 3.16)

# Project name and language
project(jimphp LANGUAGES CXX)

# Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Debug or release monde = -g (no optimization) or -O3 (03 optimization)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Print info
message(STATUS "--------------------------------------------")
message(STATUS " Project: Jim PHP")
message(STATUS " Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS " Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " Inspired by: Jim TCL")
message(STATUS "--------------------------------------------")

# Set header position
include_directories(include)

# Search cpp file insid /src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Search executable file
add_executable(jimphp ${SOURCES})

# Specify where binary will be saved
set_target_properties(jimphp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# directory /test for unit test
#enable_testing()
#add_subdirectory(tests)

# -----------------------------------------------------------
# End
# -----------------------------------------------------------

