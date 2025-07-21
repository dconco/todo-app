cmake_minimum_required(VERSION 3.10)
project(TodoApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find all C++ source files (these get compiled)
file(GLOB SOURCES 
    "src/*.cpp"
    "src/*.cxx" 
    "src/*.cc"
    "src/*.c++"
    "src/*.cp"
    "src/*.c"
)

# Find all C source files if you have any
file(GLOB C_SOURCES "src/*.c")

# Find header files (for IDE support, not compilation)
file(GLOB HEADERS 
    "src/*.h"
    "src/*.hh"
    "src/*.hpp"
    "src/*.hxx"
    "src/*.h++"
    "src/*.hp"
)

# Create executable with all source files
add_executable(app ${SOURCES} ${C_SOURCES} ${HEADERS})
target_precompile_headers(app PRIVATE "src/lib/httplib.h")

# Add DEBUG options for debug builds
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Set default build type to Debug if not specified
# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE Debug)
# endif()

