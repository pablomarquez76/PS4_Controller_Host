#include <PS4Controller.h>
unsigned long lastTimeStamp = 0;
#define EVENTS 0
#define BUTTONS 0
#define JOYSTICKS 1
#define SENSORS 0

void setup() {
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready!");
}

void loop() {
  delay(100);
}

void onConnect() {
  Serial.println("Connected!");
}

void notify() {
#if EVENTS
  boolean sqd = PS4.event.button_down.square,
          squ = PS4.event.button_up.square,
          trd = PS4.event.button_down.triangle,
          tru = PS4.event.button_up.triangle;
  if (sqd)
    Serial.println("SQUARE down");
  else if (squ)
    Serial.println("SQUARE up");
  else if (trd)
    Serial.println("TRIANGLE down");
  else if (tru)
    Serial.println("TRIANGLE up");
#endif

#if BUTTONS
  boolean sq = PS4.Square(),
          tr = PS4.Triangle();
  if (sq)
    Serial.print(" SQUARE pressed");
  if (tr)
    Serial.print(" TRIANGLE pressed");
  if (sq | tr)
    Serial.println();
#endif

  //Only needed to print the message properly on serial monitor. Else we dont need it.
  if (millis() - lastTimeStamp > 50) {
#if JOYSTICKS
    Serial.printf("lx:%4d,ly:%4d,rx:%4d,ry:%4d\n",
                  PS4.LStickX(),
                  PS4.LStickY(),
                  PS4.RStickX(),
                  PS4.RStickY());
#endif
#if SENSORS
    Serial.printf("gx:%5d,gy:%5d,gz:%5d,ax:%5d,ay:%5d,az:%5d\n",
                  PS4.GyrX(),
                  PS4.GyrY(),
                  PS4.GyrZ(),
                  PS4.AccX(),
                  PS4.AccY(),
                  PS4.AccZ());
#endif
    lastTimeStamp = millis();
  }
}

void onDisConnect() {
  Serial.println("Disconnected!");
}
