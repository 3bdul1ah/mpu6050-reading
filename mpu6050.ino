#include <Wire.h>

const int MPU_ADDR = 0x68; 
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22, 100000); 
  
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);

  Serial.println("Setup complete");
}

void readMPU6050Data() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false); 
  Wire.requestFrom(MPU_ADDR, 14, true); 

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();
}

void loop() {
  readMPU6050Data();

  Serial.print("AcX: "); Serial.print(AcX);
  Serial.print(", AcY: "); Serial.print(AcY);
  Serial.print(", AcZ: "); Serial.print(AcZ);
  Serial.print(", GyX: "); Serial.print(GyX);
  Serial.print(", GyY: "); Serial.print(GyY);
  Serial.print(", GyZ: "); Serial.println(GyZ);

  delay(500); 
}
