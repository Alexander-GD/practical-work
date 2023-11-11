cmake_minimum_required(VERSION 3.24.0)

project(PracticalWork LANGUAGES CXX)

# set project properties
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set target name
set(PRACTICAL_TASK_NAME "Task_")

# project options
set(COMPILE_OPTIONS_GNU 
    -Wall;-Wextra;-Werror;-Wpedantic;
    -Wsign-conversion;
    -Wno-error=sign-conversion;
    -Wno-error=unused-parameter 
    CACHE STRING "GCC warning options")

# add compile options
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(${COMPILE_OPTIONS_GNU})
endif()

# useful functions
include(cmake/utils.cmake)

# add modules directory to the build
add_subdirectory(Module-11)
add_subdirectory(Module-12)
add_subdirectory(Module-13)
add_subdirectory(Module-14)
add_subdirectory(Module-15)
add_subdirectory(Module-16)
