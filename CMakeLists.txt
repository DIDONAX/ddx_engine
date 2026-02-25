cmake_minimum_required(VERSION 3.16)
project(fyzix LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SDL_AUDIO OFF CACHE BOOL "" FORCE)
set(SDL_HAPTIC OFF CACHE BOOL "" FORCE)
set(SDL_JOYSTICK OFF CACHE BOOL "" FORCE)
file(GLOB SOURCES engine/source/*.cpp)

include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main
    SOURCE_DIR deps/SDL3
)

FetchContent_MakeAvailable(SDL3)


add_executable(orbit exe/orbit.cpp ${SOURCES})
add_executable(test exe/test.cpp ${SOURCES})

include_directories(engine/include)

target_link_libraries(orbit_demo PRIVATE SDL3::SDL3)
target_link_libraries(test PRIVATE SDL3::SDL3)


