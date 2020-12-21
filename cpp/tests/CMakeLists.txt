cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

# modify this to where the shared library is installed
include_directories(/home/hilko/devprojects/hal/install/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

# should not set AUTOMOBILE_LIB, it stores the result of the search
find_library(AUTOMOBILE_LIB automobile HINTS /home/hilko/devprojects/hal/install/lib )

add_executable(test src/test.cpp)

# Installation
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/home/hilko/devprojects/hal/install" CACHE PATH "..." FORCE)
endif()

target_link_libraries(test PUBLIC ${AUTOMOBILE_LIB})