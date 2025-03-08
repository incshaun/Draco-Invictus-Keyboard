# Draco-Invictus-Keyboard
Converts wired keyboards into bluetooth keyboards

This project contains the software and hardware schematics for a device that allows older PS/2 style keyboards to appear as a bluetooth keyboard. The board uses an ESP32 system-on-chip microcontroller to provide the processing and bluetooth functionality, and requires some level converters to manage the 3.3V required by the ESP32 and 5V required by the PS/2 keyboard.

The software is largely derived from:
* https://github.com/T-vK/ESP32-BLE-Keyboard: for the bluetooth functionality.
* https://github.com/techpaul/PS2KeyAdvanced: for the PS/2 keyboard handling.
* https://github.com/ab0tj/PS2KeyAdvanced-Pico: for some fixes to PS/2 keyboard handling using ESP32
The licenses from these repositories applies to the corresponding code in this repository.

# Software

The software can be compiled and installed using the arduino IDE configured to support an ESP32 Dev Module.

The current version handles the standard keys, as well as capslock and numlock. Additional multimedia keys are not currently supported.

# Hardware

![View of the completed board](https://github.com/incshaun/Draco-Invictus-Keyboard/blob/main/images/complete.png)

Notes:
* Power to the unit is supplied using an USB connector. A powerbank is a suitable power source, and allows the keyboard to be portable.
* The ESP32 module is attached to an adapter board (e.g., https://www.komputer.de/zen/index.php?main_page=product_info&products_id=422). This provides buttons to reset and flash the software onto the chip. Note that pull-up resistors on the EN and IO0 lines are required and may not be present on the adapter board. Replacements ($10 \mathsf{k\Omega}$) are included in the schematic and board layout.
* External connector J1 is provided to attached an FTDI FT232RL USB Serial Converter module (e.g., https://littlebirdelectronics.com.au/products/ftdi-ft232rl-usb-to-ttl-serial-converter-adapter-module-5v-and-3-3v). Make sure that this is connected the right way around (GND pin should connect to the ground line), and that the voltage level is set to 3.3 V using the jumper on the board. This module can be removed once the software has been transferred.

The circuit diagram schematic:

![Schematic](https://github.com/incshaun/Draco-Invictus-Keyboard/blob/main/hardware/sch.png)

The circuit board layout:

![Circuit board layout](https://github.com/incshaun/Draco-Invictus-Keyboard/blob/main/hardware/pcb.png)

## Views of an assembled board

Top:

![Top View](https://github.com/incshaun/Draco-Invictus-Keyboard/blob/main/images/top.png)

Bottom (flipped to correspond with circuit layout):

![Bottom View](https://github.com/incshaun/Draco-Invictus-Keyboard/blob/main/images/bottom.png)
