# Development Guide

This guide provides detailed instructions for setting up the development environment, building programs, and understanding the project structure.

## Table of Contents

- [Development Environment Setup](#development-environment-setup)
- [Building and Running Programs](#building-and-running-programs)
- [Project Structure](#project-structure)
- [Coding Standards](#coding-standards)
- [Common Issues and Solutions](#common-issues-and-solutions)
- [IDE Configuration](#ide-configuration)

## Development Environment Setup

### Prerequisites

- **C Compiler:** GCC or compatible compiler
- **Text Editor/IDE:** Visual Studio Code (recommended), or any C-compatible editor
- **Operating System:** Windows 10/11, Linux, or macOS

### Windows Setup

#### Option 1: MSYS2 (Recommended)

1. **Download and install MSYS2:**
   - Visit https://www.msys2.org/
   - Download the installer
   - Run the installer and follow prompts

2. **Install MinGW-w64 toolchain:**
   ```bash
   # Open MSYS2 terminal
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc
   ```

3. **Add to PATH:**
   - Add `C:\msys64\mingw64\bin` to your system PATH
   - Verify: `gcc --version` in Command Prompt

4. **Install Visual Studio Code:**
   - Download from https://code.visualstudio.com/
   - Install C/C++ extension by Microsoft

#### Option 2: MinGW-w64 Direct Install

1. Download MinGW-w64 from https://winlibs.com/
2. Extract to `C:\mingw64`
3. Add `C:\mingw64\bin` to PATH
4. Verify installation: `gcc --version`

### Linux Setup

#### Ubuntu/Debian

```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install gcc
```

#### Fedora/RHEL

```bash
sudo dnf install gcc
sudo dnf install make
```

#### Arch Linux

```bash
sudo pacman -S base-devel
sudo pacman -S gcc
```

### macOS Setup

```bash
# Install Xcode Command Line Tools
xcode-select --install

# Or install via Homebrew
brew install gcc
```

### Verify Installation

```bash
gcc --version
# Expected output: gcc (GCC) X.X.X or similar
```

## Building and Running Programs

### Command Line Compilation

#### Basic Program (no external libraries)

```bash
# Syntax
gcc -o output_name source_file.c

# Example: Compile Rectangle Area program
gcc -o rectangle "Chapter Exercises/Chapter 2 Exercises/9a Area of Rectangle/Rectangle_Area - John Akujobi CSC150.c"

# Run
./rectangle           # Linux/macOS
rectangle.exe         # Windows
```

#### Program with Math Library

```bash
# Compile with -lm flag (link math library)
gcc -o hobo_mug "P3-150 - Hobo Day Mug/Program 3 code/Hobo_Day_Mug_Calculation_John_Akujobi.c" -lm

# Run
./hobo_mug
```

#### Program with Multiple Source Files

```bash
# If program has multiple .c files
gcc -o program file1.c file2.c file3.c -lm
```

#### With Debug Symbols

```bash
# Add -g flag for debugging
gcc -g -o program source.c
gdb ./program
```

#### With Warnings Enabled

```bash
# Good practice: enable all warnings
gcc -Wall -Wextra -o program source.c
```

### Compilation Examples

```bash
# Water Tank Calculator
gcc -o watertank "P2-150 - Fill time for cylindrical Water Tank/Watertank_fill_time_calculator - John Akujobi.c"

# Dice Game
gcc -o dicegame "P4-150 - Diceroll Game/Program code/Diceroll Game - John Akujobi.c"

# Patterns Program
gcc -o patterns "P5-150 - Patterns Menu program/Patterns_JCA.c"

# Tornado Analysis (with file I/O)
gcc -o tornado "P6-150 - Tornado Area/Program 6 code tornado data/Program 6 code to process tornado data.c"

# Snowblower Sales
gcc -o sales "P7-150 - Snowblower sales/thrower_JCA.c"
```

### Running Programs with Input Files

Some programs require input files to be in the same directory as the executable:

```bash
# P6: Tornado Area (requires tornado.txt)
cd "P6-150 - Tornado Area"
gcc -o tornado "Program 6 code tornado data/Program 6 code to process tornado data.c"
./tornado
# Creates report.txt in the same directory

# P7: Snowblower Sales (requires throwers.txt)
cd "P7-150 - Snowblower sales"
gcc -o sales thrower_JCA.c
./sales
```

## Project Structure

### Directory Naming Conventions

- **Programs:** `P[N]-150 - [Description]` (e.g., `P2-150 - Fill time for cylindrical Water Tank`)
- **Exercises:** `Chapter [N] Exercises` or `Chapter [N] Problems`
- **Practice:** `Practice and small scripts`

### File Naming Conventions

- **Source Files:** Descriptive names with author initials
  - `Program_Name - John Akujobi CSC150.c`
  - `Program_Name_JCA.c`
- **Executables:** `.exe` extension on Windows
- **Data Files:** `.txt` extension (e.g., `tornado.txt`, `throwers.txt`)
- **Documentation:** `.doc`, `.docx`, `.png` (flowcharts), `.xmind` (mind maps)

### Standard Program Structure

```
Program-N/
├── Requirements & Design/
│   ├── CSC150ProgramNDirections.doc    # Assignment specifications
│   ├── Flowchart.png                   # Program flow diagram
│   ├── Structure_Chart.png             # Module hierarchy
│   └── Design_Document.docx            # Detailed design
├── Program N code/                     # Primary implementation
│   ├── source.c
│   ├── source.exe (not in git)
│   └── data_file.txt
└── Version 1/                          # Earlier iterations
    └── source_V1.c
```

## Coding Standards

### Code Style

Based on the repository's existing code:

**Indentation:**
- Use 4 spaces or tabs consistently
- Align braces with block start

**Comments:**
```c
// Single-line comments for brief explanations

/*
 * Multi-line comments for:
 * - File headers (author, date, description)
 * - Function descriptions
 * - Complex algorithm explanations
 */
```

**Function Prototypes:**
```c
// At top of file, before main()
void WelcomeMessage(void);
int CalculateValue(int param1, float param2);
```

**Variable Declarations:**
```c
// Group related variables
float tank_height, tank_diameter, tank_radius;
int total_sales, monthly_average;

// Or separate for clarity
float tank_height;
float tank_diameter;
float tank_radius;
```

### Naming Conventions

**Variables:**
- Descriptive, lowercase with underscores: `tank_fill_time`, `user_choice`
- Avoid single-letter names except for loop counters (`i`, `j`, `k`)

**Functions:**
- PascalCase or snake_case: `CalculateArea()` or `calculate_area()`
- Verb-based names: `GetInput()`, `PrintResults()`, `ValidateChoice()`

**Constants:**
- `#define` in ALL_CAPS: `#define MAX_SIZE 100`
- `const` in PascalCase: `const float PI = 3.14159;`

### File Header Template

```c
/*
 * Program: [Program Name]
 * Description: [Brief description of what the program does]
 * 
 * Created by: John Akujobi
 * Date: [MM/DD/YYYY]
 * Course: CSC 150 - S01
 */
```

### Function Documentation

```c
/*
 * Function: CalculateVolume
 * Description: Calculates the volume of a hemisphere given the radius
 * Parameters: 
 *   - radius: The radius of the hemisphere in inches
 * Returns: Volume in cubic inches
 */
float CalculateVolume(float radius) {
    // Implementation
}
```

## Common Issues and Solutions

### Issue: `undefined reference to 'pow'`

**Cause:** Math library not linked  
**Solution:** Add `-lm` flag to compilation:
```bash
gcc -o program source.c -lm
```

### Issue: `cannot open source file "xyz.c"`

**Cause:** File path with spaces not quoted  
**Solution:** Quote the path:
```bash
gcc -o output "path/with spaces/source.c"
```

### Issue: Program doesn't find `tornado.txt` or `throwers.txt`

**Cause:** Input file not in same directory as executable  
**Solution:** 
1. Run program from the directory containing the data file, OR
2. Copy data file to executable's directory, OR
3. Modify code to use absolute path (not recommended)

### Issue: Random numbers are always the same

**Cause:** Not seeding the random number generator  
**Solution:** Add at start of `main()`:
```c
#include <time.h>
srand(time(NULL));
```

### Issue: Input prompt not showing

**Cause:** Output buffer not flushed  
**Solution:** Add `fflush(stdout);` after `printf()`:
```c
printf("Enter value: ");
fflush(stdout);
scanf("%d", &value);
```

### Issue: `scanf()` skipping input

**Cause:** Leftover newline in input buffer  
**Solution:** Clear buffer or use alternative:
```c
// Option 1: Clear buffer
int c;
while ((c = getchar()) != '\n' && c != EOF);

// Option 2: Use format string with space
scanf(" %c", &char_variable);  // Space before %c
```

## IDE Configuration

### Visual Studio Code Setup

#### Required Extensions

1. **C/C++** (Microsoft) - IntelliSense, debugging, code browsing
2. **Code Runner** (Optional) - Quick code execution

#### Workspace Configuration

The repository includes `.vscode/` configuration:

**tasks.json** - Build tasks
- Press `Ctrl+Shift+B` to build active file
- Uses GCC with `-g` flag for debugging

**launch.json** - Debug configuration
- Press `F5` to build and debug
- Uses GDB debugger
- Configured for Windows paths (modify for Linux/macOS)

#### Adapting for Linux/macOS

Edit `.vscode/tasks.json`:
```json
{
    "command": "/usr/bin/gcc",  // Instead of C:\\msys64\\...
    "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"  // Remove .exe
    ]
}
```

Edit `.vscode/launch.json`:
```json
{
    "program": "${fileDirname}/${fileBasenameNoExtension}",  // Remove .exe
    "miDebuggerPath": "/usr/bin/gdb"  // Instead of C:\\msys64\\...
}
```

### Using the Debugger

1. **Set Breakpoints:** Click left margin next to line numbers
2. **Start Debugging:** Press `F5`
3. **Debug Controls:**
   - `F5` - Continue
   - `F10` - Step Over
   - `F11` - Step Into
   - `Shift+F11` - Step Out
   - `Shift+F5` - Stop

4. **View Variables:** Hover over variables or check "Variables" panel

### Terminal Commands in VSCode

```bash
# Open integrated terminal: Ctrl + `

# Navigate to program directory
cd "P2-150 - Fill time for cylindrical Water Tank"

# Compile
gcc -o watertank "Watertank_fill_time_calculator - John Akujobi.c"

# Run
./watertank
```

## Working with Chapter Exercises

```bash
# Example: Chapter 2 Exercise 9a
cd "Chapter Exercises/Chapter 2 Exercises/9a Area of Rectangle"
gcc -o rectangle "Rectangle_Area - John Akujobi CSC150.c"
./rectangle

# Example: Chapter 4 Exercise 3
cd "Chapter Exercises/Chapter 4 Exercises/Q3 Educational Level"
gcc -o edu "Q3 Educational Level - John Akujobi CSC150.c"
./edu

# Example: Chapter 7 Exercise 10
cd "Chapter Exercises/Chapter 7 Exercises/Q 10 Bubble and selection sort"
gcc -o sort "Q 10 Bubble and selection sort.c"
./sort
```

## Quick Reference

### Compile and Run Workflow

```bash
# 1. Navigate to program directory
cd "P5-150 - Patterns Menu program"

# 2. Compile
gcc -o patterns Patterns_JCA.c

# 3. Run
./patterns

# 4. Clean up (optional)
rm patterns  # Linux/macOS
del patterns.exe  # Windows
```

### Essential GCC Flags

| Flag | Purpose |
|------|---------|
| `-o <name>` | Specify output filename |
| `-g` | Include debug symbols |
| `-Wall` | Enable all warnings |
| `-Wextra` | Enable extra warnings |
| `-lm` | Link math library |
| `-std=c99` | Use C99 standard |
| `-O2` | Optimization level 2 |

### Useful Commands

```bash
# Check GCC version
gcc --version

# Compile with all warnings
gcc -Wall -Wextra -o program source.c

# Compile for debugging
gcc -g -Wall -o program source.c

# Run with GDB
gdb ./program

# Compile multiple files
gcc -o program main.c utils.c helpers.c
```

## Additional Resources

- **GCC Manual:** https://gcc.gnu.org/onlinedocs/
- **C Reference:** https://en.cppreference.com/w/c
- **GDB Tutorial:** https://www.gdbtutorial.com/
- **VSCode C/C++ Docs:** https://code.visualstudio.com/docs/languages/cpp

---

*For questions about specific programs, refer to the design documents in each program's `Requirements & Design` folder.*
