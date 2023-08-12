#include <PS4Controller.h>
unsigned long lastTimeStamp = 0;

void setup() {
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
}

void loop() {
}

void onConnect() {
  Serial.println("Connected!.");
}

void notify() {
  char messageString[255];

  sprintf(messageString, "%3d,%3d,%3d,%3d,%3d,%3d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d,%2d",
          PS4.LStickX(),
          PS4.LStickY(),
          PS4.RStickX(),
          PS4.RStickY(),
          PS4.L2Value(),
          PS4.R2Value(),
          PS4.Left(),
          PS4.Down(),
          PS4.Right(),
          PS4.Up(),
          PS4.Square(),
          PS4.Cross(),
          PS4.Circle(),
          PS4.Triangle(),
          PS4.L1(),
          PS4.R1(),
          PS4.L2(),
          PS4.R2(),
          PS4.L3(),
          PS4.R3(),
          PS4.Share(),
          PS4.Options(),
          PS4.PSButton(),
          PS4.Touchpad(),
          PS4.Charging(),
          PS4.Audio(),
          PS4.Mic(),
          PS4.Battery());
		  
  /*
  sprintf(messageString, "gx:%d,gy:%d,gz:%d,ax:%d,ay:%d,az:%d,",
          PS4.GyrX(),
          PS4.GyrY(),
          PS4.GyrZ(),
          PS4.AccX(),
          PS4.AccY(),
          PS4.AccZ());

  sprintf(messageString, "lx:%d,ly:%d,rx:%d,ry:%d,",
          PS4.LStickX(),
          PS4.LStickY(),
          PS4.RStickX(),
          PS4.RStickY());
  */

  //Only needed to print the message properly on serial monitor. Else we dont need it.
  if (millis() - lastTimeStamp > 50) {
    Serial.println(messageString);
    lastTimeStamp = millis();
  }
}

void onDisConnect() {
  Serial.println("Disconnected!.");
}