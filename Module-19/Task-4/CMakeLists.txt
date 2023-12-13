generate_target_name(TARGET_NAME ${PRACTICAL_TASK_NAME})

add_executable(${TARGET_NAME} 
    src/main.cpp
)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different 
        "${CMAKE_CURRENT_SOURCE_DIR}/data"
        "$<TARGET_FILE_DIR:${TARGET_NAME}>/data"
)
