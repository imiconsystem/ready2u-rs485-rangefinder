const int numBytes = 8;
const byte modbusQuery[numBytes] = {0x04, 0x03, 0x01, 0x00, 0x00, 0x01, 0x85, 0xA3}; // Ultrasonic DYP A01A
byte buffQuery[numBytes];

byte ByteArray[9];
int ByteData[9];

void serialSetup() {
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);  //
}

void serialLoop() {

  SerialProcessData();
  delay(5000);
}

void SerialProcessData() {

  for (int j = 0; j < numBytes; j++) {
    Serial2.write(modbusQuery[j]);
  }
  int a = 0;
  while (Serial2.available() > 0) {
    ByteArray[a] = Serial2.read();
    a++;
  }

  ByteData[0] = ByteArray[3] * 256 + ByteArray[4];

  RANGE = (ByteData[0] * 0.1)-setVar0;

  Serial.print("RANGE ");
  Serial.print(RANGE);

  
}