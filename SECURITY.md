# Security Policy

## Overview

This repository contains educational C programming code from CSC-150 coursework. While this is primarily an academic portfolio, we take security seriously and welcome reports of potential security issues.

## Supported Versions

This repository represents completed coursework from Fall 2022. Security updates will be applied to:

| Version/Branch | Supported          |
| -------------- | ------------------ |
| main           | :white_check_mark: |
| Older commits  | :x:                |

## Security Considerations

### Educational Code Context

**Important:** This code was written for educational purposes and may not follow all production security best practices. Known security-related considerations:

1. **Input Validation:** Some programs have minimal input validation
2. **Buffer Overflows:** Potential risks with `scanf()` and fixed-size buffers
3. **File Operations:** Limited error handling in some file I/O operations
4. **Integer Overflows:** Not all arithmetic operations are checked

### Use in Production

**Warning:** This code is NOT intended for production use. It is designed for learning fundamental programming concepts, not for deployment in security-critical environments.

## Reporting a Vulnerability

### When to Report

Report security issues if you discover:

- **Critical vulnerabilities** that could lead to code execution or data exposure
- **Memory safety issues** (buffer overflows, use-after-free, etc.)
- **Input validation flaws** that could lead to crashes or unexpected behavior
- **File handling issues** that could lead to unauthorized access

### What NOT to Report

You do not need to report:

- Missing input validation in obvious educational contexts
- Code style issues or non-security-related bugs (use regular Issues for these)
- Theoretical vulnerabilities in unrealistic usage scenarios
- Issues already documented in code comments

### How to Report

**For security vulnerabilities:**

1. **DO NOT** open a public GitHub issue
2. **Contact the repository owner directly:**
   - Via GitHub: Send a direct message to [@jakujobi](https://github.com/jakujobi)
   - Via email: Use the email address in the GitHub profile (if available)

3. **Include in your report:**
   - Description of the vulnerability
   - Affected file(s) and line number(s)
   - Steps to reproduce
   - Potential impact
   - Suggested fix (if you have one)

### Response Timeline

- **Acknowledgment:** Within 5 business days
- **Initial assessment:** Within 10 business days
- **Resolution:** Depends on severity and complexity

## Security Best Practices for Users

If you're using this code as a learning reference:

### Safe Compilation

```bash
# Compile with warnings to catch potential issues
gcc -Wall -Wextra -Werror source.c

# Enable stack protection (if supported)
gcc -fstack-protector-all source.c

# Enable address sanitizer for debugging
gcc -fsanitize=address -g source.c
```

### Safe Execution

1. **Don't run with elevated privileges**
   - Never use `sudo` or run as Administrator
   
2. **Use in isolated environments**
   - Test in virtual machines or containers if concerned

3. **Don't process untrusted input**
   - Use test data you create yourself
   - Don't feed external files without inspection

### Common Vulnerabilities to Learn From

This repository can help you learn about:

#### 1. Buffer Overflows with scanf()

**Example from code:**
```c
char name[10];
scanf("%s", name);  // Vulnerable: no length limit
```

**Safer alternative:**
```c
char name[10];
scanf("%9s", name);  // Limit to 9 chars + null terminator
```

#### 2. Format String Vulnerabilities

**Vulnerable:**
```c
printf(user_input);  // Never do this!
```

**Safe:**
```c
printf("%s", user_input);
```

#### 3. Integer Overflow

**Example:**
```c
int total = large_value1 + large_value2;  // Can overflow
```

**Better:**
```c
if (large_value1 > INT_MAX - large_value2) {
    // Handle overflow
}
```

#### 4. File Path Injection

**Vulnerable:**
```c
FILE *fp = fopen(user_provided_filename, "r");  // Can access any file
```

**Better:**
```c
// Validate filename, check permissions, use whitelist
```

## Known Security Issues

### Intentionally Unfixed Issues

Some security issues are left as-is for educational purposes:

1. **P6 Tornado Area - File Path Hardcoding**
   - **Issue:** Uses hardcoded filename `tornado.txt`
   - **Risk:** Low - educational context
   - **Learning:** Shows basic file I/O

2. **P7 Snowblower Sales - Fixed Array Size**
   - **Issue:** Fixed-size arrays without bounds checking
   - **Risk:** Low - controlled input
   - **Learning:** Demonstrates array basics

3. **Various Programs - scanf() Without Length Limits**
   - **Issue:** No width specifiers on string inputs
   - **Risk:** Medium - buffer overflow potential
   - **Learning:** Common beginner pattern; shows why validation matters

### Fixed Security Issues

None currently documented. When security fixes are applied, they will be listed here with:
- Date of fix
- CVE ID (if applicable)
- Description of vulnerability
- Commit hash of fix

## Security Enhancements

If you want to contribute security improvements:

1. **Maintain educational clarity**
   - Don't obscure the learning objective
   - Add comments explaining the security consideration

2. **Focus on high-impact issues**
   - Prioritize memory safety
   - Address input validation where critical

3. **Document the fix**
   - Explain why it was needed
   - Show the vulnerable pattern for learning

**Example security enhancement PR:**
```c
// Original (vulnerable):
char buffer[100];
scanf("%s", buffer);

// Enhanced (with educational comments):
char buffer[100];
// Use width specifier to prevent buffer overflow
// %99s reads up to 99 characters, leaving room for null terminator
scanf("%99s", buffer);
```

## Responsible Disclosure

If you discover a security vulnerability:

1. **Report privately** to repository owner
2. **Allow time for fix** (typically 90 days)
3. **Coordinate disclosure** before going public
4. **Credit will be given** in fix acknowledgment

## Additional Resources

### Learning Resources

- [OWASP C/C++ Security](https://owasp.org/www-project-secure-coding-practices-quick-reference-guide/)
- [CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard)
- [CWE Top 25](https://cwe.mitre.org/top25/)

### Tools for Security Analysis

```bash
# Static analysis
cppcheck source.c

# Address sanitizer
gcc -fsanitize=address source.c

# Valgrind (memory leak detection)
valgrind ./program
```

## Disclaimer

This code is provided "as-is" for educational purposes. While we address reported security issues, we make no guarantees about the security or safety of this code. Users assume all risks associated with using, modifying, or deploying this code.

---

**Last Updated:** 2026-02-05  
**Repository:** [jakujobi/CSC-150-with-C](https://github.com/jakujobi/CSC-150-with-C)
