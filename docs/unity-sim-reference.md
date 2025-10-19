# Unity Simulation Reference for Firefight Quadcopter Firmware

This document serves as a reference for the Unity simulation code that has been adapted for the firmware of the firefight quadcopter. The Unity simulation provides a virtual environment to test and visualize the quadcopter's functionalities, including navigation, fire detection, and suppression mechanisms.

## Overview

The Unity simulation is designed to mimic the behavior of the firefight quadcopter as described in the firmware. It utilizes the same state machine and control logic, allowing for seamless integration between the simulation and the actual firmware implementation.

## Key Components

### Drone States

The quadcopter operates in various states, which are managed by the `DroneStateMachine` class. The states include:

- **Idle**: The drone is stationary and awaiting commands.
- **Patrol**: The drone navigates predefined waypoints to monitor for fires.
- **Investigate**: Upon detecting a potential fire, the drone approaches to confirm the presence of flames.
- **Extinguish**: The drone deploys powder to suppress the fire.
- **Return**: The drone returns to the base for recharging or after completing its mission.

### Navigation

The `NavigationManager` class handles the navigation logic, including waypoint management and obstacle avoidance. The quadcopter uses GPS data from the `GPSReceiver` to determine its position and navigate effectively.

### Fire Detection

Fire detection is achieved through the `CO2Analyzer` and `ThermalScanner` classes. The quadcopter scans the environment for elevated CO2 levels and thermal signatures indicative of fire. The detection logic is similar to that implemented in the Unity simulation.

### Powder Dispersal

The `PowderDispersal` class controls the mechanism for dispersing fire suppression powder. The simulation visualizes this process, allowing for testing of the dispersal patterns and effectiveness.

### Manual Control

The `ManualInterface` class provides functionality for manual control of the quadcopter. This feature is crucial for emergency situations where human intervention may be necessary.

### Emergency Communications

The `EmergencyChannel` class facilitates communication with emergency services. The simulation includes mock interfaces to demonstrate how the quadcopter would notify authorities in real scenarios.

## Integration with Firmware

The Unity simulation is integrated with the firmware through the `UnityAdapter` class. This adapter ensures that the simulation accurately reflects the state and behavior of the quadcopter as defined in the firmware code.

## Testing and Validation

The simulation serves as a testing ground for validating the quadcopter's behavior before deployment. It allows developers to identify and resolve issues in a controlled environment, ensuring that the firmware operates as intended in real-world scenarios.

## Conclusion

This reference document outlines the key aspects of the Unity simulation for the firefight quadcopter firmware. By leveraging the simulation, developers can enhance the reliability and effectiveness of the quadcopter in detecting and extinguishing fires.