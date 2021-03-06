project(recreito)

cmake_minimum_required(VERSION 2.8.11.2)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(RECREITO_THIRD_PARTY_LIBS_DIR "${CMAKE_SOURCE_DIR}/lib")

# C++11 support
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

# Create targets
    # Add all files to build target, excluding main.cpp
    file(GLOB recreito_SRC
        "src/*.h"
        "src/core/*.*"
        "src/gameobjects/*.*"
        "src/systems/rendering/*.*"
        "src/systems/rendering/models/*.*"
        "src/systems/rendering/shaders/*.*"
        "src/systems/behavior/*.*"
        "src/[!main]*.cpp"
    )
        add_library(recreito_lib STATIC ${recreito_SRC})
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
        target_link_libraries(recreito_lib ${SDL2_LIBRARY})

# SOIL
        set(SOIL "${RECREITO_THIRD_PARTY_LIBS_DIR}/soil/build"
                                                                CACHE PATH "Path where SOIL was BUILT (without ending slash)")
        set(SOIL_INCLUDE_DIR "${RECREITO_THIRD_PARTY_LIBS_DIR}/soil/src")
        include_directories(${SOIL_INCLUDE_DIR})
        target_link_libraries(recreito_lib ${SOIL}/libSOIL.a)

# GLEW
        include_directories("${RECREITO_THIRD_PARTY_LIBS_DIR}/glew/include")
        target_link_libraries(recreito_lib "${RECREITO_THIRD_PARTY_LIBS_DIR}/glew/build/mingw/lib/libglew32.a")

# ASSIMP
        set(ASSIMP "${RECREITO_THIRD_PARTY_LIBS_DIR}/assimp/build"
                   CACHE PATH "Path where ASSIMP was BUILT")
        set(ASSIMP_INCLUDE_DIR "${RECREITO_THIRD_PARTY_LIBS_DIR}/assimp/include/")
        include_directories(${ASSIMP_INCLUDE_DIR})
#TODO: FIX FOR UNIX
        target_link_libraries(recreito_lib ${ASSIMP}/code/libassimp.dll.a)

# OpenGL
        find_package(OpenGL REQUIRED)
        include_directories(${OPENGL_INCLUDE_DIRS})
        target_link_libraries(recreito_lib ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

# Link executable with library's libraries
target_link_libraries(recreito recreito_lib)

# Unit tests
#add_subdirectory(${CMAKE_SOURCE_DIR}/test)
