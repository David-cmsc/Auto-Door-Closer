// Pin definitions
#define IR_SENSOR_PIN 4    // D4
#define IN1 26 //D26
#define IN2 27 //D27
//#define ENA 14 //D14

int sensorVal; 

// Door state
bool doorWasClosed = true;

void setup() {
  Serial.begin(115200);
  
  // IR sensor pin as input
  pinMode(IR_SENSOR_PIN, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //pinMode(ENA, OUTPUT);

  // Start with door closed position
  delay(1000);
  
  Serial.println("Door system ready!");
}

void loop() {
  sensorVal = digitalRead(IR_SENSOR_PIN);
  
  // IR sensor goes LOW when no reflection (door open)
  if (sensorVal == LOW && doorWasClosed) {
    doorWasClosed = false;

    // Wait 3 seconds then close
    delay(7000);
    closeDoor();
  }
  
}

void closeDoor() {
  Serial.println("Closing door...");
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  // Keep running motor WHILE door is still open
  while(sensorVal != HIGH) {
    sensorVal = digitalRead(IR_SENSOR_PIN);
    delay(100);
  }
   // Stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(500);
  
  // Immediately create slack
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  // reverse
  delay(5000);              // let out some line
  Serial.println("Slack Created!");
  
  // Stop - self locking holds door
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  Serial.println("Door closed!");
  doorWasClosed = true;
}
//   int timeout = 0;
//   while(sensorVal != HIGH && timeout < 50) {
//       sensorVal = digitalRead(IR_SENSOR_PIN);
//       delay(100);
//       timeout++;
// }
  