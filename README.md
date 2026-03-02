# 🎓 CGPA Calculator

> **CodeAlpha Internship Task** — A beautiful console-based Cumulative Grade Point Average (CGPA) Calculator built in C++

[![Language](https://img.shields.io/badge/Language-C++-blue?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![CodeAlpha](https://img.shields.io/badge/Internship-CodeAlpha-orange)](https://www.codealpha.tech/)

---

## 📋 About

This project is developed as part of the **CodeAlpha C++ Programming Internship**. It is a clean, colorful, and user-friendly console application that helps students calculate their **semester GPA** and **cumulative CGPA** across multiple semesters.

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🎨 **Colorful Output** | ANSI color-coded console for a visually appealing experience |
| 📚 **Multi-Semester Support** | Add up to 12 semesters with up to 15 courses each |
| ✅ **Input Validation** | Rejects invalid grades and credit hours with clear error messages |
| 📊 **Progress Bars** | Visual ASCII progress bars for GPA representation |
| 📝 **Report Cards** | Detailed per-semester report card with formatted tables |
| 🏆 **Academic Standing** | Automatic classification (Dean's List, Honor Roll, etc.) |
| 📈 **GPA Trend** | Semester-wise GPA comparison chart for multi-semester entries |
| 🔢 **Quality Points** | Displays individual course quality points and totals |

---

## 📖 Grade Scale

| Letter Grade | Grade Points |
|:---:|:---:|
| A+ / A | 4.0 |
| A- | 3.7 |
| B+ | 3.3 |
| B | 3.0 |
| B- | 2.7 |
| C+ | 2.3 |
| C | 2.0 |
| C- | 1.7 |
| D+ | 1.3 |
| D | 1.0 |
| F | 0.0 |

---

## 🚀 How to Run

### Prerequisites
- A C++ compiler (g++, clang++, or MSVC)

### Steps

| Step | Platform | Command |
|:----:|----------|--------|
| 1 | **Linux / Mac** | `g++ CGPACalculator.cpp -o CGPACalculator` |
| 2 | **Linux / Mac** | `./CGPACalculator` |
| 1 | **Windows** | `g++ CGPACalculator.cpp -o CGPACalculator.exe` |
| 2 | **Windows** | `CGPACalculator.exe` |

> **Note:** For best color support on Windows, use **Windows Terminal** or **VS Code integrated terminal**.

---

## 🧪 Test Cases

### Test Case 1 — Single Semester, All A's

| Course | Grade | Credit Hours | Grade Points | Quality Points |
|--------|:-----:|:------------:|:------------:|:--------------:|
| Data Structures | A | 3 | 4.0 | 12.0 |
| Calculus II | A | 3 | 4.0 | 12.0 |
| English | A | 2 | 4.0 | 8.0 |

| Metric | Value |
|--------|:-----:|
| Total Credits | 8 |
| Total Quality Points | 32.0 |
| **Semester GPA** | **4.00** |
| **CGPA** | **4.00** |
| Academic Standing | 🌟 Dean's List |

---

### Test Case 2 — Single Semester, Mixed Grades

| Course | Grade | Credit Hours | Grade Points | Quality Points |
|--------|:-----:|:------------:|:------------:|:--------------:|
| Programming | A | 3 | 4.0 | 12.0 |
| Physics | B+ | 3 | 3.3 | 9.9 |
| History | C | 2 | 2.0 | 4.0 |

| Metric | Value |
|--------|:-----:|
| Total Credits | 8 |
| Total Quality Points | 25.9 |
| **Semester GPA** | **3.24** |
| **CGPA** | **3.24** |
| Academic Standing | ✅ Good Standing |

---

### Test Case 3 — Two Semesters (Cumulative CGPA)

**Semester 1:**

| Course | Grade | Credit Hours | Grade Points | Quality Points |
|--------|:-----:|:------------:|:------------:|:--------------:|
| OOP | A | 3 | 4.0 | 12.0 |
| Discrete Math | B | 3 | 3.0 | 9.0 |

> Semester 1 GPA = 21.0 / 6 = **3.50**

**Semester 2:**

| Course | Grade | Credit Hours | Grade Points | Quality Points |
|--------|:-----:|:------------:|:------------:|:--------------:|
| Databases | A- | 3 | 3.7 | 11.1 |
| OS | B+ | 3 | 3.3 | 9.9 |

> Semester 2 GPA = 21.0 / 6 = **3.50**

| Metric | Value |
|--------|:-----:|
| Grand Total Credits | 12 |
| Grand Total Quality Points | 42.0 |
| **CGPA** | **3.50** |
| Academic Standing | ⭐ Honor Roll |

---

### Test Case 4 — Edge Case: Single Course with F

| Course | Grade | Credit Hours | Grade Points | Quality Points |
|--------|:-----:|:------------:|:------------:|:--------------:|
| Calculus | F | 3 | 0.0 | 0.0 |

| Metric | Value |
|--------|:-----:|
| Total Credits | 3 |
| Total Quality Points | 0.0 |
| **CGPA** | **0.00** |
| Academic Standing | ⚠️ Academic Probation |

---

### Test Case 5 — Input Validation

| Scenario | Input | Expected Behavior |
|----------|-------|-------------------|
| Invalid grade | `X` | Shows error, re-prompts for valid grade |
| Invalid credit hours | `0` or `7` | Shows error, re-prompts (valid: 1–6) |
| Invalid semester count | `0` or `13` | Shows error, re-prompts (valid: 1–12) |
| Lowercase grade | `a+` | Accepted, auto-converted to `A+` |

---

## 🧮 How CGPA is Calculated

| Formula | Expression |
|---------|------------|
| **Quality Points** | Grade Points × Credit Hours |
| **Semester GPA** | Total Quality Points ÷ Total Credit Hours |
| **CGPA** | Grand Total Quality Points ÷ Grand Total Credit Hours |

**Example:**
| Course | Grade | Cr. Hr | Grade Pts | Quality Pts |
|--------|:-----:|:------:|:---------:|:-----------:|
| Data Structures | A | 3 | 4.0 | 12.0 |
| Calculus II | B+ | 3 | 3.3 | 9.9 |
| **Total** | | **6** | | **21.9** |

> **GPA = 21.9 / 6 = 3.65**

---

## 🏅 Academic Standing

| CGPA Range | Standing |
|:---:|---|
| ≥ 3.70 | 🌟 Dean's List (Outstanding!) |
| ≥ 3.50 | ⭐ Honor Roll (Excellent!) |
| ≥ 3.00 | ✅ Good Standing |
| ≥ 2.00 | 📝 Satisfactory |
| < 2.00 | ⚠️ Academic Probation |

---

## 🛠️ Built With

- **Language:** C++
- **Libraries:** `<iostream>`, `<string>`, `<iomanip>` (standard library only)
- **Styling:** ANSI Escape Codes for terminal colors

---

## 👨‍💻 Author

**Rehan Ilyas**

- GitHub: [@RehanIlyas-dev](https://github.com/RehanIlyas-dev)

---

## 🏢 Acknowledgements

This project was developed as a task during the **[CodeAlpha](https://www.codealpha.tech/)** C++ Programming Internship (March 2026). Special thanks to the CodeAlpha team for providing the opportunity to build practical, real-world projects.

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).