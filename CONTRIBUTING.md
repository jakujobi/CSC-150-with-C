# Contributing to CSC-150 with C

Thank you for your interest in this repository! This is an academic coursework repository documenting C programming assignments from CSC-150 (Computer Science I) at South Dakota State University.

## Repository Purpose

This repository serves as:
- **Portfolio** of completed coursework
- **Learning resource** for C programming concepts
- **Reference implementation** for common CS1 assignments

## Contribution Guidelines

### What Contributions Are Welcome

We welcome the following types of contributions:

1. **Documentation improvements**
   - Fixing typos or unclear explanations
   - Adding clarifying comments to code
   - Improving README or guides
   - Adding usage examples

2. **Bug fixes**
   - Fixing compilation errors
   - Correcting logic errors in existing code
   - Improving error handling

3. **Code enhancements** (with caution)
   - Improving code style consistency
   - Adding input validation
   - Optimizing algorithms (while maintaining educational clarity)

4. **Build system improvements**
   - Adding Makefiles
   - Improving cross-platform compatibility
   - Enhancing VSCode configuration

### What Contributions Are NOT Accepted

- Complete rewrites that obscure the original learning progression
- Changes that would contradict the original assignment requirements
- Adding external dependencies or libraries beyond standard C
- Solutions to assignments that are still in active use in courses

## How to Contribute

### Reporting Issues

1. Check if the issue already exists in the [Issues](https://github.com/jakujobi/CSC-150-with-C/issues) tab
2. Create a new issue with:
   - **Title:** Clear, descriptive summary
   - **Description:** Detailed explanation
   - **Steps to reproduce** (for bugs)
   - **Expected vs actual behavior**
   - **Environment:** OS, compiler version, etc.

### Submitting Changes

1. **Fork the repository**
   ```bash
   # Click "Fork" on GitHub, then clone your fork
   git clone https://github.com/YOUR_USERNAME/CSC-150-with-C.git
   cd CSC-150-with-C
   ```

2. **Create a feature branch**
   ```bash
   git checkout -b feature/your-feature-name
   # or
   git checkout -b fix/bug-description
   ```

3. **Make your changes**
   - Follow the existing code style (see [Coding Standards](#coding-standards))
   - Test your changes thoroughly
   - Update documentation if needed

4. **Commit your changes**
   ```bash
   git add .
   git commit -m "Brief description of changes"
   ```
   
   **Commit message format:**
   - Use present tense: "Add feature" not "Added feature"
   - Be descriptive but concise
   - Reference issues if applicable: "Fix #123: Description"

5. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Create a Pull Request**
   - Go to the original repository on GitHub
   - Click "New Pull Request"
   - Select your fork and branch
   - Provide a clear description of changes
   - Reference related issues

### Pull Request Guidelines

**Title:** Clear summary of what the PR does  
**Description:** Should include:
- What changes were made and why
- Which issue(s) it addresses (if any)
- How to test the changes
- Any potential side effects

**Example:**
```
Fix compilation error in P3 Hobo Mug program

- Added missing semicolon in line 45
- Corrected function parameter type mismatch
- Verified compilation with gcc 13.3.0

Fixes #42
```

## Coding Standards

### Style Guidelines

Follow the existing code style in the repository:

**Indentation:**
- Use 4 spaces (or tabs if that's what the file uses)
- Be consistent within a file

**Naming Conventions:**
- Variables: `snake_case` (e.g., `tank_height`, `user_choice`)
- Functions: `PascalCase` or `snake_case` (e.g., `CalculateArea()`, `get_input()`)
- Constants: `UPPER_CASE` for `#define`, `PascalCase` for `const`

**Comments:**
```c
// Single-line comments for brief explanations

/*
 * Multi-line comments for:
 * - Function documentation
 * - Complex algorithms
 * - File headers
 */
```

**File Headers:**
```c
/*
 * Program: [Name]
 * Description: [Brief description]
 * 
 * Created by: John Akujobi
 * Modified by: [Your Name]  // Add this if making significant changes
 * Date: [MM/DD/YYYY]
 * Course: CSC 150 - S01
 */
```

### Code Quality

- **Compile without warnings:** `gcc -Wall -Wextra source.c`
- **Test your changes:** Verify the program works as expected
- **Avoid breaking changes:** Don't modify behavior unless fixing a bug
- **Keep it simple:** This is educational code; clarity > cleverness

### Testing

Before submitting a PR:

1. **Compilation test:**
   ```bash
   gcc -Wall -Wextra -o program source.c -lm
   ```

2. **Runtime test:**
   - Test with expected inputs
   - Test edge cases
   - Verify output matches requirements

3. **Cross-platform test** (if possible):
   - Test on Windows, Linux, or macOS
   - Note any platform-specific issues

## Development Environment

See [docs/DEVELOPMENT.md](docs/DEVELOPMENT.md) for detailed setup instructions.

**Quick setup:**
1. Install GCC (MinGW-w64 on Windows)
2. Clone the repository
3. Navigate to a program directory
4. Compile and run: `gcc -o program source.c && ./program`

## Review Process

1. **Automated checks:** None currently (future: CI/CD)
2. **Manual review:** Repository maintainer will review your PR
3. **Feedback:** You may be asked to make changes
4. **Merge:** Once approved, your PR will be merged

**Expected timeline:** Usually within 1-2 weeks

## Code of Conduct

### Our Standards

- **Be respectful:** Treat all contributors with respect
- **Be constructive:** Provide helpful feedback
- **Be patient:** Everyone is learning
- **Be honest:** Don't plagiarize or claim others' work

### Academic Integrity

**Important:** This repository contains completed coursework. If you are a student:

- **DO NOT** copy code for your own assignments
- **DO** use it as a reference to understand concepts
- **DO** follow your institution's academic honesty policy
- **CITE** this repository if you reference it in your work

Misuse of this code for academic dishonesty is:
- Against your school's policies
- Harmful to your learning
- Detectable by plagiarism detection tools

## Questions?

- **General questions:** Open a [Discussion](https://github.com/jakujobi/CSC-150-with-C/discussions)
- **Bug reports:** Open an [Issue](https://github.com/jakujobi/CSC-150-with-C/issues)
- **Security issues:** Contact the repository owner directly (don't open public issues)

## License

By contributing, you agree that your contributions will be licensed under the GPL-3.0 license that covers this project.

See [LICENSE](LICENSE) for full license text.

---

Thank you for contributing to this educational resource! Your efforts help make learning C programming more accessible to everyone.
