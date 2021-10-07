////////
// Designing the Absurd
// Pedro Oliveira 2020/2021
// IR Receiver

#define DECODE_NEC
#include <IRremote.h>

// Constant IR Receiver Pin (IR input)
// Arduino Uno / Nano Every - pin 2
#define IR_RECEIVE_PIN 2
#define ENABLE_LED_FEEDBACK true

namespace Ir {
void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("IR Receiver Pin: ");
  Serial.println(IR_RECEIVE_PIN);
}

void loop() {
  if (!IrReceiver.decode()) {
    return;
  }

  IrReceiver.printIRResultShort(&Serial);
  Serial.println(IrReceiver.decodedIRData.command);

  IrReceiver.resume();
}
}; // namespace Ir
