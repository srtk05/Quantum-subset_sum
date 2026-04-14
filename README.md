# Quantum Subset Sum Project

## Overview

This project compares a classical Subset Sum solver with a simple quantum-inspired simulation using Qiskit.

The goal is to show how subsets can be represented with qubits and how quantum ideas can change the search process.

---

## Problem

Given a set of numbers and a target sum, find all subsets whose values add up to the target.

Example:
- Set: {5, 10, 12, 13, 15, 18}
- Target: 30
- Solutions: {5, 10, 15} and {12, 18}

---

## Project Files

- `README.md` — project overview
- `requirements.txt` — Python dependencies
- `classical/subset_sum.cpp` — classical backtracking solver
- `quantum/quantum_subset.py` — quantum simulator example
- `comparison/analysis.md` — comparison of classical and quantum ideas
- `docs/explanation.md` — technical notes
- `demo/sample_output.txt` — sample run outputs
- `.gitignore` — files to ignore for Git

---

## How This Works

### Classical version

`classical/subset_sum.cpp` uses backtracking.
Each number can be included or excluded, so the algorithm checks all subset combinations.
This is simple and works well for small sets.

### Quantum version

`quantum/quantum_subset.py` uses Qiskit to create a superposition of all possible subsets.
It then measures the qubits and checks which measured states match the target sum.

This is not a full quantum search algorithm, but it shows the main idea:
- one qubit per number
- superposition means many combinations can exist together
- measurement gives one result at a time

---

## How to Run

### Install dependencies

```bash
pip install -r requirements.txt
```

### Run classical solver

```bash
cd classical
g++ -o subset_sum subset_sum.cpp
./subset_sum
```

### Run quantum simulation

```bash
cd quantum
python quantum_subset.py
```

## 📖 Documentation

For detailed technical explanations, see:
- [Technical Explanation](docs/explanation.md)
- [Comparison Analysis](comparison/analysis.md)
- [Presentation Guide](docs/presentation.md)

---

## 👨‍💻 Author
        -Sarthak Ardhapure
B.Tech (2nd Year) | Quantum Computing Enthusiast  
QuEdX Hackathon - April 14, 2026

---

## 📜 License

MIT License - Feel free to use and modify for learning purposes.

---

## 🤝 Contributing

Suggestions and improvements welcome! Feel free to open issues or submit PRs.


