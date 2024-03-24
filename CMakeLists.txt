cmake_minimum_required(VERSION 3.16)
project(platformer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Check if it's a UNIX system (which includes Linux)
if(UNIX)
    # Check if Xinerama is installed, if not, install it using apt-get
    execute_process(
            COMMAND dpkg-query -W -f='${Status}' libxinerama-dev
            RESULT_VARIABLE XINERAMA_PKG_NOT_FOUND
            OUTPUT_QUIET
    )
    if(XINERAMA_PKG_NOT_FOUND)
        message(STATUS "Xinerama package not found. Installing...")
        execute_process(
                COMMAND sudo apt-get -y install libxinerama-dev
                RESULT_VARIABLE XINERAMA_INSTALL_RESULT
        )
        if(NOT XINERAMA_INSTALL_RESULT EQUAL 0)
            message(FATAL_ERROR "Failed to install Xinerama package.")
        endif()
    endif()
endif()

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_Declare(BOX2D
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.3.1
        CMAKE_ARGS -DBOX2D_BUILD_UNIT_TESTS=OFF)
FetchContent_MakeAvailable(SFML)
FetchContent_MakeAvailable(BOX2D)

add_executable(platformer src/main.cpp
        src/engine/Camera.cpp
        src/engine/Camera.h
        src/engine/Renderer.cpp
        src/engine/Renderer.h
        src/engine/Debug.cpp
        src/engine/Debug.h
        src/engine/Physics.cpp
        src/engine/Physics.h
        src/Map.cpp
        src/Map.h
        src/Resources.cpp
        src/Resources.h
        src/entities/Player.cpp
        src/entities/Player.h
        src/engine/Collision.cpp
        src/engine/Collision.h
        src/engine/Animation.cpp
        src/engine/Animation.h
)
file(COPY src/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
target_link_libraries(platformer PRIVATE sfml-graphics)
target_link_libraries(platformer PRIVATE box2d)
target_compile_features(platformer PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
            TARGET platformer
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:platformer>
            VERBATIM)
endif()

install(TARGETS platformer)
