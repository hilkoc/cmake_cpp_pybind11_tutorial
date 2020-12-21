cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(automobile)

include_directories("${CMAKE_SOURCE_DIR}/cpp/include/automobile_bits")
include_directories("${CMAKE_SOURCE_DIR}/python")

file (GLOB SOURCE_FILES "cpp/src/*.cpp")
file (GLOB HEADER_FILES "cpp/include/automobile_bits/*.hpp")
file (GLOB PYTHON_FILES "python/*.cpp" "python/*.hpp")

# Set up such that XCode organizes the files
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES} ${HEADER_FILES} ${PYTHON_FILES} )

# These two variables should not be set here, but on the command line instead. From within the buld directory:
# cmake .. -DPYTHON_LIBRARY_DIR=”/path/to/site-packages” -DPYTHON_EXECUTABLE=”/path/to/executable/python3"
# My PYTHON_LIBRARY_DIR is /home/hilko/software/miniconda3/envs/hqenv/lib/python3.9/site-packages
# My PYTHON_EXECUTABLE is  /home/hilko/software/miniconda3/envs/hqenv/bin/python
set(PYTHON_LIBRARY_DIR "/home/hilko/devprojects/hal/install/py")
set(PYTHON_EXECUTABLE "/home/hilko/software/miniconda3/envs/hqenv/bin/python")


include(pybind11.cmake)
pybind11_add_module(automobile 
	${SOURCE_FILES}
	${HEADER_FILES}
	${PYTHON_FILES}
)

target_link_libraries(automobile PUBLIC)

# Installation
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/home/hilko/devprojects/hal/install" CACHE PATH "..." FORCE)
endif()

install(TARGETS automobile
  COMPONENT python
  LIBRARY DESTINATION "${PYTHON_LIBRARY_DIR}"
  )
