cmake_minimum_required(VERSION 3.11)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(On_The_Run)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

#### on_the_run ####
file(GLOB_RECURSE SOURCES on_the_run/*.cpp on_the_run/*.h)
add_executable(on_the_run ${SOURCES})
target_include_directories(on_the_run PRIVATE ${SFML_INCS})
target_link_libraries(on_the_run sfml-graphics)

add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/res" # Source directory containing resources
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res # Target directory in the build output
)

add_dependencies(on_the_run copy_resources)