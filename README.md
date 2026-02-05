# CSC-150 Computer Science I with C

A comprehensive collection of C programming assignments, exercises, and practice problems completed for CSC-150 (Computer Science I) at South Dakota State University. This repository demonstrates fundamental programming concepts, problem-solving skills, and software development practices.

## 📋 Overview

This repository contains coursework from CSC-150, showcasing progressive learning in C programming from basic I/O operations to advanced file handling, data structures, and algorithms. Each program includes design documentation, source code, and test data where applicable.

**Author:** John Akujobi  
**Course:** CSC-150 - Computer Science I  
**Institution:** South Dakota State University  
**Academic Period:** Fall 2022  
**License:** GPL-3.0

## ✨ Key Features

- **7 Major Programs** covering core CS concepts (P1-P7)
- **15+ Chapter Exercises** organized by topic (Chapters 1-7)
- **17+ Practice Scripts** for skill reinforcement
- **Complete Design Documentation** including flowcharts and structure charts
- **Real-world Applications** (hospital IV calculator, tornado data analysis, sales analytics)
- **Input/Output File Handling** with data processing
- **Interactive Console Applications** with menu-driven interfaces

## 🏗️ Repository Structure

```
CSC-150-with-C/
├── P1 C/                                    # Program 1: Basic programming concepts
├── P2-150 - Fill time for cylindrical Water Tank/  # Volume and time calculations
├── P3-150 - Hobo Day Mug/                   # Hemisphere volume calculations
├── P4-150 - Diceroll Game/                  # Random number generation & game logic
├── P5-150 - Patterns Menu program/          # Nested loops & pattern printing
├── P6-150 - Tornado Area/                   # File I/O & data processing
├── P7-150 - Snowblower sales/               # Arrays, sorting, and statistics
├── Chapter Exercises/                       # Organized by chapter (1-7)
├── Practice and small scripts/              # Practice programs & experiments
├── Precipitation Practice/                  # Weather data analysis
├── TOu Hospital Intraveinous Assistant/     # Medical IV rate calculator
└── .vscode/                                 # VSCode configuration files
```

See [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) for detailed module descriptions and learning progression.

## 🚀 Quick Start

### Prerequisites

- **GCC Compiler** (MinGW-w64 on Windows, GCC on Linux/macOS)
- **Text Editor or IDE** (VSCode recommended with C/C++ extension)
- **Make** (optional, for automated builds)

**Windows:**
```bash
# Install MSYS2 from https://www.msys2.org/
# Then install MinGW-w64:
pacman -S mingw-w64-x86_64-gcc
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get update
sudo apt-get install build-essential
```

**macOS:**
```bash
xcode-select --install
```

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/jakujobi/CSC-150-with-C.git
   cd CSC-150-with-C
   ```

2. **Verify GCC installation:**
   ```bash
   gcc --version
   ```

### Building and Running Programs

#### Basic Programs (without math library)

```bash
# Compile
gcc -o program_name "path/to/source.c"

# Example: Rectangle Area Calculator
gcc -o rectangle "Chapter Exercises/Chapter 2 Exercises/9a Area of Rectangle/Rectangle_Area - John Akujobi CSC150.c"

# Run
./rectangle
```

#### Programs with Math Library

```bash
# Compile with -lm flag
gcc -o hobo_mug "P3-150 - Hobo Day Mug/Program 3 code/Hobo_Day_Mug_Calculation_John_Akujobi.c" -lm

