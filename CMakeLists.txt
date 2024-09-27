cmake_minimum_required(VERSION 3.29)

# Set the project name and version
project(lab0 VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(lab0 main.cpp
        Linked.h)

# Link the C++ standard library
target_link_libraries(lab0 stdc++)

# Include directories if needed
# target_include_directories(lab0 PRIVATE ${CMAKE_SOURCE_DIR}/include)

project(lab0)



