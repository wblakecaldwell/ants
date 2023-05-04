cmake_minimum_required(VERSION 3.0.0)
project(ants VERSION 0.1.0)

# If you want to enable testing
include(CTest)
enable_testing()

# Create an executable target for your SDL2 project
add_executable(ants main.cpp)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Include the SDL2 header files
include_directories(${SDL2_INCLUDE_DIRS})

# Link the SDL2 library to the ants target
target_link_libraries(ants ${SDL2_LIBRARIES})

# Package configuration
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)