# Run
./hobo_mug
```

#### Using VSCode

1. Open the repository folder in VSCode
2. Install the C/C++ extension
3. Open any `.c` file
4. Press `F5` to build and debug (uses `.vscode/tasks.json` and `.vscode/launch.json`)

## 📚 Major Programs

### P1 - Basic C Programming
**Topics:** Basic I/O, variables, arithmetic operations  
**Location:** [`P1 C/`](P1%20C/)

### P2 - Cylindrical Water Tank Fill Time
**Topics:** Constants, mathematical calculations, type conversions  
**Description:** Calculates time to fill a cylindrical tank based on dimensions and flow rate  
**Location:** [`P2-150 - Fill time for cylindrical Water Tank/`](P2-150%20-%20Fill%20time%20for%20cylindrical%20Water%20Tank/)  
**Key Concepts:**
- Mathematical constants (PI)
- Volume calculations
- Unit conversions (cubic feet to gallons)
- Time formatting (hours and minutes)

### P3 - Hobo Day Mug Volume
**Topics:** Functions, modular programming, mathematical functions  
**Description:** Calculates the volume of a hemisphere-shaped mug in multiple units  
**Location:** [`P3-150 - Hobo Day Mug/`](P3-150%20-%20Hobo%20Day%20Mug/)  
**Key Concepts:**
- Function prototypes and definitions
- Math library usage (`pow()`)
- Multi-unit conversions (cubic inches, ounces, liters)

### P4 - Dice Roll Game
**Topics:** Random number generation, conditional logic, control structures  
**Description:** Two-player dice game with special rules (Snake Eyes, Lucky 7, Closest to 12)  
**Location:** [`P4-150 - Diceroll Game/`](P4-150%20-%20Diceroll%20Game/)  
**Key Concepts:**
- Random number generation with `rand()` and `srand()`
- Time-based seeding
- Complex conditional logic
- Game state management

### P5 - Patterns Menu Program
**Topics:** Nested loops, menu-driven interfaces, switch statements  
**Description:** Interactive program that prints various ASCII patterns based on user selection  
**Location:** [`P5-150 - Patterns Menu program/`](P5-150%20-%20Patterns%20Menu%20program/)  
**Key Concepts:**
- Nested loop structures
- Menu-driven design with `enum`
- Input validation
- Pattern generation algorithms

### P6 - Tornado Area Analysis
**Topics:** File I/O, data processing, formatted output  
**Description:** Reads tornado data from file, calculates affected areas, generates report  
**Location:** [`P6-150 - Tornado Area/`](P6-150%20-%20Tornado%20Area/)  
**Key Concepts:**
- File reading with `fopen()`, `fscanf()`, `fclose()`
- File writing for reports
- Data validation and error handling
- Modular function design
- Statistical calculations

### P7 - Snowblower Sales Analytics
**Topics:** Arrays, sorting algorithms, statistical analysis  
**Description:** Analyzes monthly snowblower sales data with statistics and visualizations  
**Location:** [`P7-150 - Snowblower sales/`](P7-150%20-%20Snowblower%20sales/)  
**Key Concepts:**
- Array manipulation
- Sorting algorithms (bubble sort, selection sort)
- Statistical measures (mean, median, mode)
- Histogram generation
- Finding min/max values

### TOu Hospital Intravenous Assistant
**Topics:** Menu systems, medical calculations, user input validation  
**Description:** Assists healthcare professionals with IV rate calculations  
**Location:** [`TOu Hospital Intraveinous Assistant/`](TOu%20Hospital%20Intraveinous%20Assistant/)  
**Key Concepts:**
- Multi-option menu interface
- Domain-specific calculations (medical)
- Precision in calculations
- User-friendly output formatting

## 📖 Chapter Exercises

Exercises are organized by chapter, covering:

- **[Chapter 1](Chapter%20Exercises/Chapter%201%20Exercises/):** Introduction to C programming
- **[Chapter 2](Chapter%20Exercises/Chapter%202%20Exercises/):** Basic I/O, variables, arithmetic (5 exercises)
- **[Chapter 3](Chapter%20Exercises/Chapter%203%20Problems/):** More on data types and expressions
- **[Chapter 4](Chapter%20Exercises/Chapter%204%20Exercises/):** Control structures, if-else, switch statements (6 exercises)
- **[Chapter 5](Chapter%20Exercises/Chapter%205%20Exercises/):** Loops and iteration (7 exercises)
- **[Chapter 6](Chapter%20Exercises/Chapter%206%20Exercises/):** Functions and modular design (1+ exercises)
- **[Chapter 7](Chapter%20Exercises/Chapter%207%20Exercises/):** Arrays and sorting algorithms (1+ exercises)

## 🛠️ Development Environment

### IDE Setup

The repository includes VSCode configuration for Windows development:

**Tasks** (`.vscode/tasks.json`):
- GCC build task for active file
- G++ build task (default)

**Debug Configuration** (`.vscode/launch.json`):
- Integrated GDB debugging
- Automatic pre-launch build
- Console I/O support

See [docs/DEVELOPMENT.md](docs/DEVELOPMENT.md) for detailed setup instructions.

### Compilation Flags

Most programs use standard compilation:
```bash
gcc -fdiagnostics-color=always -g source.c -o output.exe
```

For programs using `math.h`:
```bash
gcc -fdiagnostics-color=always -g source.c -o output.exe -lm
```

## 🎯 What This Project Demonstrates

This repository showcases key computer science competencies valuable to recruiters and employers:

### Programming Fundamentals
- **Strong C Language Proficiency:** 50+ programs demonstrating mastery of C syntax, memory management, and standard library  
  *Evidence:* All source files in repository
  
- **Problem Decomposition:** Breaking complex problems into manageable functions and modules  
  *Evidence:* [P6 Tornado Analysis](P6-150%20-%20Tornado%20Area/), [P7 Sales Analytics](P7-150%20-%20Snowblower%20sales/)

### Software Engineering Practices
- **Design Documentation:** Comprehensive flowcharts, structure charts, and design documents  
  *Evidence:* Design folders in P2-P7, e.g., [P5 Requirements & Design](P5-150%20-%20Patterns%20Menu%20program/Requirements%20%26%20Design/)
  
- **Version Control:** Multiple program versions showing iterative development  
  *Evidence:* Version folders in P4, P5, P6, P7
  
- **Code Organization:** Modular, maintainable code with clear naming conventions  
  *Evidence:* Function-based architecture in all major programs

### Algorithm Implementation
- **Sorting Algorithms:** Implementation of bubble sort and selection sort from scratch  
  *Evidence:* [P7 Snowblower Sales](P7-150%20-%20Snowblower%20sales/thrower_JCA.c), [Chapter 7 Exercises](Chapter%20Exercises/Chapter%207%20Exercises/)
  
- **Statistical Analysis:** Mean, median, mode calculations and histogram visualization  
  *Evidence:* [P7](P7-150%20-%20Snowblower%20sales/)

### Data Management
- **File I/O Operations:** Reading from and writing to text files with error handling  
  *Evidence:* [P6 Tornado Data](P6-150%20-%20Tornado%20Area/), [P7](P7-150%20-%20Snowblower%20sales/), [Precipitation Practice](Precipitation%20Practice/)
  
- **Data Structures:** Arrays, structs (implied through data grouping)  
  *Evidence:* Array usage in P7 and Chapter 7 exercises

### Problem-Solving Skills
- **Real-world Applications:** Medical calculations, weather analysis, business analytics  
  *Evidence:* [TOu Hospital Assistant](TOu%20Hospital%20Intraveinous%20Assistant/), [P6 Tornado](P6-150%20-%20Tornado%20Area/), [P7 Sales](P7-150%20-%20Snowblower%20sales/)
  
- **Debugging & Testing:** Bug documentation and fixes in code comments  
  *Evidence:* Bug tracking in [P4 Game](P4-150%20-%20Diceroll%20Game/), [P5 Patterns](P5-150%20-%20Patterns%20Menu%20program/Patterns_JCA.c), [P7 Sales](P7-150%20-%20Snowblower%20sales/thrower_JCA.c)

### User Interface Design
- **Interactive Console Applications:** Menu-driven interfaces with input validation  
  *Evidence:* [P5 Patterns](P5-150%20-%20Patterns%20Menu%20program/), [TOu Hospital](TOu%20Hospital%20Intraveinous%20Assistant/)

## 🧪 Testing

No automated test suite is present. Testing was performed manually during development:

1. **Unit Testing:** Individual functions tested with known inputs/outputs
2. **Integration Testing:** Full programs tested with sample data files
3. **Edge Case Testing:** Validation of boundary conditions and error handling

**Test Data Files:**
- `tornado.txt` - Sample tornado data for P6
- `throwers.txt` - Sample sales data for P7
- `Brookings_Rainfall_2020_2022.txt` - Weather data for precipitation practice

## 📊 Project Status

**Status:** ✅ **Complete** - Academic coursework finished Fall 2022

**What's Included:**
- ✅ All major programming assignments (P1-P7)
- ✅ Chapter exercises and solutions
- ✅ Design documentation and flowcharts
- ✅ Practice scripts and experiments
- ✅ Test data files

**Future Enhancements (Optional):**
- [ ] Add automated build system (Makefile)
- [ ] Create unit tests for core functions
- [ ] Add example output screenshots
- [ ] Cross-platform build verification
- [ ] Code style consistency improvements

## 📝 License

This project is licensed under the **GNU General Public License v3.0** (GPL-3.0).

See [LICENSE](LICENSE) file for full license text.

**Key Points:**
- Free to use, modify, and distribute
- Modified versions must also be open source under GPL-3.0
- No warranty provided

## 🙏 Acknowledgments

- **South Dakota State University** - CSC-150 Computer Science I course
- **Course Instructor** - For project specifications and guidance
- **MinGW-w64 Project** - GCC compiler for Windows
- **VSCode Team** - C/C++ extension and development tools

## 📧 Contact

**John Akujobi**  
GitHub: [@jakujobi](https://github.com/jakujobi)

---

*This repository represents academic work completed for CSC-150 in Fall 2022. All programs are original work unless otherwise noted in source comments.*
