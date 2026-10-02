# Question 1: Technical Explanation

### a. Real-world application:
C programming is the go-to language for embedded systems (like the water-quality monitor) because it runs incredibly close to the hardware. It allows direct memory manipulation and has a very small runtime footprint. This makes it perfect for microcontrollers (like Arduino) which have very limited RAM and processing power compared to a desktop computer.

### b. Error analysis:
1. **Syntax Error Example:** Forgetting a semicolon at the end of a variable declaration (e.g., loat temperature = 28.5). The compiler will literally stop and throw an error because it violates the grammar rules of C.
2. **Semantic Error Example:** Using + instead of - in the Water Quality formula: int index = 100 + (int)(temp_dev + turbidity_penalty);. The code will compile perfectly fine because the syntax is correct, but the logic is flawed, meaning the device will output incorrect quality ratings.

### c. Compilation lifecycle:
1. **Preprocessing:** Removes comments, expands macros (#define), and includes header files (#include <stdio.h>). 
   - Input: Source code (.c file)
   - Output: Expanded source code (.i file)
2. **Compilation:** Translates the preprocessed C code into assembly language specific to the target architecture.
   - Input: Expanded source code (.i file)
   - Output: Assembly code (.s file)
3. **Assembly:** Converts the assembly instructions into machine-level binary code.
   - Input: Assembly code (.s file)
   - Output: Object file (.o file)
4. **Linking:** Combines one or more object files with standard library files (like printf from stdio) into the final program.
   - Input: Object files (.o files) and C libraries
   - Output: Executable file (.exe on Windows or .out on Linux)