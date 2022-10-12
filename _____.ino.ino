#include <ArduinoJson.h>

int duration1 = 0; // left
int duration2 = 0; // mid
int duration3 = 0; // right

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // left
  pinMode(2, OUTPUT); // TRIG
  pinMode(3, INPUT);  // ECHO

  // middle
  pinMode(4, OUTPUT); // TRIG
  pinMode(5, INPUT);  // ECHO
  
  // right
  pinMode(6, OUTPUT); // TRIG
  pinMode(7, INPUT);  // ECHO
}

void loop() {
  // put your main code here, to run repeatedly:
  StaticJsonDocument<200> doc;
  String json;

  digitalWrite(2,LOW);
  delayMicroseconds(2);
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  duration1 = pulseIn(3, HIGH);
  
  digitalWrite(4,LOW);
  delayMicroseconds(2);
  digitalWrite(4,HIGH);
  delayMicroseconds(10);
  digitalWrite(4,LOW);
  duration2 = pulseIn(5, HIGH);

  digitalWrite(6,LOW);
  delayMicroseconds(2);
  digitalWrite(6,HIGH);
  delayMicroseconds(10);
  digitalWrite(6,LOW);
  duration3 = pulseIn(7, HIGH);

  doc["left"]   = duration1 / 29 / 2;
  doc["middle"] = duration2 / 29 / 2;
  doc["right"]  = duration3 / 29 / 2;

  serializeJson(doc, json);
  Serial.println(json);
  delay(1000);
}
