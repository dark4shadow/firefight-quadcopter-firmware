# Firefight Quadcopter Firmware

This project implements firmware for a Raspberry Pi-based quadcopter designed for detecting and extinguishing fires using a powder dispersal method. The quadcopter is equipped with GPS and internet access to locate areas with high CO2 levels and communicate with emergency services.

## Features

- **Fire Detection**: Utilizes CO2 sensors and thermal scanners to identify potential fire sources.
- **Powder Dispersal**: Implements a mechanism for dispersing fire suppression powder.
- **GPS Navigation**: Uses GPS for precise navigation and location tracking.
- **Manual Control**: Allows operators to manually control the quadcopter when necessary.
- **Emergency Communication**: Communicates with emergency services to report fire locations and status.
- **Automatic Return**: Automatically returns to the base for recharging when battery levels are low.

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/firefight-quadcopter-firmware.git
   cd firefight-quadcopter-firmware
   ```

2. **Install Dependencies**:
   Ensure you have the necessary dependencies installed for building the firmware. This may include libraries for GPS, communication, and sensor integration.

3. **Configure the Project**:
   Modify the configuration files in the `config` directory to set up flight paths, network settings, and sensor configurations.

4. **Build the Firmware**:
   Use CMake to build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

5. **Deploy to Raspberry Pi**:
   Follow the instructions in the `scripts` directory to flash the firmware onto the Raspberry Pi.

## Usage

- **Start the Quadcopter**: Power on the quadcopter and ensure it is connected to the internet.
- **Automatic Mode**: The quadcopter will automatically patrol designated areas, detect fires, and extinguish them.
- **Manual Control**: Use the manual interface to take control of the quadcopter if needed.

## Documentation

Refer to the `docs` directory for detailed documentation on the architecture, emergency communications, and Unity simulation references.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.