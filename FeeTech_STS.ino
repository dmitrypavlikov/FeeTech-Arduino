#include <SCServo.h>
SCSCL servomotor;

void setup() {
  
  Serial.begin(9600);
  Serial3.begin(1000000); //Serial for servomotor
  servomotor.pSerial = &Serial3;  //Serial for servomotor
  /*delay(300);
  servomotor.writeByte(1, 55, 0); //unlock eprom
  Serial.println(servomotor.readByte(1, 55));
  delay(300);*/
  
 
  int ID = servomotor.Ping(1);
  Serial.print("ID ");
  Serial.println(servomotor.Ping(1));
  delay(300);
  
  //servomotor.unLockEprom(1);
  Serial.print("Lock");
  Serial.println(servomotor.readByte(1, 40));
  delay(300);
  servomotor.writeByte(1, u8(40), u8(1));
  Serial.println(servomotor.readByte(1, 40));
  
  servomotor.writeByte(1, u8(26), u8(0));
  servomotor.writeByte(1, u8(27), u8(0));
  delay(3000);
}

void loop() {
 
  servomotor.writeWord(1, 46, 500); // id param (address) value
  Serial.println(servomotor.readWord(1, 46));
  /*Serial.println(servomotor.readWord(1, 33));
  servomotor.writeByte(1, 40, 1);
  Serial.println(servomotor.readWord(1, 40));
  delay(300);*/
}
