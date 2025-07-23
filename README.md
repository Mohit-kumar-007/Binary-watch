# ESP32 Binary LED Watch

A simple DIY binary watch project using ESP32 microcontroller and LEDs to display time in binary format.

## Youtube Video link - (https://youtube.com/shorts/v_yORGDut5M?feature=share)

## Overview

This project creates a binary clock/watch using an ESP32 microcontroller and LEDs. The time is displayed in binary format with separate LED indicators for hours and minutes.

## Hardware Requirements

- ESP32 Development Board
- 10 LEDs
  - 4 LEDs for Hours display (H0-H3)
  - 6 LEDs for Minutes display (M0-M5)
- Appropriate resistors for LEDs
- Jumper wires
- Power supply

## Pin Connections

### Hours Display
| Function | LED Bit | GPIO Pin |
|----------|---------|----------|
| Hours    | H0      | GPIO16   |
|          | H1      | GPIO17   |
|          | H2      | GPIO18   |
|          | H3      | GPIO19   |

### Minutes Display
| Function | LED Bit | GPIO Pin |
|----------|---------|----------|
| Minutes  | M0      | GPIO21   |
|          | M1      | GPIO22   |
|          | M2      | GPIO23   |
|          | M3      | GPIO25   |
|          | M4      | GPIO26   |
|          | M5      | GPIO27   |

## How to Read the Binary Watch

- Hours are displayed using 4 LEDs (representing 0-23 in binary)
- Minutes are displayed using 6 LEDs (representing 0-59 in binary)
- Each LED represents a bit in binary counting:
  - For Hours: H3 H2 H1 H0 (8-4-2-1)
  - For Minutes: M5 M4 M3 M2 M1 M0 (32-16-8-4-2-1)

## Example
To read the time:
- If H3 and H1 are lit (1010 in binary), that represents 10 hours
- If M5 and M2 are lit (100100 in binary), that represents 36 minutes
- So the time would be 10:36

## Setting Up

1. Connect the LEDs to the corresponding GPIO pins as shown in the pin connection table
2. Make sure to use appropriate resistors with the LEDs
3. Upload the code to your ESP32
4. Power up the device

## Notes
- Make sure to follow proper LED connection guidelines with appropriate current-limiting resistors
- The ESP32 operates on 3.3V logic level
