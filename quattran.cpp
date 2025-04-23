#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);
byte speed = 0;

void setup() {
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);  // Địa chỉ nhận
  radio.startListening();  // Lắng nghe
  pinMode(5, OUTPUT);      // Chân PWM điều khiển quạt
}

void loop() {
  if (radio.available()) {
    radio.read(&speed, sizeof(speed));  // Nhận tốc độ
    analogWrite(5, speed == 1 ? 50 : speed == 2 ? 128 : 255);  // Điều khiển PWM
  }
}
