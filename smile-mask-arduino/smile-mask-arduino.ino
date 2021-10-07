#include <Arduino.h>

bool hasUpdate = true;
int lastCommand = 0;

#include "display.h"
#include "ir.h"

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello from the Arduino :)");
  Display::setup();
  Ir::setup();
}

void loop(void) {
  Display::loop();
  Ir::loop();
}
