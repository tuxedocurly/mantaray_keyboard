# Mantaray -  A ZSA Voyager Inspired Ergonomic Mechanical Keyboard
*The Mantaray2040 is a ZSA Voyager inspired low-profile, ortholinear, column staggered ergonomic mechanical keyboard. The design is intended to provide a low-cost, easy to build alternative to the ZSA Voyager for users who aren't looking for a split keyboard design.*

Keyboard Creator and Maintainer: [Colton Hawkins AKA TuxedoMakes](https://youtube.com/@TuxedoMakes)

![mantaray blue and red](https://github.com/user-attachments/assets/a529b1cd-dc40-4ec1-89aa-4ed37819612f)

![PXL_20250112_193250812](https://github.com/user-attachments/assets/bdc39298-31d2-4579-9593-ffe6afcdeefb)


*Key features:*
- PCB is compatible with any pro-micro board
- 128x32 vertical OLED
- USB-C
- Kailh choc v1 switch compatible
- Ultra thin, ultra portable

## <img src="https://storage.ko-fi.com/cdn/brandasset/v2/kofi_symbol.png" alt="Buy me a coffee" width="25"/> Support This Project (and Fuel Open Source!)

This project is a labor of love, built during my spare time. If you've found this keyboard design helpful, interesting, or just plain awesome, consider checking out [my shop](https://ko-fi.com/tuxedomakes/shop) where I sell PCBs and parts to make my projects, or buy me a coffee!

**Your support helps me:**

*   Dedicate more time to improve this design.
*   Experiment with new features and ideas.
*   Kickstart other open-source projects that you might love.

<a href='https://ko-fi.com/W7W51HGF6A' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://storage.ko-fi.com/cdn/kofi6.png?v=6' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

Even a small coffee-sized contribution goes a long way in fueling my passion for open source. If you use the shop, you'll get a useful part for your next project, plus my eternal gratitude!

**Thank you for being awesome!**

## Build Guide
*Video guide available on my [YouTube channel](https://www.youtube.com/@TuxedoMakes).*
* Supported Controllers: *Anything pro-micro pin compatible. The provided firmware has been built for an RP2040-based pro-micro compatible controller.*
* Hardware Needed:
  - 1 x Mantaray PCB
  - 1 x RP2040 Pro Micro Controller ([Amazon](https://amzn.to/428M2m1), [AliExpress](https://www.aliexpress.us/item/3256806600745653.html))
  - 52 x Kailh Hotswap Sockets ([Amazon](https://amzn.to/4h6iSsb))
  - 52 x Kailh Choc V1 Switches ([Amazon](https://amzn.to/4fRsSVb))
  - 52 x Kailh choc v1 compatible keycaps ([Amazon](https://amzn.to/4ae0R8R))
  - 52 x 1N4148 through-hole Diodes ([Amazon](https://amzn.to/40qinUf))
    - Alternatively, you can use surface mount diodes ([Amazon](https://amzn.to/3WbPPeA))
  - 1 x 128x32 SSD1306 OLED Display ([Amazon](https://amzn.to/3Wcarnd))
  - 1 x 3D printed case (STL files available in this repo, or via [MakerWorld](https://makerworld.com/en/models/972433#profileId-944453))
  - 8 x M2x5mm tapered head machine screws ([Amazon](https://amzn.to/3BTecHg))
  - Optional Stuff
    - 1 x Reset Button ([Amazon](https://amzn.to/3Pt3eer))
    - 1 x Syringe of Solder Flux ([Amazon](https://amzn.to/4fXnPT4))
    - 8 x M2x3x3.2mm Heat Set Inserts ([Amazon](https://amzn.to/40bUWMX))
      - While the inserts are technically optional, I highly recommend using them. They're awesome.

**Step 1: Solder Diodes**

Solder all the through hole or surface-mount diodes to the board. Note the direction of the diodes carefully, as they have a polarity (the black stripe should face the square contact on the PCB).

![Diode Placement](https://github.com/user-attachments/assets/a6efe06b-1570-4cf0-95db-6eb436ecb63f)

If you decide to use through-hole diodes like I did, be sure to solder the diodes from the  back side of the PCB to avoid globs of solder forming on the front side - the front of the PCB needs to be flat in order for the choc switches to sit flush when installed later.Also, be sure to trim the excess wire from the other side of the board to keep things as tidy and low-profile as possible. A good pair of nippers comes in handy here.

This is how the diodes should look after soldering
![diode_solder](https://github.com/user-attachments/assets/d3d3f572-a6b3-40e6-8724-1c0cec577d54)

This is how the front of the board should look after snipping off the excess diode legs to make them flush with the PCB.
![diode_snipped](https://github.com/user-attachments/assets/8b29630d-994d-40b7-afd7-616a1010b100)

**Step 2: Solder Hotswap Sockets**

Next, go ahead and place the hotswap sockets on the board and solder them in. This step is slightly tedious, but pretty straight forward.

Here's how the back of the PCB should look once the hotswap sockets are installed.
![hotswap_sockets](https://github.com/user-attachments/assets/ddb2e2c5-b924-47a3-9d69-25ec44674ac7)

**Step 3: Solder Controller to PCB**

Keeping everything low profile is very important here, so I used a mid-mount USB C RP2040 pro micro board. The provided case file is designed to work with this type of controller, and you *may* run into clearance issues if you use a standard top-mounted USB C pro micro.

With that out of the way, follow bakingpy's [guide](https://imgur.com/a/how-to-solder-pro-micro-header-pins-like-badass-M9r3EW9) to get the headers for the controller soldered to the PCB. TL;DR - solder the pin headers in to the bottom of the board, making sure they don't protrude from the front of the board. Once they're all soldered, remove the plastic spacer piece using some tweezers.

Once that's done, install the RP2040 Pro Micro on the bottom side of the keyboard PCB. The IC and reset buttons should be facing away from the PCB, allowing the microcontroller to sit nearly flush with the PCB. Trim the excess wire from the pin headers, and you're done with this step.

Here's how the final result should look:
![promicro_soldered](https://github.com/user-attachments/assets/c55196bb-65da-4a99-b59d-7218cf4dec99)
![promicro](https://github.com/user-attachments/assets/1b3c5b9c-f64c-4a23-8f65-d60cf14eb9df)

**Step 4: Solder OLED Display**

Time to install the display. Grab the 128x32 SSD1306 OLED and install it into the front of the pcb. The process is very similar to installing the controller to the PCB, but luckily we only have to deal with 4 pins this time. Follow bakingpy's [guide](https://imgur.com/a/how-to-solder-pro-micro-header-pins-like-badass-M9r3EW9) to install the 4 pin headers onto the front of the PCB, then add the OLED onto the headers and solder it into place. **Be sure to solder this as straight as posible, using the silkscreen lines on the front of the PCB as reference**. The display needs to be relatively straight in order to fit into its cutout in the top case later.

Here's how the display should look just before soldering it to the headers.
![oled](https://github.com/user-attachments/assets/afe8fe9d-5820-4436-bf20-06eaf8efa736)

**Step 5: (Optional) Install Front Reset Button**

Because the controller I chose has a reset button built into the board, and I built access to the button into the back of the 3D printed case, this step is not required; however, it is recommended as it makes accessing the bootloader a bit easier.

If you decide to add the reset button, there isn't much to say here. Grab a [reset button](https://amzn.to/3Pt3eer), and solder it onto the PCB. A bit of [flux](https://amzn.to/4fXnPT4) is extremely helpful here.

See the image above for a reference of the reset button install location.

**Step 6: The Case**

Print yourself a case using the files in this repo, or by grabbing them on [MakerWorld](https://makerworld.com/en/models/972433#profileId-944453).
![PXL_20250109_202859032](https://github.com/user-attachments/assets/9643e677-b60c-4c29-ab6f-15d350bfb17c)

Install the heat set inserts into each of the posts with holes on the bottom plate. Note that there are 4 posts that do not have holes for inserts. Those are supports for the PCB, and can be ignored.
![PXL_20250109_202824409](https://github.com/user-attachments/assets/c0f55b61-fee6-4fd1-b491-8f6372d1cfee)

Screw the PCB into the case using 8 x M2x5mm tapered head machine screws.

Place the top case over the PCB. Pay attention to the cutout for the OLED display, and make sure you soldered this straight enough to fit into the cutout. If needed, go back and reflow the solder to better align the display. You're almost done - hang in there!

**Step 7: Install Switches and Keycaps**

Grab your Kailh Choc V1 switches and install them over the plate, into the hotswap sockets on the pcb. Watch for bent pins. Once all the switches are installed, go ahead and add your keycaps.
![PXL_20250109_180317979](https://github.com/user-attachments/assets/e0e67303-9cf5-4d4d-b39c-639c156300bf)

**Step 8: Install the Firmware**

Hold down the reset button as you plug the keyboard into your computer. Release the reset button once the board is plugged in, and you should see a removable drive appear with the name "RPI-RP2". If this doesn't work, try plugging in the keyboard, then double tapping the reset button. Download the mantaray2040_default.u2f firmware file from this repo, then drag and drop it into the removable drive that appeared.

The keyboard should reboot, and the firmware should now be flashed! Enjoy your new ergonomic keyboard!

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
1. Download the mantaray2040_default.u2f firmware file, or compile the firmware yourself.
1. Enter the bootloader by plugging in your mantaray2040 and double tapping the "reset" button.
2. A removable drive should appear named "RPI-RP2" or similar.
3. Drag and drop the mantaray2040_default.u2f firmware file onto the "RPI-RP2" removable drive.
4. Your keyboard should now be flashed and ready to use.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Double tap the "Reset" button located on your microcontroller. Alternatively, if you've installed the optional reset button on the front of the PCB, double tap that.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (top right key on layer 2)

## ❤️ Support Me ❤️

If you liked this project, please consider checking out [my shop](https://ko-fi.com/tuxedomakes/shop) or [buying me a coffee ☕](https://ko-fi.com/tuxedomakes).
