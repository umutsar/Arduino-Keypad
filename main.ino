#include <Keypad.h>
#include "string.h"

const byte row = 4;
const byte col = 4;

char num;

String buffer;

char num_pad[row][col] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte row_pins[row] = { 13, 12, 11, 10 };
byte col_pins[col] = { 9, 8, 7, 6 };

Keypad newKeyPad = Keypad(makeKeymap(num_pad), row_pins, col_pins, row, col);

void setup() {
  Serial.begin(9600);
}

void loop() {
  num = newKeyPad.getKey();
  if (num) {
    buffer += num;
    Serial.println(buffer);
  }

  if (buffer.length() == 4) {
    if (buffer == "1453") {
      Serial.println("Authentication Succesfull!");
      buffer = "";
    } else {
      Serial.println("Wrong Password!!!");
      buffer = "";
    }
  }
}
