cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(ants VERSION 0.1.0)

# If you want to enable testing
include(CTest)
enable_testing()

file(GLOB SOURCES "*.cc")
add_executable(ants main.cc ${SOURCES})

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

set(ABSEIL_DIR "${CMAKE_SOURCE_DIR}/thirdparty/abseil")
add_subdirectory(${ABSEIL_DIR})
target_link_libraries(ants absl::base absl::synchronization absl::strings)

# Replace this with the actual path to the 'thirdparty/abseil' directory.
set(THIRDPARTY_ABSEIL_DIR "${CMAKE_SOURCE_DIR}/thirdparty/abseil")

# Add the 'thirdparty/abseil' directory to the include directories.
include_directories(${THIRDPARTY_ABSEIL_DIR})
