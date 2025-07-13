#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  
  int valA = random(-100, 101);
  float valB = random(-100, 101) / 100.0;
  int valC = random(0, 1024);
  String msg = "Hi from UBUNTU";

  Serial.print(valA);
  Serial.print(",");
  Serial.print(valB, 3);
  Serial.print(",");
  Serial.print(valC);
  Serial.print(",");
  Serial.println(msg);

  delay(2000);

  
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "OFF") {
      digitalWrite(LED , LOW);
    } else if (command == "ON") {
      digitalWrite(LED, HIGH);
    }
  }
}

