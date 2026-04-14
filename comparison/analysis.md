# Classical vs Quantum: Subset Sum Problem

## How They Compare

### Algorithm Approach

#### Classical (Backtracking)
```
Problem: Find subsets that add up to target

Method:
├── Start with empty set
├── For each number:
│   ├── Try including it
│   └── Try excluding it
├── Check if sum matches target
├── Stop if sum gets too big (optimization)
└── Go back and try other combinations

Result: Finds all correct subsets one by one
```

#### Quantum (Superposition + Amplitude Amplification)
```
Problem: Find subsets that add up to target

Method:
├── Use n qubits (one per number)
├── Put all qubits in superposition (Hadamard gates)
│   └── All 2^n subsets exist at the same time
├── Mark correct subsets with phase change
├── Boost probability of correct subsets
├── Measure qubits
│   └── High chance of getting right answer
└── Repeat to find more solutions

Result: Correct subsets show up more often when measured
```

---

### Time Complexity

| Thing | Classical | Quantum |
|-------|-----------|---------|
| **Method** | Check one by one | Superposition + boosting |
| **Time** | O(2^n) | O(√(2^n)) = O(2^(n/2)) |
| **Operations** | Direct checking | Amplitude boosting |
| **n=5** | 32 | ~6 |
| **n=10** | 1,024 | ~32 |
| **n=20** | 1,048,576 | ~1,024 |
| **n=30** | 1 billion+ | ~32,768 |
| **n=50** | 10^15 | 33 million |

**Speedup:** 2^(n/2) = √(2^n)
- n=10: 32x faster
- n=30: 32,768x faster
- n=50: 33 million times faster (huge!)

---

### Space Complexity

| Part | Classical | Quantum |
|------|-----------|---------|
| **Recursion** | O(n) | N/A |
| **Qubit memory** | N/A | O(n) qubits |
| **Classical bits** | O(n) | O(n) for measurement |
| **Total** | O(n) | O(n) |

**Bottom line:** Both use about the same space, but quantum uses it differently.

---

### How They Run

### Classical (Sequential)
```
Time goes by...

Check {5}        - sum=5     (no)
Check {10}       - sum=10    (no)
Check {5,10}     - sum=15    (no)
Check {12}       - sum=12    (no)
Check {5,12}     - sum=17    (no)
Check {10,12}    - sum=22    (no)
Check {5,10,12}  - sum=27    (no)
Check {13}       - sum=13    (no)
...
Check {5,10,15}  - sum=30    (YES!)

Total: 64 subsets checked one after another
```

### Quantum (Parallel)
```
Time goes by...

Start: All 64 subsets in superposition |Ψ⟩

|000⟩ {none}      ← equal weight
|001⟩ {18}        ← equal weight
|010⟩ {15}        ← equal weight
|011⟩ {15,18}     ← equal weight
|100⟩ {13}        ← equal weight
|101⟩ {13,18}     ← equal weight
|110⟩ {13,15}     ← equal weight
|111⟩ {13,15,18}  ← equal weight
...

After Oracle + Amplitude Amplification:
|011101⟩ {5,10,15} ← WEIGHT INCREASED! (90%+ probability)
|110010⟩ {12,18}   ← WEIGHT INCREASED! (90%+ probability)
...

Measure → Get correct solution with high probability!
```

---

### Type of Parallelism

#### Classical
```
Problem: Must be done step by step
Method: Backtracking checks one branch at a time
Parallel: Can use multiple threads but limited
Scalability: Limited by number of CPU cores
```

#### Quantum
```
Problem: Can be done all at once
Method: Superposition holds all possibilities together
Parallel: Built-in through quantum states
Scalability: Grows exponentially with qubits
Limitation: Must measure to get results (random)
```

---

### Measurement & Output

### Classical Output
```
Classical Approach Output:
Set: {5, 10, 12, 13, 15, 18}
Target: 30

Valid Subsets Found:
1. {5, 10, 15} → Sum = 30
2. {12, 18} → Sum = 30

Total: 2 solutions found
Verification: 100% accurate
```

