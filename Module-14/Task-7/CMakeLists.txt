generate_target_name(TARGET_NAME ${PRACTICAL_TASK_NAME})

add_executable(${TARGET_NAME} 
    src/main.cpp
    src/game/minecraft.cpp
    src/console/user_input.cpp
)
