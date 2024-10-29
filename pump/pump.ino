int relayPin1 = 8;  // Pin for controlling the first relay
int relayPin2 = 9;  // Pin for controlling the second relay
int interval = 2000;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
}

void loop() {

  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.startsWith("Fs")) {
      // Turn on the first pump
      digitalWrite(relayPin1, HIGH);
      Serial.println("Pump 1 ON");
      //delay(interval);
    }
    if (input.startsWith("Fe")) {
      // Turn off the first pump
      digitalWrite(relayPin1, LOW);
      Serial.println("Pump 1 OFF");
      //delay();
    }

    if (input.startsWith("Ss")) {
      // Turn on the second pump
      digitalWrite(relayPin2, HIGH);
      Serial.println("Pump 2 ON");
      //delay(interval);
    }

    if (input.startsWith("Se")) {
      // Turn off the second pump
      digitalWrite(relayPin2, LOW);
      Serial.println("Pump 2 OFF");
      //delay(1000);
    }
  }
}
