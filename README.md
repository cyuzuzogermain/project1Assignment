# project1Assignment

Collection of assignment questions and deliverables for a C programming project.

## Questions

| Folder | Description |
|--------|-------------|
| [Question1](Question1/) | Water-Quality Monitoring Report (C console program) |
| [Question2](Question2/) | Mobile-Money Transaction System (C console program) |
| [Question3](Question3/) | Delivery Analysis Program (C console program) |
| [Question4](Question4/) | Smart Parking Indicator (Tinkercad Arduino simulation) |

---

## Question 1 — Water-Quality Monitoring Report

**Folder:** `Question1/`

**Files:**
- `water_quality.c` — source code
- `water_quality` — compiled executable
- `README.md` — full write-up (sample output, real-world application, error analysis, compilation lifecycle)

**Sample output:**

```
$ ./water_quality
=== Water Quality Monitoring Report ===
Temperature reading : 28 C
Turbidity reading   : 6 NTU
Water Quality Index : 94
Water Quality Status: Good
========================================
```

(These readings correspond to temperature = 28 °C and turbidity = 6 NTU.
TemperatureDeviation = |28 - 25| = 3, TurbidityPenalty = 6 / 2 = 3,
Index = 100 - (3 + 3) = 94 -> "Good".)

**What the program does:**

- Reads a fixed temperature (20 °C) and turbidity (6 NTU).
- Computes a Water Quality Index using:
  - `TemperatureDeviation = abs(temperature - 25)`
  - `TurbidityPenalty = turbidity / 2`
  - `Index = 100 - (TemperatureDeviation + TurbidityPenalty)`
- Classifies the result as `Good` (≥80), `Warning` (60–79), or `Critical` (<60).
- Prints a formatted report.

**How to build and run:**

```bash
cd Question1
gcc -o water_quality water_quality.c
./water_quality
```

For the full explanation (real-world application, syntax vs. semantic error analysis,
C compilation lifecycle), see [Question1/README.md](Question1/README.md).

---

## Question 2 — Mobile-Money Transaction System

**Folder:** `Question2/`

**Files:**
- `transaction_system.c` — source code
- `transaction_system` — compiled executable
- `README.md` — full write-up (sample input/output, how conditionals/loops/break/continue are used)
- `sample_run.txt` — recorded sample run

**Sample input/output:**

Input provided: `1`, `50000`, `2`, `70000`, `3`, `5`

```
$ ./transaction_system

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 1
Enter deposit amount: 50000
Deposit successful.
Current balance: 50000 RWF

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 2
Enter withdrawal amount: 70000
Transaction rejected: Insufficient balance.

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 3
Current balance: 50000 RWF

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 5
System terminated.
```

What this sample shows:

- **Deposit (choice 1):** 50000 RWF deposited, balance becomes 50000 RWF.
- **Invalid transaction (choice 2):** withdrawal of 70000 RWF is rejected
  because it exceeds the available balance.
- **Balance inquiry (choice 3):** displays the current balance.
- **Exit (choice 5):** terminates the program.

**What the program does:**

- Runs a menu-driven loop (`while (1)`) for a mobile-money agent.
- Supports deposit, withdrawal, balance check, and transaction summary.
- Validates all inputs: rejects non-numeric input, non-positive amounts,
  and withdrawals exceeding the balance.
- Uses `continue` to skip back to the menu on invalid input and `break`
  to control flow inside `switch` cases.

**How to build and run:**

```bash
cd Question2
gcc -o transaction_system transaction_system.c
./transaction_system
```

For the full explanation of how the program uses conditionals, loops,
`break`, and `continue`, see [Question2/README.md](Question2/README.md).

---

## Question 3 — Delivery Analysis Program

**Folder:** `Question3/`

**Files:**
- `delivery_analysis.c` — source code
- `delivery_analysis` — compiled executable
- `README.md` — full write-up (sample input/output, function breakdown, recursion explanation, advantage/limitation)

**Sample Input/Output:**

**Input:**
```
Enter number of routes (max 100): 5
Enter 5 distances (km):
12 25 8 30 15
Enter distance limit (km): 20
```

**Output:**
```
===== DELIVERY DISTANCE ANALYSIS =====

Total distance: 90 km
Average distance: 18.00 km
Longest route: 30 km
Routes above 20 km: 2

Recursive sum: 90 km

--- Function Reuse Demonstration ---
Routes above 10 km (half limit): 4
(Used count_above_limit() again with a different argument)
```

**What the program does:**

- Reads up to 100 route distances and a distance limit.
- Computes total distance, average distance, longest route,
  routes above the limit, and a recursive sum.
- Demonstrates function reuse: `average_distance()` calls `total_distance()`,
  and `count_above_limit()` is called twice with different limits.

**Functions:**

