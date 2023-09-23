# Defines functions and macros useful for building tasks for lessons
# and practice.

# Generate target name
function(generate_target_name output target_name)
    # Get the relative path of the current directory
    cmake_path(RELATIVE_PATH CMAKE_CURRENT_SOURCE_DIR BASE_DIRECTORY ${CMAKE_SOURCE_DIR} OUTPUT_VARIABLE path)

    # Get a number from a relative path
    # string(REGEX REPLACE "[a-zA-Z]*.([1-9]*)/[a-zA-Z]*.([1-9]*)/[a-zA-Z]*.([1-9]*)" "\\1.\\2.\\3" number ${path})
    string(REGEX REPLACE "[^0-9/]+" "" number ${path})
    string(REGEX REPLACE "[/]+" "." number ${number})
    
    # Return the name of the target.
    set(${output} "${target_name}${number}" PARENT_SCOPE)
endfunction()

# Define operating system macros
macro(define_operating_system_macros target_name)
    if(WIN32)
        # Get the latest version of the build. (from 22621.2283 --> 22621)
        string(REGEX MATCH "([0-9]+$)" version ${CMAKE_HOST_SYSTEM_VERSION})
        # Add compile definitions to a target
        target_compile_definitions(${target_name} PRIVATE 
            WIN_OS 
            WIN_VER=${version})
    endif()
endmacro()
