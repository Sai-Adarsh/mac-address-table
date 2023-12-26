# Mac Address Table

This C++ library provides a basic implementation of a MAC address table. It includes a `Switch` class, a `MacTableValue` structure, and a `MacAddressTable` structure. The library also includes a `send` function for updating the address table based on communication between switches.

## Files

- **SwitchLibrary.h**: Header file containing class and structure declarations.
- **SwitchLibrary.cc**: Source file containing the implementations of the declared classes and structures.
- **main.cc**: Example usage of the library, demonstrating the creation of switches and communication between them.

## Compilation

Compile and link the example program using the following command:

```bash
g++ --std=c++11 -o main main.cc SwitchLibrary.cc
```
