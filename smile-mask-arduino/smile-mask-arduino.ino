#include <Arduino.h>

#include "display.h"
#include "ir.h"

void setup(void) {
  Serial.begin(9600);
  Display::setup();
  Ir::setup();
}

void loop(void) {
  Display::loop();
  Ir::loop();
}
