// Enter the following commands to turn on/off

// Fs - Start first pump
// Fe - Stop first pump

// Fs - Start first pump
// Fe - Stop first pump

// Mf - Run motor in forward direction
// Mf - Run motor in reverse direction
// Mo - Turn the motor off


//pump setup
int relayPin1 = 8;  // Pin for controlling the first relay
int relayPin2 = 9;  // Pin for controlling the second relay
int interval = 2000;

//motor setup
const int motorPin1 = 5; // IN1  
const int motorPin2 = 6; // IN2 
const int enablePin = 10; // ENA  

const int speed = 255;


void setup() {

  Serial.begin(9600);

  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT); 
  pinMode(enablePin, OUTPUT); 

  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  
  
  digitalWrite(motorPin1, LOW); 
  digitalWrite(motorPin2, LOW); 
  analogWrite(enablePin, 0); 

  
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


  //motor

    if (input.startsWith("Mf")) { 

      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, LOW); 
      analogWrite(enablePin, speed); 
      Serial.write("F key pressed, Motor speed is: ");
      Serial.write(speed);
      Serial.write("\n");
    } 
    else if (input.startsWith("Mr")) { 
      // int speed = input.substring(1).toInt();  
      // speed = constrain(speed, 0, 255);  
      digitalWrite(motorPin1, LOW); 
      digitalWrite(motorPin2, HIGH); 
      analogWrite(enablePin, speed); 
      Serial.write("R key pressed, Motor speed is: ");
      Serial.write(speed);
      Serial.write("\n");
    }
    else if (input.startsWith("Mo")) { 
      // int speed = input.substring(1).toInt();  
      // speed = constrain(speed, 0, 255);  
      digitalWrite(motorPin1, LOW); 
      digitalWrite(motorPin2, LOW); 
      analogWrite(enablePin, 0); 
      Serial.write("Moff , Motor speed is: 0\n");
      //Serial.write(0);
      //Serial.write("\n");
    }
  }
}
