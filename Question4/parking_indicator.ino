/*
  Smart Parking Indicator
  -----------------------
  Tinkercad-friendly Arduino sketch for a single parking-space monitor.

  Hardware used:
  - Arduino Uno
  - HC-SR04 ultrasonic sensor
  - Green LED  : parking space available
  - Red LED    : parking space occupied
  - Buzzer     : alert when a vehicle is within the threshold

  Sensor -> Arduino -> Processing -> LEDs + Buzzer

  Threshold:
  - If the measured distance is <= PARKING_THRESHOLD_CM,
    the space is considered OCCUPIED.
  - Otherwise it is AVAILABLE.

  Pin assignments (change these to match your Tinkercad wiring):
  - Ultrasonic Trig  -> pin 9
  - Ultrasonic Echo  -> pin 10
  - Green LED        -> pin 6
  - Red LED          -> pin 7
  - Buzzer           -> pin 8
*/

const int TRIG_PIN  = 9;
const int ECHO_PIN  = 10;

const int GREEN_LED_PIN = 6;
const int RED_LED_PIN   = 7;
const int BUZZER_PIN    = 8;

// Occupancy threshold in centimeters.
// A smaller value means the vehicle must be closer to count as "occupied".
const int PARKING_THRESHOLD_CM = 20;

void setup()
{
  // Ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Indicator/output pins
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Start serial monitor for simulation/debugging
  Serial.begin(9600);
  Serial.println("Smart Parking Indicator initialized");
  Serial.print("Occupancy threshold: ");
  Serial.print(PARKING_THRESHOLD_CM);
  Serial.println(" cm");
}

void loop()
{
  long duration;
  int distanceCm;

  // ---------------- 1. Read ultrasonic sensor ----------------
  // Send a 10 microsecond trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo pulse duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // ---------------- 2. Calculate distance ----------------
  // Duration is the round-trip time in microseconds.
  // Approximate conversion: duration / 58 ~= distance in cm.
  if (duration == 0) {
    // No echo received within timeout -> assume nothing detected
    distanceCm = 100;
  } else {
    distanceCm = duration / 58;
  }

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // ---------------- 3. Decision / processing ----------------
  bool occupied = (distanceCm <= PARKING_THRESHOLD_CM);

  // ---------------- 4. Control outputs ----------------
  if (occupied) {
    // Space occupied
    digitalWrite(GREEN_LED_PIN, LOW);   // green OFF
    digitalWrite(RED_LED_PIN,   HIGH);  // red ON
    digitalWrite(BUZZER_PIN,    HIGH);  // buzzer ON
  } else {
    // Space available
    digitalWrite(GREEN_LED_PIN, HIGH);  // green ON
    digitalWrite(RED_LED_PIN,   LOW);   // red OFF
    digitalWrite(BUZZER_PIN,    LOW);   // buzzer OFF
  }

  // Short delay so the simulation updates at a readable rate
  delay(200);
}
