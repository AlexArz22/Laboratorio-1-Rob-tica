#include <Wire.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mpu;

const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 7;
const int IN4 = 6;
const int ENA = 9;
const int ENB = 10;

float L = 0.15;  // Distancia entre ruedas (metros)
float x = 0, y = 0, theta = 0;
unsigned long lastTime;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  mpu.setWire(&Wire);
  mpu.beginAccel();
  mpu.beginGyro();

  delay(200); // Esperar estabilización del sensor

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);

  // Dirección hacia adelante
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);

  lastTime = millis();
}

void loop() {
  mpu.gyroUpdate();  // Actualiza datos del giroscopio

  float gyroZ = mpu.gyroZ(); // Velocidad angular eje Z en °/s

  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime) / 1000.0;
  lastTime = currentTime;

  theta += gyroZ * dt * (PI / 180.0);  // Convertir a radianes

  int baseSpeed = 180;
  int correction = gyroZ * 0.5;

  int speedLeft = constrain(baseSpeed + correction, 0, 255);
  int speedRight = constrain(baseSpeed - correction, 0, 255);

  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  // Estimar posición usando cinemática diferencial
  float vL = speedLeft / 255.0 * 0.2;
  float vR = speedRight / 255.0 * 0.2;
  float v = (vR + vL) / 2.0;

  x += v * cos(theta) * dt;
  y += v * sin(theta) * dt;

  // Mostrar datos por el monitor serial
  Serial.print("X: "); Serial.print(x, 3);
  Serial.print(" | Y: "); Serial.print(y, 3);
  Serial.print(" | θ(rad): "); Serial.print(theta, 3);
  Serial.print(" | GyroZ: "); Serial.println(gyroZ, 2);

  delay(50);
}