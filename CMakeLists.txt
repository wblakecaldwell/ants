cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(ants VERSION 0.1.0)

# If you want to enable testing
include(CTest)
enable_testing()

file(GLOB SOURCES "*.cc")
add_executable(ants ${SOURCES})

# SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(ants ${SDL2_LIBRARIES})

# SDL_image packages
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(ants ${SDL2_IMAGE_LIBRARIES})

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
