
// WaterWise – Smart Water Management System
// Ultrasonic sensor + GSM SMS alerts for rural water tanks

#define TRIG_PIN 9
#define ECHO_PIN 8
#define LED_PIN 13
#define THRESHOLD_CM 30

#include <SoftwareSerial.h>
SoftwareSerial gsm(7, 6); // RX, TX

long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void sendSMS(String message) {
  gsm.println("AT+CMGF=1");
  delay(100);
  gsm.println("AT+CMGS="+1234567890""); // Replace with your number
  delay(100);
  gsm.print(message);
  delay(100);
  gsm.write(26);
  delay(1000);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  gsm.begin(9600);
  delay(1000);
}

void loop() {
  long distance = readDistanceCM();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > THRESHOLD_CM) {
    digitalWrite(LED_PIN, HIGH);
    sendSMS("Water level low! Please refill the tank.");
    delay(30000); // avoid spamming
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(5000);
}
