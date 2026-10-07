# Water-Quality Monitoring Report

## Sample output (one test run)

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

---

## a. Real-world application

One common real-world application of C in embedded/systems programming is
firmware for microcontroller-based devices such as environmental sensors,
pacemakers, automotive engine controllers, or Arduino-compatible boards.

C is suitable for these applications because:

- It compiles to compact, predictable machine code with minimal runtime
  overhead, which matters on devices with limited memory and no operating
  system.
- It gives direct, low-level control over hardware (memory addresses,
  registers, I/O ports, interrupts) and lets developers reason about exact
  resource usage, timing, and footprint.
- Its small language core and long-standing compiler/toolchain support make
  it portable across many embedded architectures (ARM, AVR, ESP32, RISC-V,
  etc.), so the same kind of program can be retargeted more easily than with
  higher-level languages that depend on large runtimes.

---

## b. Error analysis

### Syntax error (example)
If you write:

```c
printf("Temperature reading : %d C\n", temperature   // missing closing parenthesis
```

This is a **syntax error** because the source code violates the grammatical
rules of C: the `printf` call is not properly closed. A compiler can detect
this purely from the structure of the code and will refuse to compile until
it is fixed.

### Semantic error (example)
If you accidentally write:

```c
int index = compute_index(turbidity, temperature);   // arguments swapped
```

the program still compiles, but the semantics are wrong: the first parameter
is treated as temperature and the second as turbidity, so the calculation is
performed on the wrong values (for instance, the deviation is taken from the
turbidity reading instead of the temperature). This is a **semantic error**
because the program is syntactically valid but does not do what was intended.

---

## c. Compilation lifecycle

Transforming a C source file into an executable generally involves these main
stages:

### 1. Preprocessing
- **Input:** source files (e.g. `water_quality.c`) and headers (`.h`).
- **Output:** a single expanded translation unit (often `.i`).
- Macros are expanded, `#include`s are replaced with the contents of the
  included headers, and conditional compilation (`#ifdef`, `#if`, etc.) is
  resolved.

### 2. Compilation (to assembly / intermediary representation)
- **Input:** preprocessed translation unit.
- **Output:** assembly code (`.s`) or an equivalent intermediate
  representation.
- The preprocessor output is parsed, semantically checked, and translated into
  target-specific assembly or IR. Type checking and many semantic errors are
  caught here.

### 3. Assembly
- **Input:** assembly code (`.s`).
- **Output:** object file (`.o` / `.obj`), containing machine code and
  relocations, but not yet a complete executable.
- The assembler converts assembly mnemonics into binary machine instructions
  and builds the object file format (ELF, Mach-O, COFF, etc.).

### 4. Linking
- **Input:** one or more object files plus libraries (static `.a`/`.lib` or
  dynamic `.so`/`.dll`).
- **Output:** final executable (or library).
- The linker resolves external symbols, assigns final addresses, merges
  sections, and produces the executable that the loader can run.

In practice, a driver like `gcc` runs the preprocessor, compiler, assembler,
and linker in sequence (or invokes them as needed), so a single command such
as `gcc -o water_quality water_quality.c` can go from source to executable.
