#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7, 8);
const byte address[10] = "ADDRESS01";

void setup() {

  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  };

void loop() {
  if (radio.available()) {
  char txt[32] =  "";
  radio.read(&txt, sizeof(txt));
  Serial.println(txt);
  };
};
