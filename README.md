# mantaray2040
*The Mantaray2040 is a ZSA Voyager inspired low-profile, ortholinear, column staggered ergonomic mechanical keyboard. The design is intended to provide a low-cost, easy to build alternative to the ZSA Voyager for users who aren't looking for a split keyboard design.*

Keyboard Creator and Maintainer: [Colton Hawkins AKA TuxedoMakes](https://youtube.com/@TuxedoMakes)

![mantaray2040](https://i.imgur.com/LBJzdiN.jpeg)

![mantaray2040](https://i.imgur.com/M4AyEyV.jpeg)

*Key features:*
- PCB is compatible with any pro-micro board
- 128x32 vertical OLED
- USB-C
- Kailh choc v1 switch compatible
- Ultra thin, ultra portable

## Build Guide
*Video guide available on my [YouTube channel](https://www.youtube.com/@TuxedoMakes).*
* Supported Controllers: *Anything pro-micro pin compatible. The provided firmware has been built for an RP2040-based pro-micro compatible controller.*
* Hardware Needed:
  - 1 x Mantaray PCB
  - 1 x RP2040 Pro Micro Controller ([Amazon](https://amzn.to/428M2m1), [AliExpress](https://www.aliexpress.us/item/3256806600745653.html))
  - 52 x Kailh Hotswap Sockets ([Amazon](https://amzn.to/4h6iSsb))
  - 52 x Kailh Choc V1 Switches ([Amazon](https://amzn.to/4fRsSVb))
  - 52 x 1N4148 through-hole Diodes ([Amazon](https://amzn.to/40qinUf))
    - Alternatively, you can use surface mount diodes ([Amazon](https://amzn.to/3WbPPeA))
  - 1 x 3D printed case (STL files available here, or via [MakerWorld]())

## Firmware
There are two options for getting the firmware file:
1. download the pre-build firmware file from this repository (mantaray2040_default.u2f)
2. build the firmware yourself from the source provided in this repository

**How to build the firmware (after setting up the build environment):**
1. Set up your build environment according to the QMK documentation for your OS

2. Clone the mantaray2040 repo, unzip the file, and add it to you qmk_firmware/keyboards folder

3. Run the build command. Below is an example for linux:

    qmk compile -kb mantaray2040 -km default
4. You  should now have a firmware file named mantaray2040_default.uf2 in the qmk_firmware directory (or the output directory you specified).

**How to flash the firmware:**
1. Download the 
1. Enter the bootloader by plugging in your mantaray2040 and double tapping the "reset" button.
2. A removable drive should appear named "RPI-RP2" or similar.
3. Drag and drop the mantaray2040_default.u2f firmware file onto the "RPI-RP2" removable drive.
4. Your keyboard should now be flashed and ready to use.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Double tap the "Reset" button located on your microcontroller. Alternatively, if you've installed the optional reset button on the front of the PCB, double tap that.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (top right key on layer 2)
