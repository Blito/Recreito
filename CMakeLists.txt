project(recreito)

cmake_minimum_required(VERSION 2.8.11.2)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# C++11 support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

# Create targets
    # Add all files to build target, excluding main.cpp
    file(GLOB recreito_SRC
        "src/*.h"
        "src/[!main]*.cpp"
    )
#add_library(recreito_lib STATIC ${recreito_SRC})
add_executable(recreito src/main.cpp)

# GLM includes
include_directories("${CMAKE_SOURCE_DIR}/lib/glm/")

# Link executable with library's libraries
#target_link_libraries(recreito recreito_lib)

# Unit tests
#add_subdirectory(${CMAKE_SOURCE_DIR}/test)