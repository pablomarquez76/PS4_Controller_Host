# PS4_Controller_Host
Allows ESP32 to communicate with PS4 controller (can be used to control robots and other devices)

Use a PS4 controller with an ESP32

This is heavily based the library https://github.com/aed3/PS4-esp32 use to connect a PS4 controller to an ESP32. This library add accelerometer and gyroscope features.

Here's a video about how this library was made: https://youtu.be/BmlKBs27pgE

This repo can be downloaded as a zip file and imported into the Arduino IDE as a library.

Installation
The instructions on how to do this are base off what can be found here

The instructions below may no longer work. If they do not work for you, try applying changes from the various forks of this repo.

You can add the ESP32 boards to your Arduino IDE by adding them to the Boards Manager:
Open File -> Preferences
Paste the following URL in the Additional Boards Manager URLs field: https://dl.espressif.com/dl/package_esp32_index.json
Open the Boards Manager with Tools -> Board: "xxx" -> Boards Manager
Look for esp32 (probably the last one in the list), and click install (version 1.0.3 works best)
Select the ESP32 board you have with Tools -> Board: "xxx" under the section ESP32 Arduino
To install this library into your Arduino IDE:
Click on the "Code" button in the top right of this page
Select "Download Zip" (It's always a good idea to look through the code on this page first to make sure you know what you're downloading)
In the Arduino IDE, navigate to Sketch -> Include Library -> Add .ZIP Library, then select the file you just downloaded
Pairing the PS4 Controller:
When a PS4 controller is 'paired' to a PS4 console, it just means that it has stored the console's Bluetooth MAC address, which is the only device the controller will connect to. Usually, this pairing happens when you connect the controller to the PS4 console using a USB cable, and press the PS button. This initiates writing the console's MAC address to the controller.

Therefore, if you want to connect your PS4 controller to the ESP32, you either need to figure out what the Bluetooth MAC address of your PS4 console is and set the ESP32's address to it, or change the MAC address stored in the PS4 controller.

Whichever path you choose, you might want a tool to read and/or write the currently paired MAC address from the PS4 controller. You can try using sixaxispairer for this purpose.
