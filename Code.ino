// Define pins for IR sensors
#define LEFT_SENSOR A0
#define MIDDLE_SENSOR A1
#define RIGHT_SENSOR A2

// Define pins for motors
#define LEFT_MOTOR 5
#define RIGHT_MOTOR 6

// Define threshold value for sensors
#define THRESHOLD 500

void setup() {
  // Set pin modes for sensors and motors
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(MIDDLE_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(LEFT_SENSOR);
  int middleSensorValue = analogRead(MIDDLE_SENSOR);
  int rightSensorValue = analogRead(RIGHT_SENSOR);
  
  // Determine if the robot should turn left, go straight, or turn right
  if (leftSensorValue > THRESHOLD && middleSensorValue > THRESHOLD && rightSensorValue > THRESHOLD) {
    // All sensors are on the line, so go straight
    digitalWrite(LEFT_MOTOR, HIGH);
    digitalWrite(RIGHT_MOTOR, HIGH);
  } else if (leftSensorValue > THRESHOLD && middleSensorValue < THRESHOLD && rightSensorValue < THRESHOLD) {
    // Only left sensor is on the line, so turn left
    digitalWrite(LEFT_MOTOR, LOW);
    digitalWrite(RIGHT_MOTOR, HIGH);
  } else if (leftSensorValue < THRESHOLD && middleSensorValue < THRESHOLD && rightSensorValue > THRESHOLD) {
    // Only right sensor is on the line, so turn right
    digitalWrite(LEFT_MOTOR, HIGH);
    digitalWrite(RIGHT_MOTOR, LOW);
  } else if (leftSensorValue < THRESHOLD && middleSensorValue > THRESHOLD && rightSensorValue < THRESHOLD) {
    // Only middle sensor is on the line, so go straight
    digitalWrite(LEFT_MOTOR, HIGH);
    digitalWrite(RIGHT_MOTOR, HIGH);
  } else {
    // No sensors are on the line, so stop
    digitalWrite(LEFT_MOTOR, LOW);
    digitalWrite(RIGHT_MOTOR, LOW);
  }
}
