#include <SCServo.h>
SCSCL servomotor;

void setup() {
  Serial.begin(9600);
  Serial3.begin(1000000);
  servomotor.pSerial = &Serial3;
  
  Serial.println(servomotor.Ping(1));
  servomotor.writeByte(1, u8(40), u8(1));
  servomotor.writeByte(1, u8(26), u8(0));
  servomotor.writeByte(1, u8(27), u8(0));
}

void loop() {
  servomotor.writeWord(1, 46, 100); // id param (address) value
  Serial.println(servomotor.readWord(1, 46));
  delay(2000);
  servomotor.writeWord(1, 46, -100); // id param (address) value
  Serial.println(servomotor.readWord(1, 46));
  delay(2000);
}
