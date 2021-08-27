# 6502 Emulator
Some time ago, I decided to create a CPU emulator in order to better
understand how these work.

This emulator is built as a **C library**.

## Using the library
1. Include the emulator header
```C
#include "6502_emulator.h"
```

2. Initialize the library
```C
cpu_library_init();
```

3. Create and set the CPU's IO functions
```C
cpu_read_byte = read_byte;
cpu_write_byte = write_byte;
```

4. Reset the CPU
```C
cpu_reset();
```

5. Make the CPU run
```C
while(1) {
    cpu_clock();
}
```

## Resources
- [This website](http://www.obelisk.me.uk/6502/) contains information about
architecture, registers, instructions and addressing modes.
- I also used some of the information present in
[this book](http://archive.6502.org/books/mcs6500_family_hardware_manual.pdf)
to make sure that the emulator behaves correctly.
