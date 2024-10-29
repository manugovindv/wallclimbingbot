const int motorPin1 = 5; // IN1  
const int motorPin2 = 6; // IN2 
const int enablePin = 10; // ENA  

const int speed = 255;

void setup() { 
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT); 
  pinMode(enablePin, OUTPUT); 

  
  
  digitalWrite(motorPin1, LOW); 
  digitalWrite(motorPin2, LOW); 
  analogWrite(enablePin, 0); 
 
  Serial.begin(9600); 

  
  
} 
 
void loop() { 

  if (Serial.available() > 0) { 
    String input = Serial.readStringUntil('\n'); 
    input.trim();  
    if (input.startsWith("F")) { 
      //int speed = input.substring(1).toInt();  
      //speed = constrain(speed, 0, 255);  
      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, LOW); 
      analogWrite(enablePin, speed); 
      Serial.write("F key pressed, Motor speed is: ");
      Serial.write(speed);
      Serial.write("\n");

    }  
     
    else if (input.startsWith("R")) { 
      // int speed = input.substring(1).toInt();  
      // speed = constrain(speed, 0, 255);  
      digitalWrite(motorPin1, LOW); 
      digitalWrite(motorPin2, HIGH); 
      analogWrite(enablePin, speed); 
      Serial.write("R key pressed, Motor speed is: ");
      Serial.write(speed);
      Serial.write("\n");
    }  
     
     
    else { 
      digitalWrite(motorPin1, LOW); 
      digitalWrite(motorPin2, LOW); 
      analogWrite(enablePin, 0); 
    } 
  
} }