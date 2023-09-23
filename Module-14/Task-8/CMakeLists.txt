generate_target_name(TARGET_NAME ${PRACTICAL_TASK_NAME})

add_executable(${TARGET_NAME} 
    src/main.cpp
    src/game/battleship.cpp
    src/console/user_input.cpp
    src/console/commands.cpp
)

define_operating_system_macros(${TARGET_NAME})
