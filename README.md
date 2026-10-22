# Simple C Celsius-to-Fahrenheit & Vice-Versa Converter

A clean, modular C program that performs bidirectional temperature conversion between Celsius and Fahrenheit. Designed for collegiate programming coursework, strictly adhering to structured decomposition standards where `main()` delegates entirely to specialized function routines.

---

## ?? Architectural Overview

In accordance with textbook design specifications (Figure 4-40), the program decomposes temperature conversion into autonomous, single-responsibility functions:
- `celsiusToFahrenheit(void)`: Prompts for a Celsius value, performs conversion, and displays the result formatted to two decimal places.
- `fahrenheitToCelsius(void)`: Prompts for a Fahrenheit value, performs conversion, and displays the result formatted to two decimal places.
- `main(void)`: Serves strictly as the coordinator, containing zero computational logic and delegating 100% of execution to function calls.

```text
       [ main(void) ]
             |
   +---------+---------+
   |                   |
   v                   v
[ celsiusToFahrenheit ]   [ fahrenheitToCelsius ]
  - Prompt/Read             - Prompt/Read
  - Compute F = 32 + C*1.8  - Compute C = (F - 32)/1.8
  - Display (%.2f)          - Display (%.2f)
```

---

## ?? Mathematical Formulation

Floating-point precision is strictly preserved by using `double` and explicit real division (`180.0 / 100.0` or `1.8`) to prevent integer truncation traps (`180 / 100 == 1`).

### 1. Celsius to Fahrenheit
$$F = 32.0 + \left( C \times \frac{180.0}{100.0} \right)$$

### 2. Fahrenheit to Celsius (Algebraic Inversion)
$$C = (F - 32.0) \times \frac{100.0}{180.0}$$

---

## ?? Empirical Verification & Test Matrix

The implementation was compiled with `gcc -Wall -Wextra -Werror` and verified against standard thermodynamic milestones, including the mandatory negative convergence test case:

| Test Case | Input Scale | Input Value | Target Formula | Expected Output | Status |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Water Freezing Point** | Celsius | $0.00^\circ\text{C}$ | $32.0 + (0.0 \times 1.8)$ | `32.00 F` | **PASS** |
| **Water Boiling Point** | Celsius | $100.00^\circ\text{C}$ | $32.0 + (100.0 \times 1.8)$ | `212.00 F` | **PASS** |
| **Negative Convergence** | Celsius | $-40.00^\circ\text{C}$ | $32.0 + (-40.0 \times 1.8)$ | `-40.00 F` | **PASS** |
| **Body Temperature** | Fahrenheit | $98.60^\circ\text{F}$ | $(98.6 - 32.0) / 1.8$ | `37.00 C` | **PASS** |
| **Absolute Zero Check** | Celsius | $-273.15^\circ\text{C}$ | $32.0 + (-273.15 \times 1.8)$ | `-459.67 F` | **PASS** |

---

## ?? Compilation and Execution

### Using GCC (MinGW / Linux / macOS):
```bash
gcc -Wall -Wextra -Werror Simple-c-celsius-to-fahrenheit-and-vice-versa.c -o converter
./converter
```

### Sample Interactive Output:
```text
Enter celsius temperature to be converted: 100
Fahrenheit: 212.00

Enter fahrenheit temperature to be converted: 98.6
Celsius: 37.00
```

---

## ??? Static Safety Audit
Scanned using static analysis security scanner:
- Unsafe unbounded calls (`gets`, bare `scanf("%s")`): **0 findings**
- Shell injection / pipe traps: **0 findings**
- Input validation: Yoda-style return checks enforced.
