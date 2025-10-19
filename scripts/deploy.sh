#!/bin/bash

# This script deploys the firmware to the Raspberry Pi-based quadcopter.

# Define variables
FIRMWARE_DIR="/path/to/firmware"
TARGET_DIR="/path/to/target"
SD_CARD_DEVICE="/dev/sdX"  # Replace with the actual SD card device

# Build the firmware
echo "Building the firmware..."
cd $FIRMWARE_DIR
mkdir -p build
cd build
cmake ..
make

# Flash the firmware to the SD card
echo "Flashing firmware to SD card..."
sudo dd if=firmware.img of=$SD_CARD_DEVICE bs=4M status=progress
sync

# Notify user of completion
echo "Deployment complete. Please insert the SD card into the quadcopter."