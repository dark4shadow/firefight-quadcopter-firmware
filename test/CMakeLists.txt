cmake_minimum_required(VERSION 3.10)

project(FirefightQuadcopterFirmware)

# Include directories
include_directories(
    ../include
)

# Source files
set(SOURCES
    ../src/core/drone_state_machine.cpp
    ../src/control/manual_interface.cpp
    ../src/control/navigation_manager.cpp
    ../src/sensors/co2_analyzer.cpp
    ../src/sensors/gps_receiver.cpp
    ../src/sensors/thermal_scanner.cpp
    ../src/services/battery_manager.cpp
    ../src/services/return_to_base.cpp
)

# Test files
set(TEST_SOURCES
    core/drone_state_machine_tests.cpp
)

# Create the test executable
add_executable(drone_state_machine_tests ${TEST_SOURCES} ${SOURCES})

# Link libraries if needed
# target_link_libraries(drone_state_machine_tests <libraries>)