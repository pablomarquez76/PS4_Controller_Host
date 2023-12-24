#include <PS4Controller.h>

int r = 255;
int g = 0;
int b = 0;

// Calculates the next value in a rainbow sequence
void nextRainbowColor() {
  if (r > 0 && b == 0) {
    r--;
    g++;
  }
  if (g > 0 && r == 0) {
    g--;
    b++;
  }
  if (b > 0 && g == 0) {
    r++;
    b--;
  }
}

void setup() {
  Serial.begin(115200);

  // May use SixaxisPairTool, sixaxispairer or similars tool to synchronize
  // joystick with ESP32 
  PS4.begin();
  Serial.println("Ready.");
}

void loop() {
  if (PS4.isConnected()) {
    // Sets the color of the controller's front light
    // Params: Red, Green,and Blue
    // See here for details: https://www.w3schools.com/colors/colors_rgb.asp
    PS4.setLed(r, g, b);
    nextRainbowColor();

    // Sets how fast the controller's front light flashes
    // Params: How long the light is on , how long the light is off
    // Range: 0->255 (255 = 2550ms), Set to 0, 0 for the light to remain on
    PS4.setFlashRate(PS4.LStickY(), PS4.RStickY());

    // Sets the rumble of the controllers
    // Params: Weak rumble intensity, Strong rumble intensity
    // Range: 0->255
    PS4.setRumble(PS4.L2Value(), PS4.R2Value());

    // Sends data set in the above three instructions to the controller
    PS4.sendToController();

    // Don't send data to the controller immediately, will cause buffer overflow
    delay(10);
  }
}