| Function | Purpose |
|---|---|
| `total_distance()` | Iterates through the array and sums all distances |
| `average_distance()` | Calls `total_distance()` and divides by `n` to compute the mean |
| `longest_route()` | Finds and returns the maximum value in the array |
| `count_above_limit()` | Counts how many distances exceed a given limit |
| `recursive_sum()` | Recursively computes the sum of the first `n` elements |
| `main()` | Handles input, calls all analysis functions, and displays results |

**How the recursive function works:**

`recursive_sum(int distances[], int n)`:
- **Base case:** When `n == 0`, returns `0`.
- **Recursive step:** Returns `distances[n - 1] + recursive_sum(distances, n - 1)`.

**Advantage:** Clean, concise code that mirrors the mathematical definition of a sum.
**Limitation:** Each recursive call adds a stack frame; for large arrays this can
cause stack overflow. An iterative loop is safer and more efficient at scale.

**How to build and run:**

```bash
cd Question3
gcc -o delivery_analysis delivery_analysis.c
./delivery_analysis
```

For the full explanation, see [Question3/README.md](Question3/README.md).

---

## Question 4 — Smart Parking Indicator

**Folder:** `Question4/`

**Files:**
- `parking_indicator.ino` — Arduino sketch
- `README.txt` — project explanation, wiring, block diagram, test cases, data flow

**Project behavior:**

- An ultrasonic sensor (HC-SR04) measures distance to a vehicle.
- An Arduino Uno reads the sensor and decides whether the space is occupied.
- A green LED indicates availability, a red LED indicates occupancy.
- A buzzer sounds when a vehicle is detected within the defined threshold.

**Defined threshold:**

- `PARKING_THRESHOLD_CM = 20`

**Pin assignment used in the sketch:**

| Component | Pin |
|-----------|------|
| Ultrasonic Trig | 9 |
| Ultrasonic Echo | 10 |
| Green LED | 6 |
| Red LED | 7 |
| Buzzer | 8 |

**Wiring:**

- **Ultrasonic sensor:** VCC → 5V, GND → GND, Trig → pin 9, Echo → pin 10
- **Green LED (space available):** anode → 220Ω resistor → pin 6, cathode → GND
- **Red LED (space occupied):** anode → 220Ω resistor → pin 7, cathode → GND
- **Buzzer:** positive → pin 8, negative → GND
- All GND connections share a common ground rail.

**Block diagram:**

```
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
```

**Arduino source code behavior (`parking_indicator.ino`):**

- Sends a 10 µs trigger pulse to the ultrasonic sensor.
- Measures the echo pulse width with `pulseIn()`.
- Calculates `distanceCm = duration / 58`.
- If `duration == 0` (no echo), assumes no vehicle and sets distance to a
  large placeholder value.
- If `distanceCm <= PARKING_THRESHOLD_CM`: green LED OFF, red LED ON, buzzer ON.
- Otherwise: green LED ON, red LED OFF, buzzer OFF.

**Simulation test cases:**

- **Test Case 1 — Vehicle outside threshold (space available):**
  - Simulated distance: 30 cm (greater than threshold)
  - Expected: Green LED ON, Red LED OFF, Buzzer OFF
  - Serial output: `Distance: 30 cm`

- **Test Case 2 — Vehicle within threshold (space occupied):**
  - Simulated distance: 10 cm (less than or equal to threshold)
  - Expected: Green LED OFF, Red LED ON, Buzzer ON
  - Serial output: `Distance: 10 cm`

- **Optional transition test:** Start at 30 cm, move to 20 cm and below.
  The system should change state around the threshold value of 20 cm.

**How to set up (Tinkercad):**

1. Open Tinkercad Circuits.
2. Create or load an Arduino Uno circuit.
3. Add the required components:
   - HC-SR04 ultrasonic sensor
   - green LED
   - red LED
   - buzzer
   - current-limiting resistors for the LEDs (220Ω recommended)
4. Wire the components as described above.
5. Copy the contents of `parking_indicator.ino` into the Tinkercad Arduino code editor.
6. Run the simulation and change the simulated distance to test the outputs.

**Expected simulation behavior:**

- When the simulated distance is above the threshold, the green LED should be ON,
  and the red LED and buzzer should be OFF.
- When the simulated distance is at or below the threshold, the red LED and buzzer
  should be ON, and the green LED should be OFF.

For the full project explanation, see [Question4/README.txt](Question4/README.txt).

---

## How the deliverables are organized

Each question folder contains:
- the question instructions or reference material, if any
- the solution or deliverable files
- any setup or run instructions specific to that question

If a question needs local compilation or execution, its folder includes the source
files and the commands needed to build and run it.

## Notes

- Some questions are simulation-only projects, such as Question 4 (Tinkercad).
- Some questions are local C projects that need to be compiled and run
  (Questions 1, 2, 3).
- See `SETUP.md` for user-facing setup and run instructions.
