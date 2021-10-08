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

  if (
      // On the remote, most keys use the NEC protocol.
      IrReceiver.decodedIRData.protocol == NEC ||
      // The power button uses an unknown protocol and has rawDataPtr->rawlen
      // 100. There are often stray signals, which look the same except they
      // have a smaller rawlen.
      (IrReceiver.decodedIRData.protocol == UNKNOWN &&
       IrReceiver.decodedIRData.rawDataPtr->rawlen == 100)) {
    Serial.print("Recognized command: ");
    Serial.println(IrReceiver.decodedIRData.command);
    Serial.println();
    hasUpdate = true;
    lastCommand = IrReceiver.decodedIRData.command;
  }

  IrReceiver.resume();
}
}; // namespace Ir
