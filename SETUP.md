# Setup and Run Guide

Use this file to set up and run each question in this project.

## Before you start

1. Decide which question you want to work on.
2. Open that question’s folder.
3. Read the question instructions and any question-specific README first.
4. If the question is a simulation project, open the simulator before changing code.
5. If the question is a local code project, check for source files and build instructions.

---

## Question1

### Setup

1. Open `Question1/`.
2. Check for source files and any README or instructions inside that folder.
3. If it is a C project, confirm you have a C compiler available.
4. If it is a simulation or worksheet, follow the instructions in that folder.

### Run

- If it compiles locally, build and run it from `Question1/` using the commands supplied there.
- If it is a simulation or written deliverable, complete the steps described in the question materials.

---

## Question2

### Setup

1. Open `Question2/`.
2. Look for source files, instructions, or a README.
3. If the project needs a compiler, make sure one is installed and available.
4. If the project needs other tooling, follow any notes inside the folder.

### Run

- Use the build and run commands provided in `Question2/`.
- If no commands are provided, ask for them before changing anything.
- For non-code deliverables, follow the question instructions directly.

---

## Question3

### Setup

1. Open `Question3/`.
2. Check whether this is a code project, a simulation, or a document deliverable.
3. If it is a code project, locate the main source file or build script.
4. If it requires a specific toolchain, note it before building.

### Run

- If there is a build step, run it from inside `Question3/`.
- If there is a run step, run the resulting executable or script as instructed.
- If the folder contains only documentation or a written answer, review it against the question requirements.

---

## Question4

Question4 is the smart parking indicator Tinkercad simulation.

### Setup

1. Open Tinkercad Circuits.
2. Create a new circuit or open the existing one for this question.
3. Add the following components:
   - Arduino Uno
   - HC-SR04 ultrasonic sensor
   - green LED
   - red LED
   - buzzer
   - current-limiting resistors for the LEDs if required by your wiring
4. Wire the components as described in `Question4/README.txt`.
5. Open `Question4/parking_indicator.ino` and copy its contents into the Arduino code editor in Tinkercad.

### Run

1. Start the simulation in Tinkercad.
2. Open the Serial Monitor if you want to see the reported distance.
3. Move the simulated object relative to the ultrasonic sensor to change the measured distance.
4. Watch the LEDs and buzzer change state as the distance crosses the threshold.

### Quick test sequence

1. Set the simulated distance above 20 cm.
   - Expected: green LED ON, red LED OFF, buzzer OFF.
2. Set the simulated distance at or below 20 cm.
   - Expected: red LED ON, green LED OFF, buzzer ON.
3. Move the distance across the 20 cm boundary.
   - Expected: the outputs should change around the threshold.

### If something does not behave as expected

- Verify the wiring matches the README.
- Verify the pin numbers in the sketch match the wiring.
- Check that all grounds are connected together.
- Make sure each LED has a current-limiting resistor if your design uses one.
- Try changing the simulated distance slowly around the threshold to see the transition.

---

## General troubleshooting

- If a local project fails to build, check the compiler error messages first.
- If a simulation does not respond, confirm the component pins and connections.
- If a folder has no instructions, do not guess — ask for the setup steps for that question.
- After making changes, rerun the build or simulation and check the output again.
