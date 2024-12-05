#include <IRsend.h>

const uint16_t kIrLed = 3;  // GPIO onde o LED IR está conectado
IRsend irsend(kIrLed);

uint32_t codes[] = { 0x20DF10EF, 0x20DF906F, 0x20DF30CF };
const int numCodes = sizeof(codes) / sizeof(codes[0]);

void setup() {
  irsend.begin();
}

void loop() {
  for (int i = 0; i < numCodes; i++) {
    irsend.sendNEC(codes[i]);
    delay(500);  // Pequena pausa entre os sinais
  }
}
