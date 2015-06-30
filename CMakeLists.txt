project(recreito)

cmake_minimum_required(VERSION 2.8.11.2)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(RECREITO_THIRD_PARTY_LIBS_DIR "${CMAKE_SOURCE_DIR}/lib")

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

## Third party libraries

# GLM
	include_directories("${RECREITO_THIRD_PARTY_LIBS_DIR}/glm/")

# SDL2
	set(SDL2 "${RECREITO_THIRD_PARTY_LIBS_DIR}/SDL2-2.0.3/build/debug/"
								CACHE PATH "Path where SDL2 was BUILT")
	set(SDL2_INCLUDE_DIR "${RECREITO_THIRD_PARTY_LIBS_DIR}/SDL2-2.0.3/include")
	find_package(SDL2 REQUIRED)
	include_directories(${SDL2_INCLUDE_DIR})
	target_link_libraries(recreito ${SDL2_LIBRARY})

# OpenGL
	find_package(OpenGL REQUIRED)
	include_directories(${OPENGL_INCLUDE_DIRS})
	target_link_libraries(recreito ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

# Link executable with library's libraries
#target_link_libraries(recreito recreito_lib)

# Unit tests
#add_subdirectory(${CMAKE_SOURCE_DIR}/test)