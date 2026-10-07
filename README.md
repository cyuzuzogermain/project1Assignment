# project1Assignment

Collection of assignment questions and deliverables for a C programming project.

## Questions

- **Question1/** — question 1 materials
- **Question2/** — question 2 materials
- **Question3/** — question 3 materials
- **Question4/** — question 4 materials

## Question4 overview

Question4 contains a Tinkercad-based smart parking indicator project.

Included files:
- `parking_indicator.ino` — Arduino sketch for the parking indicator
- `README.txt` — project explanation, wiring, block diagram, test cases, and data flow

Project behavior:
- An ultrasonic sensor measures distance to a vehicle
- An Arduino Uno reads the sensor and decides whether the space is occupied
- A green LED indicates availability, a red LED indicates occupancy
- A buzzer sounds when a vehicle is detected within the defined threshold

Defined threshold:
- `PARKING_THRESHOLD_CM = 20`

Pin assignment used in the sketch:
- Ultrasonic Trig: pin 9
- Ultrasonic Echo: pin 10
- Green LED: pin 6
- Red LED: pin 7
- Buzzer: pin 8

## Setup overview

### General setup

1. Open the relevant question folder.
2. Read the question README or instructions first.
3. Follow the question-specific setup notes in `SETUP.md`.
4. Build or simulate as described for that question.

### Question4 setup

Question4 is a Tinkercad simulation project, not a local C build.

1. Open Tinkercad Circuits.
2. Create or load an Arduino Uno circuit.
3. Add the required components:
   - HC-SR04 ultrasonic sensor
   - green LED
   - red LED
   - buzzer
   - current-limiting resistors for the LEDs if needed in your design
4. Wire the components as described in `Question4/README.txt`.
5. Copy the contents of `parking_indicator.ino` into the Tinkercad Arduino code editor.
6. Run the simulation and change the simulated distance to test the outputs.

### Expected Question4 simulation behavior

- When the simulated distance is above the threshold, the green LED should be ON, and the red LED and buzzer should be OFF.
- When the simulated distance is at or below the threshold, the red LED and buzzer should be ON, and the green LED should be OFF.

## How the deliverables are organized

Each question folder should contain:
- the question instructions or reference material, if any
- the solution or deliverable files
- any setup or run instructions specific to that question

If a question needs local compilation or execution, its folder should include the source files and the commands needed to build and run it.

## Notes

- Some questions may be simulation-only projects, such as Question4.
- Some questions may be local code projects that need to be compiled and run.
- See `SETUP.md` for user-facing setup and run instructions.
