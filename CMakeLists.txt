cmake_minimum_required(VERSION 3.0)
project(cgeodesy)

if (NOT TARGET ctest)
    add_subdirectory(ctest)
endif()
if (NOT TARGET cmat)
    add_subdirectory(cmat)
endif()

include_directories(include)
add_library(${PROJECT_NAME}
        src/ellipsoid.c)
target_include_directories(${PROJECT_NAME}
        PUBLIC
        include)

add_executable(${PROJECT_NAME}_unit_tests
        tests/main.c)

target_link_libraries(${PROJECT_NAME}_unit_tests
        ${PROJECT_NAME}
        ctest)

add_custom_command(
        TARGET ${PROJECT_NAME}_unit_tests
        POST_BUILD
        COMMAND ${PROJECT_NAME}_unit_tests)