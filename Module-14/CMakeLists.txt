# get the name of the current module
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME module)

# set the binary output directory for the practical work
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${module}")

# add task directory to the build
add_subdirectory(Task-1)
add_subdirectory(Task-2)
add_subdirectory(Task-3)
add_subdirectory(Task-4)
add_subdirectory(Task-5)
add_subdirectory(Task-6)
add_subdirectory(Task-7)
add_subdirectory(Task-8)
