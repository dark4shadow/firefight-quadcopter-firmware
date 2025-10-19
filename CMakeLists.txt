cmake_minimum_required(VERSION 3.10)

project(FirefightQuadcopterFirmware)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable
add_executable(firefight_quadcopter ${SOURCES})

# Link libraries if needed (e.g., wiringPi, pthread)
# target_link_libraries(firefight_quadcopter <libraries>)

# Add tests
enable_testing()
add_subdirectory(test)