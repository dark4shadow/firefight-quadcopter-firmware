#!/bin/bash

# This script flashes the firmware to the SD card for the Raspberry Pi-based quadcopter.

# Check if the user has provided the necessary arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <path_to_firmware_image> <path_to_sd_card>"
    exit 1
fi

FIRMWARE_IMAGE=$1
SD_CARD=$2

# Unmount the SD card if it is mounted
if mount | grep "$SD_CARD" > /dev/null; then
    echo "Unmounting $SD_CARD..."
    umount "$SD_CARD"*
fi

# Flash the firmware image to the SD card
echo "Flashing $FIRMWARE_IMAGE to $SD_CARD..."
sudo dd if="$FIRMWARE_IMAGE" of="$SD_CARD" bs=4M status=progress conv=fsync

# Sync to ensure all data is written
sync

echo "Firmware flashed successfully to $SD_CARD."