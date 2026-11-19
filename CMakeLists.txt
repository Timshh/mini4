cmake_minimum_required (VERSION 3.11)

project (Mini3)

add_executable(Mini3 "code/main.cpp")

set_property(TARGET Mini3 PROPERTY CXX_STANDARD 20)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/data
)

target_include_directories(Mini3 PUBLIC
    code
    data
)