### Quantum Output
```
Quantum Approach Output:
Set: {5, 10, 12, 13, 15, 18}
Target: 30
Shots: 1024

Measurement Results:
State      Subset          Sum   Count  Probability
|011101⟩   {5,10,15}      30    950    92.8%
|110010⟩   {12,18}        30    974    95.1%
|000000⟩   {}             0     2      0.2%
|001000⟩   {18}           18    1      0.1%
...

Probability of getting correct answer: ~93-95%
(Multiple measurements improve accuracy)
```

---

### Practical Considerations

| Factor | Classical | Quantum |
|--------|-----------|---------|
| **Implementation** | Easy | Hard (needs quantum hardware) |
| **Debugging** | Straightforward | Complex (probabilistic) |
| **Current Hardware** | Available everywhere | Limited quantum computers |
| **Error Rate** | Very low | High (current quantum errors) |
| **Scalability** | Limited (~20-30 elements) | Theoretically unlimited |
| **Cost** | Cheap | Very expensive |
| **Learning Curve** | Familiar | Steep (needs quantum knowledge) |

---

### When to Use Each Approach

### Use Classical Backtracking When:
✓ n ≤ 20-25 (can solve in reasonable time)
✓ Need exact solutions
✓ Can't tolerate any errors
✓ Have limited budget
✓ Want easy implementation
✓ Current state-of-the-art for small problems

### Use Quantum Approach When:
✓ n > 30 (classical becomes too slow)
✓ Have access to quantum hardware
✓ Can accept some errors
✓ Want to show theoretical speedup
✓ Part of a bigger quantum algorithm
✓ Planning for future larger problems

---

### Real-World Impact

#### Cryptography Example
```
Background:
- Some encryption uses subset sum as the hard problem
- Classical computers can break up to n=60-70
- Quantum could theoretically handle n=1000+ easily

Result:
- Current encrypted data might not be safe
- Need new quantum-resistant encryption
```

#### Optimization Example
```
Portfolio Selection Problem:
Pick stocks with total return = ₹1 Crore

Classical: Check all 2^n combinations
- n=30 stocks → 1 billion checks (takes hours)
- n=50 stocks → impossible to do

Quantum: Potential solution
- Same problem in √(2^n) time
- Could make it practical for real use
```

---

### Limitations & Reality Check

#### Classical Limitations
- ✗ Only practical for n ≤ 20-25
- ✗ Time grows exponentially

#### Quantum Limitations (Current & Near-term)
- ✗ Current quantum computers have noise/errors
- ✗ Limited number of stable qubits
- ✗ Qubits lose information over time
- ✗ Quantum advantage not proven for real problems yet
- ✓ But theoretically, huge potential!

---

### Theoretical Speedup Summary

```
Problem Size (n)  | Classical Time | Quantum Time | Speedup
─────────────────────────────────────────────────────────
5                 | 32 ops        | 5.6 ops      | 5.7x
10                | 1K ops        | 32 ops       | 32x
15                | 32K ops        | 181 ops      | 181x
20                | 1M ops        | 1K ops       | 1,024x
25                | 33M ops       | 5.6K ops     | 5,898x
30                | 1B ops        | 32K ops      | 32,768x
50                | 10^15 ops     | 33M ops      | 30,000,000x

Key: Speedup = √(2^n) = 2^(n/2)
```

---

### Conclusion

#### For Current Era (2026)
```
✓ Classical Backtracking:
  - Works for small-medium problems
  - 100% accurate
  - Easy to implement

✓ Quantum Approach:
  - Clear theoretical advantage
  - Hybrid classical-quantum looks promising
  - Needs better hardware first
```

#### Why This Project Matters
```
This project connects:
1. Classical algorithms (what we know now)
2. Quantum computing concepts (future tech)
3. Real applications (cryptography, optimization)

Judges will see you understand:
- How complexity works
- Quantum vs classical thinking
- Future technology trends
- Problem-solving mindset
```

---

## Key Takeaway

**"Classical computing checks one combination at a time, quantum computing holds all possibilities together—and boosts the right ones to make them show up more often."**

This is how quantum could change hard optimization problems.

