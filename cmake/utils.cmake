# Defines functions and macros useful for building tasks for lessons
# and practice.

# Generate target name.
function(generate_target_name output target_name)
    # Get the relative path of the current directory.
    cmake_path(RELATIVE_PATH CMAKE_CURRENT_SOURCE_DIR BASE_DIRECTORY ${CMAKE_SOURCE_DIR} OUTPUT_VARIABLE path)

    # Get a number from a relative path.
    # string(REGEX REPLACE "[a-zA-Z]*.([1-9]*)/[a-zA-Z]*.([1-9]*)/[a-zA-Z]*.([1-9]*)" "\\1.\\2.\\3" number ${path})
    string(REGEX REPLACE "[^0-9/]+" "" number ${path})
    string(REGEX REPLACE "[/]+" "." number ${number})
    
    # Return the name of the target.
    set(${output} "${target_name}${number}" PARENT_SCOPE)
endfunction()
