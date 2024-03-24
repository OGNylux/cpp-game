cmake_minimum_required(VERSION 3.16)
project(platformer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_Declare(BOX2D
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1)
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

if (UNIX)
    add_custom_command(
        TARGET platformer
        COMMENT "install"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} apt-get install libxinerama-dev
        VERBATIM)
endif (UNIX)

install(TARGETS platformer)
