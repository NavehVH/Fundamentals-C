# Fundamentals-C
Personal CS fundamentals handbook — algorithms, data structures, and problem-solving patterns for SWE interviews.

## Build & Run

This can be built in **both C and C++** modes.  
We use a single Makefile that produces two separate executables so they don’t overwrite each other.

## Targets

- `make` → builds **both** versions (`program_c` and `program_cpp`)
- `make program_c` → builds the **C version** only
- `make program_cpp` → builds the **C++ version** only
- `make clean` → removes all object files and executables

## Running

```bash
./program_c     # run the C version
./program_cpp   # run the C++ version
