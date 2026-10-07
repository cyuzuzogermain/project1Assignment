Smart Parking Indicator - Tinkercad Deliverables
=================================================

1) Tinkercad Circuit Design
---------------------------
Components:
- Arduino Uno
- HC-SR04 ultrasonic sensor
- 1 green LED
- 1 red LED
- 1 buzzer
- 220 ohm resistors, one per LED
- breadboard and jumper wires

Wiring:
- Ultrasonic sensor:
    VCC  -> 5V
    GND  -> GND
    Trig -> Arduino pin 9
    Echo -> Arduino pin 10

- Green LED (space available):
    anode (long leg) -> 220 ohm resistor -> Arduino pin 6
    cathode           -> GND

- Red LED (space occupied):
    anode (long leg) -> 220 ohm resistor -> Arduino pin 7
    cathode           -> GND

- Buzzer:
    positive terminal -> Arduino pin 8
    negative terminal -> GND

- Common ground:
    All GND connections share the same ground rail.

Tinkercad tips:
- In simulation, move the object near the ultrasonic sensor to change
  the measured distance.
- Open the Serial Monitor in Tinkercad or the Arduino IDE to see the
  reported distance.


2) Block Diagram
----------------
Ultrasonic Sensor (HC-SR04)
        |
        |  Trig + Echo
        v
Arduino Uno
        |
        |  read pulse duration
        |  convert to distance
        |  compare to threshold
        v
Decision / Processing
   occupied if distance <= threshold
        |
        +--> Green LED  (available)
        +--> Red LED    (occupied)
        +--> Buzzer     (alert when occupied)


3) Arduino Source Code
-----------------------
File: parking_indicator.ino

Main behavior:
- Ultrasonic sensor:
    Arduino sends a 10 microsecond trigger pulse,
    then measures the echo pulse width with pulseIn().
- Distance calculation:
    distanceCm = duration / 58
    If duration is 0 (no echo), the code assumes no vehicle and
    sets distance to a large placeholder value.
- Occupancy condition:
    occupied = (distanceCm <= PARKING_THRESHOLD_CM)
- Outputs:
    if occupied:
        green LED OFF
        red LED ON
        buzzer ON
    else:
        green LED ON
        red LED OFF
        buzzer OFF


4) Simulation Test Cases
------------------------
Test Case 1 - Vehicle outside the threshold (space available)
- Simulated distance: 30 cm (greater than threshold)
- Expected outputs:
    Green LED ON
    Red LED OFF
    Buzzer OFF
- Serial output example:
    Distance: 30 cm

Test Case 2 - Vehicle within the threshold (space occupied)
- Simulated distance: 10 cm (less than or equal to threshold)
- Expected outputs:
    Green LED OFF
    Red LED ON
    Buzzer ON
- Serial output example:
    Distance: 10 cm

Optional transition test:
- Start with distance at 30 cm, then move it to 20 cm and below.
- The system should change state around the threshold value of 20 cm.


5) Short Explanation
---------------------
Role of each component:
- Ultrasonic sensor: measures distance to the nearest object by
  sending a sound pulse and timing the echo.
- Arduino Uno: reads the sensor, calculates distance, decides whether
  the space is occupied, and drives the outputs.
- Green LED: shows that the parking space is available.
- Red LED: shows that the parking space is occupied.
- Buzzer: gives an audible alert when a vehicle is detected within the
  threshold distance.

How sensor data is processed:
- The Arduino triggers the ultrasonic sensor and records the echo
  pulse duration.
- It converts that duration into a distance in centimeters.
- It compares the distance to a fixed threshold.
- If the distance is at or below the threshold, the space is treated
  as occupied; otherwise it is treated as available.

How the Arduino controls the outputs:
- The Arduino sets the green LED, red LED, and buzzer pins HIGH or LOW
  depending on the occupancy decision.
- This happens repeatedly in loop(), so the indicator follows changes
  in the simulated distance.


6) Data Flow Summary
---------------------
Ultrasonic Sensor -> Arduino Uno -> Decision/Processing -> LEDs + Buzzer
